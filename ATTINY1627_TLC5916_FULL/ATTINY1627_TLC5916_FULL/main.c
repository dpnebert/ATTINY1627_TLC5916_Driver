#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

int main(void)
{
	atmel_start_init();
	
	switchToSpecialMode();
	writeConfiguration(0b11111111);	
	switchToNormalMode();
	
	allOn();
	enableOutput();
	
	while (1) {
		
	}
}