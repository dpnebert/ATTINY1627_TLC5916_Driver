#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

uint8_t outputPin;
uint8_t latchPin;
uint8_t outputPin;

uint16_t counter;

uint8_t count, brightness;

void printToTerminal(uint8_t r);
void nightRider();
void majiger(uint8_t b);

int main(void)
{
	brightness = 1;
	atmel_start_init();
	_delay_us(100000);
	//majiger();
	enableOutput();
	
// 	
// 	//switchToNormalMode();
// 	counter = 0;
// 	count = 32;
// 	
// 	enableOutput();
// 	allOn();
// 	_delay_us(100000);
	while (1) {	
		
		if(brightness == 255) {
			brightness = 0;
			} else {
			brightness = 255;
		}
			
		majiger(brightness);
		
		transmitCharacter(1, 8);
		_delay_us(5000000);
	}
}
void majiger(uint8_t b) {
	switchToSpecialMode();
	
	writeConfiguration(b);// + 192);
		
	
	_delay_us(10);
	switchToNormalMode();
	
}
void printToTerminal(uint8_t r) {
	uint8_t divisor = 0;
	if(r >= 100) {
		divisor = r / 100;
		USART0.TXDATAL = divisor + 48;
		r = r - (divisor * 100);
	}
	
	if(r >= 10) {
		divisor = r / 10;
		USART0.TXDATAL = divisor + 48;
		r = r - (divisor * 10);
		} else if(divisor > 0) {
		USART0.TXDATAL = 48;
	}
	
	USART0.TXDATAL = r + 48;
	_delay_us(100);
	
	USART0.TXDATAL = '\r';
	USART0.TXDATAL = '\n';
}
void nightRider() {
	char out = 1;
	char dir = 1;
	for(int i = 0; i < 16; i++) {
		transmitCharacter(out, PACKET_FULL);
		if(dir == 1) {
			if(out == 128) {
				dir = 0;
				} else {
				out = out << 1;
				}
			} else if(dir == 0) {
			if(out == 1) {
				dir = 1;
				} else {
				out = out >> 1;
			}
		}
		_delay_us(50000);
	}
	
}





