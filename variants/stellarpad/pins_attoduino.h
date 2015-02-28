/*
 pins_attoduino.h - pin definition for attoduino
 Copyright (c) 2015 Jonathan Drisoll
 
 Derived from:
 pins_energia.h
 Energia core files for LM4F
 Copyright (c) 2012 Robert Wessels. All right reserved.
 Contribution: Rei VILO
 
 Derived from:
 pins_arduino.h - Pin definition functions for Arduino
 Part of Arduino - http://www.arduino.cc/
 Copyright (c) 2007 David A. Mellis
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General
 Public License along with this library; if not, write to the
 Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 Boston, MA  02111-1307  USA
*/

#ifndef pins_attoduino_h
#define pins_attoduino_h

#define __LM4F120H5QR__
#define __TM4C123GH6PM__

#ifndef BV
#define BV(x) (1 << (x))
#endif
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"

// pins and ports changed for attoduino
// attoduino pin definition begin
static const uint8_t PE_0 = 0;     /* PE0 */
static const uint8_t PE_1 = 1;     /* PE1 */
static const uint8_t PE_2 = 2;     /* PE2 */
static const uint8_t PE_3 = 3;     /* PE3 */
static const uint8_t PD_3 = 4;     /* PD3 */
static const uint8_t PD_2 = 5;     /* PD2 */
static const uint8_t PD_1 = 6;     /* PD1 */
static const uint8_t PD_0 = 7;     /* PD0 */
static const uint8_t PE_5 = 8;     /* PE5 */
static const uint8_t PE_4 = 9;     /* PE4 */
static const uint8_t PB_4 = 10;    /* PB4 */
static const uint8_t PD_5 = 11;    /* PD5 */
static const uint8_t PB_0 = 12;    /* PB0 */
static const uint8_t PB_1 = 13;    /* PB1 */
static const uint8_t PB_2 = 14;    /* PB2 */
static const uint8_t PB_3 = 15;    /* PB3 */
static const uint8_t PB_6 = 16;    /* PB6 */
static const uint8_t PB_7 = 17;    /* PB7 */
static const uint8_t PF_4 = 18;    /* (pushbutton) */
static const uint8_t PD_7 = 19;    /* PB7 */
static const uint8_t PC_7 = 20;    /* PC7 */
static const uint8_t PC_6 = 21;    /* LED_RED */
static const uint8_t PC_5 = 22;    /* LED_GREEN */
static const uint8_t PC_4 = 23;    /* LED_BLUE */
static const uint8_t PA_0 = 24;    /* RX0 */
static const uint8_t PA_1 = 25;    /* TX0 */
static const uint8_t PA_2 = 26;    /* PA2 */
static const uint8_t PD_6 = 27;    /* battery_read_enable */
static const uint8_t PB_5 = 28;    /* half_battery */
static const uint8_t PA_6 = 29;    /* bt_control */
static const uint8_t PA_7 = 30;    /* bt_reset */
// attoduino pin definition end

// changed for attoduino
// note, the first 4 pins are reversed, for layout reasons ...
static const uint8_t A0 =  0;
static const uint8_t A1 =  1;
static const uint8_t A2 =  2;
static const uint8_t A3 =  3;
static const uint8_t A4 =  4;
static const uint8_t A5 =  5;
static const uint8_t A6 =  6;
static const uint8_t A7 =  7;
static const uint8_t A8 =  8;
static const uint8_t A9 =  9;
static const uint8_t A10 = 10;
static const uint8_t A11 = 28; // half battery read

static const uint8_t RED_LED =   21;
static const uint8_t GREEN_LED = 22;
static const uint8_t BLUE_LED =  23;

static const uint8_t PIN_LED_RED = 21;
static const uint8_t PIN_LED_GREEN = 22;
static const uint8_t PIN_LED_BLUE = 23;

// for reading the battery
static const uint8_t PIN_BATTERY_READ_ENABLE = 27;
static const uint8_t PIN_HALF_BATTERY = 28;

// for dealing with bluetooth
static const uint8_t PIN_BT_CONTROL = 29;
static const uint8_t PIN_BT_RESET = 30;

//static const uint8_t PUSH1 = 31;
//static const uint8_t PUSH2 = 17;
//static const uint8_t TEMPSENSOR = 0;

#ifdef ARDUINO_MAIN

// does not need modification for attoduino?
const uint32_t port_to_base[] = {
  NOT_A_PORT,
  (uint32_t) GPIO_PORTA_BASE,
  (uint32_t) GPIO_PORTB_BASE,
  (uint32_t) GPIO_PORTC_BASE,
  (uint32_t) GPIO_PORTD_BASE,
  (uint32_t) GPIO_PORTE_BASE,
  (uint32_t) GPIO_PORTF_BASE
};

