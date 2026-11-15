/*
 * custom.c
 *
 *  Created on: 14 нояб. 2026 г.
 *      Author: alexey
 */

#include "main.h"

void setup()
{}

void loop()
{
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, RESET);
	HAL_Delay(1000);
}
