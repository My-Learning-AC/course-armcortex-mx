/*
 * led.c
 *
 *  Created on: 29-Sep-2024
 *      Author: KumarDharani
 */

#include<stdio.h>
#include"led.h"


void delay(uint32_t count)
{
	for(uint32_t i=0; i<count; i++);
}


void led_init_all(void)
{
	uint32_t *pRccAhb1enr  = (uint32_t *)0x40023830;
	uint32_t *pGpioModeReg = (uint32_t *)0x40020C00;


	*pRccAhb1enr |= (1 << 3);
	// Configuration of all LEDs
	*pGpioModeReg |= (1 << (2 * LED_GREEN));
	*pGpioModeReg |= (1 << (2 * LED_ORANGE));
	*pGpioModeReg |= (1 << (2 * LED_RED));
	*pGpioModeReg |= (1 << (2 * LED_BLUE));

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);

}


void led_on(uint8_t led_no)
{
	uint32_t *pGpioDataReg = (uint32_t *)0x40020C14;
	*pGpioDataReg |= (1 << led_no);
}


void led_off(uint8_t led_no)
{
	uint32_t *pGpioDataReg = (uint32_t *)0x40020C14;
	*pGpioDataReg &= ~(1 << led_no);
}




