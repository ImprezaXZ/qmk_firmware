#pragma once
#define PRODUCT fc980hw Teensy 3.2
#define I2C1_SCL 0 // A2 on pinout = B0
#define I2C1_SDA 1 // A3 on pinout = B1
#define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2


//#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0980
#define DEVICE_VER      0x0001
#define MANUFACTURER    purple
#define DESCRIPTION     handwire

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 19

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, D7, A13, A12, D0, B17 }
#define MATRIX_COL_PINS { D2, D3, C3, C4, C6, C7, C10, D1, C0, B0, B1, B3, B2, D5, D6, C1, C2, A5, B19 }
#define UNUSED_PINS
#define UNUSED_PINS


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#undef DEBOUNCE
#define DEBOUNCE 20

#define IGNORE_MOD_TAP_INTERRUPT

// Reduce input latency by lowering the USB polling interval
// from its 10ms default to the 125μs minimum that USB 2.x (High Speed) allows: #define USB_POLLING_INTERVAL_MS 1

// The Teensy 4.1 consumes about 100 mA of current at its full speed of 600 MHz
// as per https://www.pjrc.com/store/teensy41.html
#define USB_MAX_POWER_CONSUMPTION 100

/* We use the i.MX RT1060 high-speed GPIOs (GPIO6-9) which are connected to the
 * AHB bus (AHB_CLK_ROOT), which runs at the same speed as the ARM Core Clock,
 * i.e. 600 MHz. See MIMXRT1062, page 949, 12.1 Chip-specific GPIO information.
 * No additional delay is necessary. */

// in clock cycles
#define GPIO_INPUT_PIN_DELAY 0

#define DYNAMIC_KEYMAP_LAYER_COUNT 4
