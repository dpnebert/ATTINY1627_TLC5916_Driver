#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

uint8_t outputPin;
uint8_t latchPin;
uint8_t outputPin;


void nightRider();

int main(void)
{
	atmel_start_init();
		
	enableOutput();
	
	nightRider();
	
	allOn();
	//allOff();
	
	while (1) {
		
	}
}

void nightRider() {
	char out = 1;
	char dir = 1;
	for(int i = 0; i < 16; i++) {
		transmitCharacter(out);
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
		_delay_us(100000);
	}
	
}









/*
void i2c_send(char p) {
	I2C_0_open(p);
	//I2C_0_set_buffer(values, 1);
	//I2C_0_set_address_nack_callback(i2c_cb_restart_write, NULL); // NACK polling?
	I2C_0_master_write();
	I2C_0_close();
	SDI_set_level(false);
}
*/
