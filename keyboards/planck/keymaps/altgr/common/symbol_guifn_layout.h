
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ..................................................... Symbol Navigation Layer
#ifdef SHIFT_SYMBOLS
  // .-----------------------------------------------------------------------------------.
  // |      |   ~  |   *  |   &  |      |      |      |      | Home |  Up  |  End | PgUp |
  // |-----------------------------------------------------------------------------------|
  // |  GUI |   ^  |   %  |   $  |      |      |      |      | Left | Down | Right| PgDn |
  // |-----------------------------------------------------------------------------------|
  // |      |   #  |   @  |   !  |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |Adjust|   \  |      |  f() |                           |
  // '-----------------------------------------------------------------------------------'

  [_SYMBOL] = {
    {_______, KC_TILD, KC_ASTR, KC_AMPR, _______, ___x___, ___x___, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP},
    {OS_GUI,  SM_CIRC, SM_PERC, SM_DLR,  _______, ___x___, ___x___, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN},
    {_______, KC_HASH, KC_AT,   KC_EXLM, _______, ___x___, ___x___, _______, _______, _______, _______, _______},
    {___x___, ___x___, ___x___, ADJUST,  LT_BSLS, ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___},
  },
#else
  // .-----------------------------------------------------------------------------------.
  // |   {  |   .  |   *  |   &  |   }  |      |      |      | Home |  Up  |  End | PgUp |
  // |-----------------------------------------------------------------------------------|
  // |   (  |   ^  |   %  |   $  |   )  |      |      |      | Left | Down | Right| PgDn |
  // |-----------------------------------------------------------------------------------|
  // |   [  |   #  |   @  |   !  |   ]  |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |   |  |   \  |      |  f() |                           |
  // '-----------------------------------------------------------------------------------'

  [_SYMBOL] = {
    {KC_LCBR, KC_DOT,  KC_ASTR, KC_AMPR, TD_RCBR, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP},
    {SM_LPRN, SM_CIRC, SM_PERC, SM_DLR,  TD_RPRN, _______, _______, _______, LT_LFTX, KC_DOWN, KC_RGHT, KC_PGDN},
    {KC_LBRC, KC_HASH, KC_AT,   KC_EXLM, TD_RBRC, _______, _______, _______, _______, _______, _______, _______},
    {___x___, ___x___, ___x___, SL_PIPE, LT_BSLS, ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___},
  },

  // .-----------------------------------------------------------------------------------.
  // |      |   ?  |   +  |   ~  |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |      |   <  |   =  |   >  |      |      |      |      |  f() |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |      |   3  |   2  |   1  |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |      |      |      |  f() |                           |
  // '-----------------------------------------------------------------------------------'

  [_SYMREG] = {
    {___x___, KC_QUES, KC_PLUS, KC_TILD, ___x___, _______, _______, _______, ___x___, ___x___, ___x___, ___x___},
    {___x___, KC_LT,   KC_EQL,  TD_RNGL, ___x___, _______, _______, _______, ___fn__, ___x___, ___x___, ___x___},
    {___x___, KC_3,    KC_2,    KC_1,    ___x___, _______, _______, _______, _______, _______, _______, _______},
    {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___},
  },
#endif

// ............................................................... Mouse Actions

  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      | Left |  Up  | Right|  Up  |
  // |-----------------------------------------------------------------------------------|
  // |      | Btn3 | Btn2 | Btn1 |      |      |      |      | Left | Down | Right| Down |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |                           |      |  f() |      |  f() |                           |
  // '-----------------------------------------------------------------------------------'

  [_MOUSE] = {
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U},
    {_______, KC_BTN3, KC_BTN2, KC_BTN1, _______, ___x___, ___x___, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D},
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, ___fn__, _______, _______, _______, ___fn__, _______, _______, _______},
  },
