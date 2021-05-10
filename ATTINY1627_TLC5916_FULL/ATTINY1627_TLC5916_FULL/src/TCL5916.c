/*
 * TCL5916.c
 *
 * Created: 5/1/2021 11:49:09 AM
 *  Author: dpneb
 */ 

#include "TLC5916.h"

void transmitCharacter(char p, char c) {
	sendBits(p, 0, 0, c);
	pulseLatch();
}

void enableOutput() {
	OE_ED2_set_level(false);
}
void disableOutput() {
	OE_ED2_set_level(true);
}



void allOn() {
	transmitCharacter(ALL_ON, PACKET_FULL);
}
void allOff() {
	transmitCharacter(ALL_OFF, PACKET_FULL);
}

void switchToSpecialMode() {
	sendBits(DATA_NULL, STSM_OE, STSM_LE, PACKET_MODE);
}

void switchToNormalMode() {	
	sendBits(DATA_NULL, STNM_OE, STNM_LE, PACKET_MODE);
}

void writeConfiguration(uint8_t c) {
	sendBits(c, WCC_OE, WCC_LE, PACKET_FULL);
}



uint8_t readErrorCodeStatus() {	
	uint8_t reading = 0;	
	generateErrorCodeStatus();
	CLK_set_level(true);
	disableOutput();
	if( SOUT_get_level() ) {
		reading++;
	}
	CLK_set_level(false);
	
	for(char i = 0; i < 7; i++) {
		
		CLK_set_level(true);
		if( SOUT_get_level() ) {
			reading++;
		}
		CLK_set_level(false);
		reading = reading << 1;
	}
	return reading;
}

