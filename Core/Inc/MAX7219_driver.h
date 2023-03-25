/*
 * MAX7219_driver.h
 *
 *  Created on: Mar 4, 2023
 *      Author: PC
 */

#ifndef INC_MAX7219_DRIVER_H_
#define INC_MAX7219_DRIVER_H_

#include <stdint.h>

//MACROS DEFINITIONS

//Addresses - 4 most significant bits can be dummy bits, which have been set to 0 in this driver
#define NO_OP_ADDRESS 0x00
#define DIGIT_0_ADDRESS 0x01
#define DIGIT_1_ADDRESS 0x02
#define DIGIT_2_ADDRESS 0x03
#define DIGIT_3_ADDRESS 0x04
#define DIGIT_4_ADDRESS 0x05
#define DIGIT_5_ADDRESS 0x06
#define DIGIT_6_ADDRESS 0x07
#define DIGIT_7_ADDRESS 0x08
#define DECODE_MODE_ADDRESS 0x09
#define INTENSITY_ADDRESS 0x0A
#define SCAN_LIMIT_ADDRESS 0x0B
#define SHUTDOWN_ADDRESS 0x0C
#define DISPLAY_TEST_ADDRESS 0x0F

//Codes of digits which can be displayed in BCD format
#define DIGIT_0_DISPLAY_CODE 0x00
#define DIGIT_1_DISPLAY_CODE 0x01
#define DIGIT_2_DISPLAY_CODE 0x02
#define DIGIT_3_DISPLAY_CODE 0x03
#define DIGIT_4_DISPLAY_CODE 0x04
#define DIGIT_5_DISPLAY_CODE 0x05
#define DIGIT_6_DISPLAY_CODE 0x06
#define DIGIT_7_DISPLAY_CODE 0x07
#define DIGIT_8_DISPLAY_CODE 0x08
#define DIGIT_9_DISPLAY_CODE 0x09

//Symbols and letters code in BCD format
#define DASH_DISPLAY_CODE 0x0A
#define LETTER_E_DISPLAY_CODE 0x0B
#define LETTER_H_DISPLAY_CODE 0x0C
#define LETTER_L_DISPLAY_CODE 0x0D
#define LETTER_P_DISPLAY_CODE 0x0E
#define BLANK_DISPLAY_CODE 0x0F

//Shutdown register formats
#define SHUTDOWN_MODE 0x00
#define SHUTDOWN_NORMAL_OPERATION_MODE 0x01

//Display test register format
#define TEST_NORMAL_OPERATION_MODE 0x00
#define TEST_MODE 0x01

//Display intensity
#define INTENSITY_1_OVER_32 0X00
#define INTENSITY_3_OVER_32 0X01
#define INTENSITY_5_OVER_32 0X02
#define INTENSITY_7_OVER_32 0X03
#define INTENSITY_9_OVER_32 0X04
#define INTENSITY_11_OVER_32 0X05
#define INTENSITY_13_OVER_32 0X06
#define INTENSITY_15_OVER_32 0X07
#define INTENSITY_17_OVER_32 0X08
#define INTENSITY_19_OVER_32 0X09
#define INTENSITY_21_OVER_32 0X0A
#define INTENSITY_23_OVER_32 0X0B
#define INTENSITY_25_OVER_32 0X0C
#define INTENSITY_27_OVER_32 0X0D
#define INTENSITY_29_OVER_32 0X0E
#define INTENSITY_31_OVER_32 0X0F

//Scan limit register format (how many digits of display should be displayed)
#define DISPLAY_0_DIGIT_ONLY 0x00
#define DISPLAY_0_AND_1_DIGITS 0x01
#define DISPLAY_0_TO_2_DIGITS 0X02
#define DISPLAY_0_TO_3_DIGITS 0X03
#define DISPLAY_0_TO_4_DIGITS 0X04
#define DISPLAY_0_TO_5_DIGITS 0X05
#define DISPLAY_0_TO_6_DIGITS 0X06
#define DISPLAY_0_TO_7_DIGITS 0X07

//Decode register format (decoding means that BCD code must be sent
//as a data on a proper digit address to display demanded digit)
//No decoding means that every bit of data is associated with
//single segment of display digit
#define NO_DECODE 0x00
#define DECODE_0_DIGIT_ONLY 0x01
#define DECODE_0_TO_3_DIGITS 0x0F
#define DECODE_0_TO_7_DIGITS 0xFF

//Other macros
#define ENABLE 1
#define DISABLE 0

typedef struct{
	uint8_t address;
	uint8_t payload;
}data_to_transmit_t;


//Pointer to SPI Transmit function which should be implemented
//and assign to this pointer by user of the driver
void(*spi_send)(data_to_transmit_t *data);

//Settings functions
void MAX7219_EnorDi_shutdown_mode(uint8_t EnorDi);
void MAX7219_EnorDi_test_mode(uint8_t EnorDi);
void MAX7219_set_display_intensity(uint8_t display_intensity);
void MAX7219_set_scan_limit_register_format(uint8_t number_of_digits_to_display);
void MAX7219_set_decode_register_format(uint8_t register_format);

//Displaying functions for BCD decoding on every digit (DECODE_0_TO_7_DIGITS is used)
void MAX7219_BCD_clear_display(void);
void MAX7219_BCD_display_single_char(uint8_t character_code, uint8_t digit_address, uint8_t EnorDi_decimal_point);

//Default initializing function for BCD decoding on every digit (DECODE_0_TO_7_DIGITS is used)
void MAX7219_BCD_Init(void);



#endif /* INC_MAX7219_DRIVER_H_ */
