#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

uint8_t token, dir;

int main(void)
{
	token = 1;
	dir = 1;
	
	atmel_start_init();
	_delay_us(100000);	
	
	
	switchToSpecialMode();
	writeConfiguration(WCC_FULL_BRIGHT);
	switchToNormalMode();
	
	enableOutput();
	
	while (1) {	
		transmitCharacter(token, 8);
		
		if(token == 128) {
			token = 1;
		} else {
			token = token << 1;
		}
		
		_delay_us(1000000);
	}
}



