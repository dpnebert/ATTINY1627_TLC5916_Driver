/*
 * TCL5916.c
 *
 * Created: 5/1/2021 11:49:09 AM
 *  Author: dpneb
 */ 

#include "TLC5916.h"

void transmitCharacter(char p) {
	disableOutput();
	sendChar(p);
	latch();
	enableOutput();
}
