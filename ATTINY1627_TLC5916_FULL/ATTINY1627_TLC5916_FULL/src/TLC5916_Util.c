/*
 * TLC5916_Util.c
 *
 * Created: 5/1/2021 11:47:48 AM
 *  Author: dpneb
 */ 

#include "TLC5916_Util.h"



void sendBits(char d, char o, char l, char c) {
	char bitMask = 1;
	for(char i = 0; i < c; i++) {
		SDI_set_level((d & bitMask) > 0);
		OE_ED2_set_level( (o & bitMask) > 0 );
		LE_ED1_set_level( (l & bitMask) > 0 );
		bitMask = bitMask << 1;
		CLK_set_level(true);
		CLK_set_level(false);
	}
	SDI_set_level(false);
}

void pulseLatch() {
	LE_ED1_set_level(true);
	LE_ED1_set_level(false);
}

void latchHigh() {
	LE_ED1_set_level(true);
}
void latchLow() {
	LE_ED1_set_level(false);
}
void generateErrorCodeStatus() {
	sendBits(0, 1, 0, 8);
}