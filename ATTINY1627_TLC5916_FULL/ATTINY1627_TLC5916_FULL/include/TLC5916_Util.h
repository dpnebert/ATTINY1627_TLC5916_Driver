/*
 * TLC5916_Util.h
 *
 * Created: 4/29/2021 10:02:47 PM
 *  Author: dpneb
 */ 


#include "include/atmel_start_pins.h"
#ifndef TLC5916_UTIL_H_
#define TLC5916_UTIL_H_


uint8_t readBits();
void sendBits(char d, char o, char l, char c);
void pulseLatch();
void latchHigh();
void latchLow();
void generateErrorCodeStatus();


#endif /* TLC5916_UTIL_H_ */