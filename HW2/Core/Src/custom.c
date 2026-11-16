/*
 * custom.c
 *
 *  Created on: 16 нояб. 2026 г.
 *      Author: alexey
 */

#include "main.h"

void init_led(GPIO_TypeDef* port, uint16_t pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* Включаем тактирование нужного порта */
	if (port == GPIOA)      __HAL_RCC_GPIOA_CLK_ENABLE();
	else if (port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
	else if (port == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
	else if (port == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();

	/* Настройка пина как выход */
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void blink()
{
	__NOP();
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, SET);
	HAL_Delay(300);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, RESET);
}
