#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

uint8_t outputPin;
uint8_t latchPin;
uint8_t outputPin;

uint16_t counter;

uint8_t count;

void printToTerminal(uint8_t r);
void nightRider();
void magiger();

int main(void)
{
	atmel_start_init();
	
	switchToNormalMode();
	counter = 0;
	count = 0;
	
	enableOutput();
	allOn();
	_delay_us(100000);
	while (1) {		
		magiger();
		
	}
}
void magiger() {
	switchToSpecialMode();
	
	writeConfiguration((count << 2) + 3);
		
	
	_delay_us(100000);
	switchToNormalMode();
	allOn();
	_delay_us(100000);
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