// changed for attoduino
const uint8_t digital_pin_to_timer[] = {
  NOT_ON_TIMER, /* 0 */
  NOT_ON_TIMER, /* 1 */
  NOT_ON_TIMER, /* 2 */
  NOT_ON_TIMER, /* 3 */
  WT3B, /* 4 PD_3 */
  WT3A, /* 5 PD_2 */
  WT2B, /* 6 PD_1 */
  WT2A, /* 7 PD_0) */
  NOT_ON_TIMER, /* 8 */
  NOT_ON_TIMER, /* 9 */
  NOT_ON_TIMER, /* 10 */
  NOT_ON_TIMER, /* 11 */
  T2A0, /* 12 PB_0 */
  T2B,  /* 13 PB_1 */
  T3A,  /* 14 PB_2 */
  T3B,  /* 15 PB_3 */
  T0A0, /* 16 PB_6 */
  T0B0, /* 17 PB_7 */
  T2A1, /* 18 PF_4 */
  WT5B, /* 19 PD_7 */
  WT1B, /* 20 PC_7 */
  WT1A, /* 21 PC_6 */
  WT0B, /* 22 PC_5 */
  WT0A, /* 23 PC_4 */
  NOT_ON_TIMER, /* 24 */
  NOT_ON_TIMER, /* 25 */
  NOT_ON_TIMER, /* 26 PA_2 ... may actually be a timer for this ... */
  NOT_ON_TIMER, /* 27 */
  NOT_ON_TIMER, /* 28 */
  NOT_ON_TIMER, /* 29 */
  NOT_ON_TIMER  /* 30 */
};

// changed for attoduino
const uint8_t digital_pin_to_port[]       = {
  PE,     // 00 - PE_0       PE0
  PE,     // 01 - PE_1       PE1
  PE,     // 02 - PE_2       PE2
  PE,     // 03 - PE_3       PE3
  PD,     // 04 - PD_3       PD3
  PD,     // 05 - PD_2       PD2
  PD,     // 06 - PD_1       PD1
  PD,     // 07 - PD_0       PD0
  PE,     // 08 - PE_5       PE5
  PE,     // 09 - PE_4       PE4
  PB,     // 10 - PB_4       PB4
  PD,     // 11 - PD_5       PD5
  PB,     // 12 - PB_0       PB0
  PB,     // 13 - PB_1       PB1
  PB,     // 14 - PB_2       PB2
  PB,     // 15 - PB_3       PB3
  PB,     // 16 - PB_6       PB6
  PB,     // 17 - PB_7       PB7
  PF,     // 18 - PF_4       (pushbutton)
  PD,     // 19 - PD_7       PB7
  PC,     // 20 - PC_7       PC7
  PC,     // 21 - PC_6       LED_RED
  PC,     // 22 - PC_5       LED_GREEN
  PC,     // 23 - PC_4       LED_BLUE
  PA,     // 24 - PA_0       RX0
  PA,     // 25 - PA_1       TX0
  PA,     // 26 - PA_2       PA2
  PD,     // 27 - PD_6       battery_read_enable
  PB,     // 28 - PB_5       half_battery
  PA,     // 29 - PA_6       bt_control
  PA,     // 30 - PA_7       bt_reset
};


// changed for attoduino
const uint8_t digital_pin_to_bit_mask[]   = {
  BV(0),          // 00 - PE_0       PE0
  BV(1),          // 01 - PE_1       PE1
  BV(2),          // 02 - PE_2       PE2
  BV(3),          // 03 - PE_3       PE3
  BV(3),          // 04 - PD_3       PD3
  BV(2),          // 05 - PD_2       PD2
  BV(1),          // 06 - PD_1       PD1
  BV(0),          // 07 - PD_0       PD0
  BV(5),          // 08 - PE_5       PE5
  BV(4),          // 09 - PE_4       PE4
  BV(4),          // 10 - PB_4       PB4
  BV(5),          // 11 - PD_5       PD5
  BV(0),          // 12 - PB_0       PB0
  BV(1),          // 13 - PB_1       PB1
  BV(2),          // 14 - PB_2       PB2
  BV(3),          // 15 - PB_3       PB3
  BV(6),          // 16 - PB_6       PB6
  BV(7),          // 17 - PB_7       PB7
  BV(4),          // 18 - PF_4       (pushbutton)
  BV(7),          // 19 - PD_7       PB7
  BV(7),          // 20 - PC_7       PC7
  BV(6),          // 21 - PC_6       LED_RED
  BV(5),          // 22 - PC_5       LED_GREEN
  BV(4),          // 23 - PC_4       LED_BLUE
  BV(0),          // 24 - PA_0       RX0
  BV(1),          // 25 - PA_1       TX0
  BV(2),          // 26 - PA_2       PA2
  BV(6),          // 27 - PD_6       battery_read_enable
  BV(5),          // 28 - PB_5       half_battery
  BV(6),          // 29 - PA_6       bt_control
  BV(7),          // 30 - PA_7       bt_reset
};

