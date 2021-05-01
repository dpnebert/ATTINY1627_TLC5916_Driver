#include <atmel_start.h>
#include "TLC5916.h"
#include <util/delay.h>

uint8_t outputPin;
uint8_t latchPin;
uint8_t outputPin;

char output;

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	output = 0;
	
	/* Replace with your application code */
	while (1) {
		transmitCharacter(++output);		
		USART0.TXDATAL = output;
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
