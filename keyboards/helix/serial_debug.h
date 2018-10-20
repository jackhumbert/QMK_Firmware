// debug flags
#define SERIAL_DEBUG_MODE_WATCH_OUTMODE 0x1
#define SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE 0x2
#define SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH 0x4
#define SERIAL_DEBUG_MODE_WATCH_SYNC 0x8
#define SERIAL_DEBUG_MODE_WATCH_IOCHG 0x10
#define SERIAL_DEBUG_MODE_WATCH_PARITY 0x20
#define SERIAL_DEBUG_MODE_WATCH_RETRY 0x40
#define SERIAL_DEBUG_MODE_WATCH_TIDERR 0x80
#define SERIAL_DEBUG_MODE_WATCH_TRANS 0x100

//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_OUTMODE
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_SYNC
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_SYNC)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_IOCHG
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_IOCHG|SERIAL_DEBUG_MODE_WATCH_SYNC)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_PARITY
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_RETRY
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_TIDERR)
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_TIDERR|SERIAL_DEBUG_MODE_WATCH_SYNC)
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_TRANS)

// Helix keyboard unused port (for Logic analyzer or oscilloscope)
#ifdef SERIAL_DEBUG_MODE
#define SERIAL_DBGPIN_DDR DDRB
#define SERIAL_DBGPIN_PORT PORTB
#define SERIAL_DBGPIN_MASK _BV(PB5)
#define SERIAL_DBGPIN_MASK2 _BV(PB6)
#endif

#ifdef SERIAL_DEBUG_MODE
 #define serial_debug_init() SERIAL_DBGPIN_DDR |= (SERIAL_DBGPIN_MASK|SERIAL_DBGPIN_MASK2)
#else
 #define serial_debug_init()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_OUTMODE
 #define debug_output_mode() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
 #define debug_input_mode()  SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
 #define debug_output_mode()
 #define debug_input_mode()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE
  #define debug_recvsample() SERIAL_DBGPIN_PORT ^= SERIAL_DBGPIN_MASK
#else
  #define debug_recvsample()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH
  #define debug_bytewidth_start()  SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_bytewidth_end()  SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_bytewidth_start()
  #define debug_bytewidth_end()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_SYNC
  #define debug_sync_start() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_sync_end() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_sync_start()
  #define debug_sync_end()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_IOCHG
  #define debug_iochg_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_iochg_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_iochg_on()
  #define debug_iochg_off()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_PARITY
  #define debug_parity_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_parity_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_parity_on()
  #define debug_parity_off()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_RETRY
  #define debug_retry_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_retry_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
  #define debug_retry_chg() SERIAL_DBGPIN_PORT ^= SERIAL_DBGPIN_MASK
#else
  #define debug_retry_on()
  #define debug_retry_off()
  #define debug_retry_chg()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_TIDERR
  #define debug_tid_error() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK2
  #define debug_tid_noerror() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK2
#else
  #define debug_tid_error()
  #define debug_tid_noerror()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_TRANS
  #define debug_trns_start() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK2
  #define debug_trns_end() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK2
#else
  #define debug_trns_start()
  #define debug_trns_end()
#endif

#define SYNC_DEBUG_MODE 0
#if SYNC_DEBUG_MODE == 0
#define debug_dummy_delay_recv()
#define debug_dummy_delay_send()
#endif
#if SYNC_DEBUG_MODE == 1
#define debug_dummy_delay_recv()  _delay_us(3); _delay_sub_us(2)
#define debug_dummy_delay_send()
#endif
#if SYNC_DEBUG_MODE == 2
#define debug_dummy_delay_recv()
#define debug_dummy_delay_send()  _delay_us(3); _delay_sub_us(2)
#endif

