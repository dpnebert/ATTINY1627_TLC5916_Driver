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

void transmitCharacter(char p);
void enableOutput();
void disableOutput();
void allOn();
void allOff();


#endif /* TLC5916_H_ */