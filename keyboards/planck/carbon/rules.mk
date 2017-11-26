# Boot Section Size in *bytes*
#   Teensy halfKay   512
#   Teensy++ halfKay 1024
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
#   USBaspLoader     2048
OPT_DEFS += -DBOOTLOADER_SIZE=512

AUDIO_ENABLE = no           # Audio output on port C6

MIDI_ENABLE = yes            # MIDI controls
UNICODE_ENABLE = yes         # Unicode
#MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
