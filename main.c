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
	enableOutput();
	
	while (1) {	
		switchToSpecialMode();		
		writeConfiguration(255);
		switchToNormalMode();
		
		transmitCharacter(1, 8);
		_delay_us(5000000);
	}
}



