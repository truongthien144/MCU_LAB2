/*
 * ex10.h
 *
 *  Created on: Sep 25, 2024
 *      Author: TruongThien
 */

#ifndef INC_EX10_H_
#define INC_EX10_H_
#include "main.h"

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
void clearAllLED();
void displayLEDCol(int col);
void updateLEDMatrix(int index);
void updateLEDMatrixBuffer(int i);

#endif /* INC_EX10_H_ */
