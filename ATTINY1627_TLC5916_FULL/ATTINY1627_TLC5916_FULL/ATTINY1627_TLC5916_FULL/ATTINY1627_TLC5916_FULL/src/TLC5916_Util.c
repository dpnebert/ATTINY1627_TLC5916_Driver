/*
 * TLC5916_Util.c
 *
 * Created: 5/1/2021 11:47:48 AM
 *  Author: dpneb
 */ 

#include "TLC5916_Util.h"

void sendChar(char p) {
	char bitMask = 1;
	for(char i = 0; i < 8; i++) {
		SDI_set_level((p & bitMask) > 0);
		bitMask = bitMask << 1;
		CLK_set_level(true);
		CLK_set_level(false);
	}
	SDI_set_level(false);
}
void latch() {
	LE_ED1_set_level(true);
	LE_ED1_set_level(false);
}


