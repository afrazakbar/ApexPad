#include QMK_KEYBOARD_H
enum layers {
    _BASE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LCTL(KC_C), LCTL(KC_X),
        LCTL(KC_V), LCTL(KC_Z), LCTL(LSFT(KC_Z))
    )
};
/* =========================
 * ENCODER
 * ========================= */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
/* =========================
 * OLED
 * ========================= */
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();
    oled_set_cursor(0, 0);
    oled_write("APEX PAD", false);
    oled_set_cursor(0, 2);
    oled_write("READY", false);
    return false;
}
#endif
