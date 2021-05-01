/*
 * TCL5916.c
 *
 * Created: 5/1/2021 11:49:09 AM
 *  Author: dpneb
 */ 

#include "TLC5916.h"

void transmitCharacter(char p) {
	sendChar(p);
	latch();
}

void enableOutput() {
	OE_ED2_set_level(false);
}
void disableOutput() {
	OE_ED2_set_level(true);
}
void allOn() {
	transmitCharacter(0xFF);
}
void allOff() {
	transmitCharacter(0x00);
}
	