/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/**
 * Geeetech GT2560 Revision A board pin assignments, based on the work of
 * George Robles (https://georges3dprinters.com) and
 * Richard Smith <galorin@gmail.com>
 */

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "GT2560 Rev.A"
#endif
#define DEFAULT_MACHINE_NAME "Prusa i3 Pro B"

//
// Limit Switches
//
#define X_MIN_PIN          22
// #define X_MAX_PIN          24//to mbe used for x CS pin
#define Y_MIN_PIN          26
//#define Y_MAX_PIN          28 //to be used for y CS pin
#define Z_MIN_PIN          30
//#define Z_MAX_PIN          32 //to be used for E0 probe pin

// Pins need to be redefined for TMC2130 drivers
//SDcard connector layout: (the dots represent the gap in the connector socket on the board)
//.... 
//0 1 2 3 4
//5 6 7 8 9

//0= Physical pin 20 on the atmega (Digital pin 52 or SCK/PCINT1) 
//1= Physical pin 19 on the atmega (Digital pin 53 or SS/PCINT0) 
//2= Physical pin 21 on the atmega (Digital pin 51 or MOSI/PCINT2)
//3= Physical pin 30 on the atmega (reset!)
//4= (5V+? not measured but assumed)
//9= GND
//8= Physical pin 50 on the atmega (Digital pin 38)
//7= Physical pin 52 on the atmega (Digital pin 40)
//6= Physical pin 43 on the atmega (Digital pin 21 /SCL int0)
//5= Physical pin 22 on the atmega (Digital pin 50 MISO/PCINT3)

//How to wire up your TMC2130 driver boards....

// note example on geetech forum had pins 5 and 2 swapped i have changed to match tinkihead info
//Connect SDsocket pin 0 (SCK) to the SCK pins of all TMC2130 stepper driver boards
//Connect SDsocket pin 5 (MOSI) to the SCO pins of all TMC2130 stepper driver boards
//Connect SDsocket pin 2 (MISO) to the SCI pins of all TMC2130 stepper driver boards 

//From tinkihead post
//SDO -> MISO
//SDI -> MOSI
//CS -> digital pins
//SCK -> SCK

// TMC2130 setup

#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI    51
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO    50
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK     52
  #endif
#endif


#define X_CS_PIN 24 //x max
//#define Y_CS_PIN 28 //y max
// #define Z_CS_PIN 28 //Z max
#define E0_CS_PIN 28 // on utlise celui du Y au lieu du 32 //Z max

//
// Steppers
//
#define X_STEP_PIN         25
#define X_DIR_PIN          23
#define X_ENABLE_PIN       27

#define Y_STEP_PIN         31
#define Y_DIR_PIN          33
#define Y_ENABLE_PIN       29

#define Z_STEP_PIN         37
#define Z_DIR_PIN          39
#define Z_ENABLE_PIN       35

#define E0_STEP_PIN        43
#define E0_DIR_PIN         45
#define E0_ENABLE_PIN      41

//#define E1_STEP_PIN        49
//#define E1_DIR_PIN         47
//#define E1_ENABLE_PIN      48

#define Z2_STEP_PIN         49
#define Z2_DIR_PIN          47
#define Z2_ENABLE_PIN       48

//
// Temperature Sensors
//
#define TEMP_0_PIN          8
#define TEMP_1_PIN          9
#define TEMP_BED_PIN       10

//
// Heaters / Fans
//
#define HEATER_0_PIN        2
//#define HEATER_1_PIN        3 // devient le pin du fan
#define HEATER_BED_PIN      4
#ifndef FAN_PIN
  //#define FAN_PIN           7
  #define FAN_PIN           3
#endif

//
// Misc. Functions
//
#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13
#define PS_ON_PIN          12
#define SUICIDE_PIN        54   // Must be enabled at startup to keep power flowing
#define KILL_PIN           -1



#if ENABLED(ULTRA_LCD)

  #define BEEPER_PIN       18

  #if ENABLED(NEWPANEL)

    #if ENABLED(MKS_MINI_12864)
      #define DOGLCD_A0     5
      #define DOGLCD_CS    21
      #define BTN_EN1      40
      #define BTN_EN2      42
    #else
      #define LCD_PINS_RS  20
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4  16
      #define LCD_PINS_D5  21
      #define LCD_PINS_D6   5
      #define LCD_PINS_D7   6
      #define BTN_EN1      42
      #define BTN_EN2      40
    #endif

    #define BTN_ENC        19
    #define SD_DETECT_PIN  38

  #else // !NEWPANEL

    #define SHIFT_CLK      38
    #define SHIFT_LD       42
    #define SHIFT_OUT      40
    #define SHIFT_EN       17

    #define LCD_PINS_RS    16
    #define LCD_PINS_ENABLE 5
    #define LCD_PINS_D4     6
    #define LCD_PINS_D5    21
    #define LCD_PINS_D6    20
    #define LCD_PINS_D7    19

    #define SD_DETECT_PIN  -1

  #endif // !NEWPANEL

#endif // ULTRA_LCD
