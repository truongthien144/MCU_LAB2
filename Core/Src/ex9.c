/*
 * ex9.c
 *
 *  Created on: Sep 25, 2024
 *      Author: TruongThien
 */
#include "ex9.h"

void  display7SEG(int num){
	const uint8_t segmentPatterns[10] = {
	        0b11000000, // 0
	        0b11111001, // 1
	        0b10100100, // 2
	        0b10110000, // 3
	        0b10011001, // 4
	        0b10010010, // 5
	        0b10000010, // 6
	        0b11111000, // 7
	        0b10000000, // 8
	        0b10010000  // 9
	};

	if (num < 0 || num > 9){
		return;// Handle invalid input
	}

	uint8_t segments = segmentPatterns[num];

	// Set the GPIO pins according to the 7-segment pattern for the digit
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

const int MAX_LED = 4;
int led_buffer [4] =  {9, 8, 7, 6};

void update7SEG(int index){
	if (index >= MAX_LED){
		return;
	}
	switch (index){
	case 0:
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		break;
	case 1:
		display7SEG(led_buffer[1]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	    break;
	case 2:
		display7SEG(led_buffer[2]);
	    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	    break;
	case 3:
		display7SEG(led_buffer[3]);
	    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	    break;
	default:
		break;
	}
}

int hour = 15, minute = 8, second = 50;

void updateClockBuffer(){
 	  led_buffer[0] = hour / 10;
 	  led_buffer[1] = hour % 10;
 	  led_buffer[2] = minute / 10;
 	  led_buffer[3] = minute % 10;
}

void clearAllLED(){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
}


void displayLEDCol(int col){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ~(col >> 7) & 1);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ~(col >> 6) & 1);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ~(col >> 5) & 1);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ~(col >> 4) & 1);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ~(col >> 3) & 1);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ~(col >> 2) & 1);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ~(col >> 1) & 1);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ~(col >> 0) & 1);
}


const int MAX_LED_MATRIX = 8;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

void updateLEDMatrix(int index){
    switch (index){
        case 0:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
        	displayLEDCol(matrix_buffer[0]);
            break;
        case 1:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
        	displayLEDCol(matrix_buffer[1]);
            break;
        case 2:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
        	displayLEDCol(matrix_buffer[2]);
            break;
        case 3:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
        	displayLEDCol(matrix_buffer[3]);
            break;
        case 4:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
        	displayLEDCol(matrix_buffer[4]);
            break;
        case 5:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
        	displayLEDCol(matrix_buffer[5]);
            break;
        case 6:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
        	displayLEDCol(matrix_buffer[6]);
            break;
        case 7:
        	clearAllLED();
        	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
        	displayLEDCol(matrix_buffer[7]);
            break;
        default:
            break;
    }
}

void updateLEDMatrixBuffer(){
	 //Init the hex values for the character "A"
	  const uint8_t letterA[8] = {
			  0x00, // 00011000
			  0x3F, // 00111100
			  0x7F, // 01100110
			  0xCC, // 11000011
			  0xCC, // 11000011
			  0x7F, // 11111111
			  0x3F, // 11000011
			  0x00  // 11000011
	  };
	  //Copy the hex values to the matrix_buffer
	  matrix_buffer[0] = letterA[0];
	  matrix_buffer[1] = letterA[1];
	  matrix_buffer[2] = letterA[2];
	  matrix_buffer[3] = letterA[3];
	  matrix_buffer[4] = letterA[4];
	  matrix_buffer[5] = letterA[5];
	  matrix_buffer[6] = letterA[6];
	  matrix_buffer[7] = letterA[7];
}
