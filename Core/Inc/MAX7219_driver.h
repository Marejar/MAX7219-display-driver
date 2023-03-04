/*
 * MAX7219_driver.h
 *
 *  Created on: Mar 4, 2023
 *      Author: PC
 */

#ifndef INC_MAX7219_DRIVER_H_
#define INC_MAX7219_DRIVER_H_

//DEFINITIONS

//ADDRESSES - 4 most significant bits can be dummy bits, set to 0 in this driver
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
#define DISPLAY_TEST_ADDRESS 0x0D

#endif /* INC_MAX7219_DRIVER_H_ */
