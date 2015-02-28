#ifndef atto_pin_map_h
#define atto_pin_map_h

// the first four pins get flipped the other direction
//static const uint8_t D0 =  29; //PE_3
//static const uint8_t D1 =  28; //PE_2
//static const uint8_t D2 =  27; //PE_1
//static const uint8_t D3 =  18; //PE_0

/*
static const uint8_t D0 =  18; //PE_0
static const uint8_t D1 =  27; //PE_1
static const uint8_t D2 =  28; //PE_2
static const uint8_t D3 =  29; //PE_3

static const uint8_t D4 =  26; //PD_3
static const uint8_t D5 =  25; //PD_2
static const uint8_t D6 =  24; //PD_1
static const uint8_t D7 =  23; //PD_0
static const uint8_t D8 =   6; //PE_5
static const uint8_t D9 =   5; //PE_4
static const uint8_t D10 =  7; //PB_4

// this is a dual use pin (hidden analog input pin ...)
//static const uint8_t D11 =  2; //PB_5

// these are also not defined in Energia ...
// could maybe just consider them flash pins?
static const uint8_t TCK = 0;
static const uint8_t TMS = 0;
static const uint8_t TMI = 0;
static const uint8_t TDO = 0;

//static const uint8_t D11 =     // not defined in Energia (from USB)
static const uint8_t D12 =  3; //PB0
static const uint8_t D13 =  4; //PB1
static const uint8_t D14 = 19; //PB2
static const uint8_t D15 = 38; //PB3
static const uint8_t D16 = 14; //PB6
static const uint8_t D17 = 15; //PB7
static const uint8_t D18 = 31; //PF4 // this is a button
static const uint8_t D19 = 32; //PD7

static const uint8_t D20 = 34; //PC7
static const uint8_t D21 = 35; //PC6
static const uint8_t D22 = 36; //PC5
static const uint8_t D23 = 37; //PC4

// these are the TX RX, don't need to mess with them ...
static const uint8_t D24 = 8;  //PA0
static const uint8_t D25 = 0; //PA1

static const uint8_t D26 = 0;
*/

/*
// this makes more sense, write the pin stuff explicitly ...
static const uint8_t D0 =  PE_0;
static const uint8_t D1 =  PE_1;
static const uint8_t D2 =  PE_2;
static const uint8_t D3 =  PE_3;

static const uint8_t D4 =  PD_3;
static const uint8_t D5 =  PD_2;
static const uint8_t D6 =  PD_1;
static const uint8_t D7 =  PD_0;
static const uint8_t D8 =  PE_5;
static const uint8_t D9 =  PE_4;
static const uint8_t D10 = PB_4;

// this is a dual use pin (hidden analog input pin ...)
//static const uint8_t D11 =  2; //PB_5

// these are also not defined in Energia ...
// could maybe just consider them flash pins?
static const uint8_t TCK = 0;
static const uint8_t TMS = 0;
static const uint8_t TMI = 0;
static const uint8_t TDO = 0;

//static const uint8_t D11 = PD_5;    // not defined in Energia (from USB)
static const uint8_t D12 = PB_0;
static const uint8_t D13 = PB_1;
static const uint8_t D14 = PB_2;
static const uint8_t D15 = PB_3;
static const uint8_t D16 = PB_6;
static const uint8_t D17 = PB_7;
static const uint8_t D18 = PF_4; // this is a button
static const uint8_t D19 = PD_7;

static const uint8_t D20 = PC_7;
static const uint8_t D21 = PC_6;
static const uint8_t D22 = PC_5;
static const uint8_t D23 = PC_4;

// these are the TX RX, don't need to mess with them ...
//static const uint8_t D24 = PA_0;
//static const uint8_t D25 = PA_1;

static const uint8_t D26 = 0;

static const uint8_t PIN_BT_RESET = 10;
static const uint8_t PIN_BT_CONTROL = 9;
 */

#endif
