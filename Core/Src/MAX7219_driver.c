/*
 * MAX7219_driver.c
 *
 *  Created on: Mar 4, 2023
 *      Author: PC
 */
#include "MAX7219_driver.h"

void EnorDi_shutdown_mode(uint8_t EnorDi){

	data_to_transmit_t data;
	data.address = SHUTDOWN_ADDRESS;

	if(EnorDi == ENABLE){
		data.payload = SHUTDOWN_MODE;
		spi_send(&data);
	}else if(EnorDi == DISABLE){
		data.payload = NORMAL_OPERATION_MODE;
		spi_send(&data);
	}else{
		//nothing should happen, wrong data passed to the function
	}

}
