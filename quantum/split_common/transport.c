/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>

#include "transactions.h"
#include "transport.h"
#include "transaction_id_define.h"

#ifdef USE_I2C

#    ifndef SLAVE_I2C_TIMEOUT
#        define SLAVE_I2C_TIMEOUT 100
#    endif  // SLAVE_I2C_TIMEOUT

#    ifndef SLAVE_I2C_ADDRESS
#        define SLAVE_I2C_ADDRESS 0x32
#    endif

#    include "i2c_master.h"
#    include "i2c_slave.h"
// Ensure the I2C buffer has enough space
_Static_assert(sizeof(split_shared_memory_t) <= I2C_SLAVE_QMK_REG_COUNT, "split_shared_memory_t too large for I2C_SLAVE_QMK_REG_COUNT");

split_shared_memory_t *const split_shmem = (split_shared_memory_t *)i2c_slave_reg;

void transport_master_init(void) { i2c_init(); }
void transport_slave_init(void) { i2c_slave_init(SLAVE_I2C_ADDRESS); }

bool transport_execute_transaction(int8_t id, const void *initiator2target_buf, uint16_t initiator2target_length, void *target2initiator_buf, uint16_t target2initiator_length) {
    bool                      okay  = true;
    split_transaction_desc_t *trans = &split_transaction_table[id];
    if (initiator2target_length > 0) {
        size_t len = trans->initiator2target_buffer_size < initiator2target_length ? trans->initiator2target_buffer_size : initiator2target_length;
        memcpy(split_trans_initiator2target_buffer(trans), initiator2target_buf, len);
        okay &= (i2c_writeReg(SLAVE_I2C_ADDRESS, trans->initiator2target_offset, split_trans_initiator2target_buffer(trans), len, SLAVE_I2C_TIMEOUT) >= 0);
    }

    if (okay && target2initiator_length > 0) {
        size_t len = trans->target2initiator_buffer_size < target2initiator_length ? trans->target2initiator_buffer_size : target2initiator_length;
        okay &= (i2c_readReg(SLAVE_I2C_ADDRESS, trans->target2initiator_offset, split_trans_target2initiator_buffer(trans), len, SLAVE_I2C_TIMEOUT) >= 0);
        if (okay) {
            memcpy(target2initiator_buf, split_trans_target2initiator_buffer(trans), len);
        }
    }

    return okay;
}

#else  // USE_I2C

#    include "serial.h"

static split_shared_memory_t shared_memory;
split_shared_memory_t *const split_shmem = &shared_memory;

void transport_master_init(void) { soft_serial_initiator_init(); }
void transport_slave_init(void) { soft_serial_target_init(); }

bool transport_execute_transaction(int8_t id, const void *initiator2target_buf, uint16_t initiator2target_length, void *target2initiator_buf, uint16_t target2initiator_length) {
    split_transaction_desc_t *trans = &split_transaction_table[id];
    if (initiator2target_length > 0) {
        size_t len = trans->initiator2target_buffer_size < initiator2target_length ? trans->initiator2target_buffer_size : initiator2target_length;
        memcpy(split_trans_initiator2target_buffer(trans), initiator2target_buf, len);
    }

    if (soft_serial_transaction(id) != TRANSACTION_END) {
        return false;
    }

    if (target2initiator_length > 0) {
        size_t len = trans->target2initiator_buffer_size < target2initiator_length ? trans->target2initiator_buffer_size : target2initiator_length;
        memcpy(target2initiator_buf, split_trans_target2initiator_buffer(trans), len);
    }

    return true;
}

#endif  // USE_I2C

bool transport_master(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]) {
    return transactions_master(master_matrix, slave_matrix);
}

void transport_slave(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]) {
    transactions_slave(master_matrix, slave_matrix);
}