/*
 * MAX7219_driver.c
 *
 *  Created on: Mar 4, 2023
 *      Author: PC
 */
#include "MAX7219_driver.h"

/**
  * @brief  Enabling or disabling shutdown mode.
  * @param  ENABLE or DISABLE macro
  * @retval None
  */
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

/**
  * @brief  Enabling or disabling test mode.
  * @param  ENABLE or DISABLE macro
  * @retval None
  */
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

/**
  * @brief  Setting display brightness.
  * @param  INTENSITY_X_OVER_32 where X is nominator of X/32 fraction which is proportional
  * 		to display brightness. All possible X values can be found in header file.
  * @retval None
  */
void MAX7219_set_display_intensity(uint8_t display_intensity){

	data_to_transmit_t data;
	data.address = INTENSITY_ADDRESS;
	data.payload = display_intensity;
	spi_send(&data);
}

/**
  * @brief  Setting digits which should be active during display work.
  * 		Digits that are not active can not be used to display data.
  * @param  Possible options can be found in the header file in the scan
  * 		limit register format macros definitions
  * @retval None
  */
void MAX7219_set_scan_limit_register_format(uint8_t number_of_digits_to_display){

	data_to_transmit_t data;
	data.address = SCAN_LIMIT_ADDRESS;
	data.payload = number_of_digits_to_display;
	spi_send(&data);
}

/**
  * @brief  Setting which digits of display should use BCD code.
  * @param  Possible options can be found in the header file in the
  * 		decode register format macros definitions
  * @retval None
  */
void MAX7219_set_decode_register_format(uint8_t register_format){

	data_to_transmit_t data;
	data.address = DECODE_MODE_ADDRESS;
	data.payload = register_format;
	spi_send(&data);
}

//BCD DECODIN FORMAT ON EVERY DIGIT DISPLAYING FUNCTIONS
/**
  * @brief  Blanking entire screen when decoding in BCD mode is set on every digit.
  * @param  None
  * @retval None
  */
void MAX7219_BCD_clear_display(void){

	data_to_transmit_t data;
	data.payload = BLANK_DISPLAY_CODE;
	for(uint8_t digit_address = DIGIT_0_ADDRESS; digit_address <= DIGIT_7_ADDRESS; digit_address++){
		data.address = digit_address;
		spi_send(&data);
	}
}

/**
  * @brief  Displaying single character when decoding in BCD mode is set on every digit.
  * @param  Code of character which user want to display in BCD code, can be found in header file
  * @param  Address of digit of the display which user want to use to display character
  * @param  Enabling or disabling decimal point on digit of the display chosen by user
  * @retval None
  */
void MAX7219_BCD_display_single_char(uint8_t character_code, uint8_t digit_address, uint8_t EnorDi_decimal_point){

	data_to_transmit_t data;
	data.payload = character_code;
	if(EnorDi_decimal_point == ENABLE){
		data.payload |= (1 << 7);
	}
	data.address = digit_address;
	spi_send(&data);

}

void MAX7219_BCD_Init(void){

	  MAX7219_EnorDi_shutdown_mode(DISABLE);
	  MAX7219_set_display_intensity(INTENSITY_31_OVER_32);
	  MAX7219_set_scan_limit_register_format(DISPLAY_0_TO_7_DIGITS);
	  MAX7219_set_decode_register_format(DECODE_0_TO_7_DIGITS);
	  MAX7219_BCD_clear_display();

}
