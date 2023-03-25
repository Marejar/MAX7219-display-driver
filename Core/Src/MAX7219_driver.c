/*
 * MAX7219_driver.c
 *
 *  Created on: Mar 4, 2023
 *      Author: PC
 */
#include "MAX7219_driver.h"

void MAX7219_EnorDi_shutdown_mode(uint8_t EnorDi){

	data_to_transmit_t data;
	data.address = SHUTDOWN_ADDRESS;

	if(EnorDi == ENABLE){
		data.payload = SHUTDOWN_MODE;
		spi_send(&data);
	}else if(EnorDi == DISABLE){
		data.payload = SHUTDOWN_NORMAL_OPERATION_MODE;
		spi_send(&data);
	}else{
		//nothing should happen, wrong argument passed to the function
	}
}

void MAX7219_EnorDi_test_mode(uint8_t EnorDi){

	data_to_transmit_t data;
	data.address = DISPLAY_TEST_ADDRESS;

	if(EnorDi == ENABLE){
		data.payload = TEST_MODE;
		spi_send(&data);
	}else if(EnorDi == DISABLE){
		data.payload = TEST_NORMAL_OPERATION_MODE;
		spi_send(&data);
	}else{
		//nothing should happen, wrong argument passed to the function
	}
}

void MAX7219_set_display_intensity(uint8_t display_intensity){

	data_to_transmit_t data;
	data.address = INTENSITY_ADDRESS;
	data.payload = display_intensity;
	spi_send(&data);
}

void MAX7219_set_scan_limit_register_format(uint8_t number_of_digits_to_display){

	data_to_transmit_t data;
	data.address = SCAN_LIMIT_ADDRESS;
	data.payload = number_of_digits_to_display;
	spi_send(&data);
}

void MAX7219_set_decode_register_format(uint8_t register_format){

	data_to_transmit_t data;
	data.address = DECODE_MODE_ADDRESS;
	data.payload = register_format;
	spi_send(&data);
}

//BCD DISPLAYING FUNCTIONS
void MAX7219_BCD_clear_display(void){

	data_to_transmit_t data;
	data.payload = BLANK_DISPLAY_CODE;
	for(uint8_t digit_address = DIGIT_0_ADDRESS; digit_address <= DIGIT_7_ADDRESS; digit_address++){
		data.address = digit_address;
		spi_send(&data);
	}
}

void MAX7219_BCD_display_single_char(uint8_t character_code, uint8_t digit_address, uint8_t EnorDi_decimal_point){

	data_to_transmit_t data;
	data.payload = character_code;
	if(EnorDi_decimal_point == ENABLE){
		data.payload |= (1 << 8);
	}
	data.address = digit_address;
	spi_send(&data);

}