const uint32_t timer_to_offset[] = {
  TIMER0,
  TIMER0,
  TIMER0,
  TIMER0,
  TIMER1,
  TIMER1,
  TIMER1,
  TIMER1,
  TIMER2,
  TIMER2,
  TIMER2,
  TIMER3,
  TIMER3,
  WTIMER0,
  WTIMER0,
  WTIMER1,
  WTIMER1,
  WTIMER2,
  WTIMER2,
  WTIMER3,
  WTIMER3,
  WTIMER5,
  WTIMER5,
};

const uint8_t timer_to_ab[] = {
  TIMA,
  TIMA,
  TIMB,
  TIMB,
  TIMA,
  TIMA,
  TIMB,
  TIMB,
  TIMA,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
  TIMA,
  TIMB,
};

const uint32_t timer_to_pin_config[] = {
  GPIO_PB6_T0CCP0,
  GPIO_PF0_T0CCP0,
  GPIO_PB7_T0CCP1,
  GPIO_PF1_T0CCP1,
  GPIO_PB4_T1CCP0,
  GPIO_PF2_T1CCP0,
  GPIO_PB5_T1CCP1,
  GPIO_PF3_T1CCP1,
  GPIO_PB0_T2CCP0,
  GPIO_PF4_T2CCP0,
  GPIO_PB1_T2CCP1,
  GPIO_PB2_T3CCP0,
  GPIO_PB3_T3CCP1,
  GPIO_PC4_WT0CCP0,
  GPIO_PC5_WT0CCP1,
  GPIO_PC6_WT1CCP0,
  GPIO_PC7_WT1CCP1,
  GPIO_PD0_WT2CCP0,
  GPIO_PD1_WT2CCP1,
  GPIO_PD2_WT3CCP0,
  GPIO_PD3_WT3CCP1,
  GPIO_PD6_WT5CCP0,
  GPIO_PD7_WT5CCP1,
};

// changed for attoduino
// note, first four are reversed, for layout reasons ...
// this makes pin 0 match with A0
const uint32_t digital_pin_to_analog_in[] = {
  ADC_CTL_CH3,     // 00 - PE_0       PE0
  ADC_CTL_CH2,     // 01 - PE_1       PE1
  ADC_CTL_CH1,     // 02 - PE_2       PE2
  ADC_CTL_CH0,     // 03 - PE_3       PE3
  ADC_CTL_CH4,     // 04 - PD_3       PD3
  ADC_CTL_CH5,     // 05 - PD_2       PD2
  ADC_CTL_CH6,     // 06 - PD_1       PD1
  ADC_CTL_CH7,     // 07 - PD_0       PD0
  ADC_CTL_CH8,     // 08 - PE_5       PE5
  ADC_CTL_CH9,     // 09 - PE_4       PE4
  ADC_CTL_CH10,    // 10 - PB_4       PB4
  NOT_ON_ADC,     // 11 - PD_5       PD5
  NOT_ON_ADC,     // 12 - PB_0       PB0
  NOT_ON_ADC,     // 13 - PB_1       PB1
  NOT_ON_ADC,     // 14 - PB_2       PB2
  NOT_ON_ADC,     // 15 - PB_3       PB3
  NOT_ON_ADC,     // 16 - PB_6       PB6
  NOT_ON_ADC,     // 17 - PB_7       PB7
  NOT_ON_ADC,     // 18 - PF_4       (pushbutton)
  NOT_ON_ADC,     // 19 - PD_7       PB7
  NOT_ON_ADC,     // 20 - PC_7       PC7
  NOT_ON_ADC,     // 21 - PC_6       LED_RED
  NOT_ON_ADC,     // 22 - PC_5       LED_GREEN
  NOT_ON_ADC,     // 23 - PC_4       LED_BLUE
  NOT_ON_ADC,     // 24 - PA_0       RX0
  NOT_ON_ADC,     // 25 - PA_1       TX0
  NOT_ON_ADC,     // 26 - PA_2       PA2
  NOT_ON_ADC,     // 27 - PD_6       battery_read_enable
  ADC_CTL_CH11,   // 28 - PB_5       half_battery
  NOT_ON_ADC,     // 29 - PA_6       bt_control
  NOT_ON_ADC,     // 30 - PA_7       bt_reset
};

#endif
#endif
