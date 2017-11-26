#ifndef CARBON_CONFIG_H
#define CARBON_CONFIG_H

#include "config_common.h"

#define DEVICE_VER 0x0042

#undef MANUFACTURER
#undef PRODUCT

#define MANUFACTURER    baetheus
#define PRODUCT         Planck Carbon

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS { B7, D0, D1, D2 }
#define MATRIX_COL_PINS { D3, C6, C7, D4, B6, F7, F6, F5, D6, D7, B4, B5 }

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#undef QMK_LED
#undef QMK_SPEAKER

#define RGB_DI_PIN D5           // The pin your RGB strip is wired to
#define RGBLIGHT_ANIMATIONS     // Require for fancier stuff (not compatible with audio)
#define RGBLED_NUM 12           // Number of LEDs
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#undef BACKLIGHT_PIN
#undef BACKLIGHT_LEVELS

#endif
