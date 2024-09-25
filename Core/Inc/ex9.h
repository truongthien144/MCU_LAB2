/*
 * ex9.h
 *
 *  Created on: Sep 25, 2024
 *      Author: TruongThien
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_
#include "main.h"

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
void clearAllLED();
void displayLEDCol(int col);
void updateLEDMatrix(int index);
void updateLEDMatrixBuffer();

#endif /* INC_EX9_H_ */
