/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Conditionals_adv.h
 * Defines that depend on advanced configuration.
 */

#define HAS_CUTTER EITHER(SPINDLE_FEATURE, LASER_FEATURE)

#if !defined(__AVR__) || !defined(USBCON)
  // Define constants and variables for buffering serial data.
  // Use only 0 or powers of 2 greater than 1
  // : [0, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, ...]
  #ifndef RX_BUFFER_SIZE
    #define RX_BUFFER_SIZE 128
  #endif
  // 256 is the max TX buffer limit due to uint8_t head and tail
  // : [0, 4, 8, 16, 32, 64, 128, 256]
  #ifndef TX_BUFFER_SIZE
    #define TX_BUFFER_SIZE 32
  #endif
#else
  // SERIAL_XON_XOFF not supported on USB-native devices
  #undef SERIAL_XON_XOFF
#endif

#if ENABLED(HOST_ACTION_COMMANDS)
  #ifndef ACTION_ON_PAUSE
    #define ACTION_ON_PAUSE   "pause"
  #endif
  #ifndef ACTION_ON_PAUSED
    #define ACTION_ON_PAUSED  "paused"
  #endif
  #ifndef ACTION_ON_RESUME
    #define ACTION_ON_RESUME  "resume"
  #endif
  #ifndef ACTION_ON_RESUMED
    #define ACTION_ON_RESUMED "resumed"
  #endif
  #ifndef ACTION_ON_CANCEL
    #define ACTION_ON_CANCEL  "cancel"
  #endif
  #ifndef ACTION_ON_KILL
    #define ACTION_ON_KILL    "poweroff"
  #endif
  #if HAS_FILAMENT_SENSOR
    #ifndef ACTION_ON_FILAMENT_RUNOUT
      #define ACTION_ON_FILAMENT_RUNOUT "filament_runout"
    #endif
    #ifndef ACTION_REASON_ON_FILAMENT_RUNOUT
      #define ACTION_REASON_ON_FILAMENT_RUNOUT "filament_runout"
    #endif
  #endif
  #if ENABLED(G29_RETRY_AND_RECOVER)
    #ifndef ACTION_ON_G29_RECOVER
      #define ACTION_ON_G29_RECOVER "probe_rewipe"
    #endif
    #ifndef ACTION_ON_G29_FAILURE
      #define ACTION_ON_G29_FAILURE "probe_failed"
    #endif
  #endif
#endif

#if ENABLED(FYSETC_MINI_12864_2_1)
  #define LED_CONTROL_MENU
  #define LED_USER_PRESET_STARTUP
  #define LED_COLOR_PRESETS
  #ifndef LED_USER_PRESET_RED
    #define LED_USER_PRESET_RED        0
  #endif
  #ifndef LED_USER_PRESET_GREEN
    #define LED_USER_PRESET_GREEN      0
  #endif
  #ifndef LED_USER_PRESET_BLUE
    #define LED_USER_PRESET_BLUE         255
  #endif
  #ifndef LED_USER_PRESET_BRIGHTNESS
    #define LED_USER_PRESET_BRIGHTNESS 255
  #endif
#endif

// Extensible UI pin mapping for RepRapDiscount
#define TOUCH_UI_ULTIPANEL ENABLED(LULZBOT_TOUCH_UI) && ANY(AO_EXP1_PINMAP, AO_EXP2_PINMAP, CR10_TFT_PINMAP)
