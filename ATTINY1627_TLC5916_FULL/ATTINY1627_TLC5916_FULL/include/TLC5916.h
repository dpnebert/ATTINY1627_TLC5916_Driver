/*
 * TLC5916.h
 *
 * Created: 4/29/2021 9:29:59 PM
 *  Author: dpneb
 */ 

#include "include/atmel_start_pins.h"
#include "TLC5916_Util.h"

#ifndef TLC5916_H_
#define TLC5916_H_

#define ALL_ON			255
#define ALL_OFF			0

#define STSM_OE			29
#define STSM_LE			8

#define STNM_OE			29
#define STNM_LE			0

#define WCC_OE			255
#define WCC_LE			128

#define DATA_NULL		0

#define PACKET_FULL		8
#define PACKET_MODE		5

void transmitCharacter(char p, char c);
void enableOutput();
void disableOutput();
void allOn();
void allOff();

void switchToSpecialMode();
void switchToNormalMode();

void writeConfiguration(uint8_t c);
uint8_t readErrorCodeStatus();


#endif /* TLC5916_H_ */