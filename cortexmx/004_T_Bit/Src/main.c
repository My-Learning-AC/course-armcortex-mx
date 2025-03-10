/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/


#include <stdio.h>
#include <stdint.h>


/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR  = (uint32_t *) 0xE000EF00;
	uint32_t *pISER0 = (uint32_t *) 0xE000E100;

	// enable IRQ3 interrupt
	*pISER0 |= (1 << 3);

	// generate an interrupt from software for IRQ3
	*pSTIR = (3 & 0x1FF);
}


void change_access_level_unpriv()
{
	// Read
	__asm volatile("MRS R0, CONTROL");
	// Modify
	__asm volatile("ORR R0, R0, #0x01");
	// Write
	__asm volatile("MSR CONTROL, R0");
}


/* This function executes in THREAD MODE + PRIV ACCESS LEVEL of the processor */
int main(void)
{
	printf("In thread mode : before interrupt\n");

	void (*fun_ptr)(void);

	fun_ptr = change_access_level_unpriv;   // This is OK
	//fun_ptr = (void *) 0x080001e8;        // This will cause a Hard Fault exception because the T bit (i.e., the LSB of the address or will be the LSB bit of PC) is even (i.e., T bit = 0)

	fun_ptr();

	printf("In thread mode : after interrupt\n");

	for(;;);
}


/* This function(ISR) executes in HANDLER MODE of the processor */
void RTC_WKUP_IRQHandler(void)
{
	printf("In handler mode : ISR\n");
}

void HardFault_Handler(void)
{
	printf("Hard Fault detected\n");
	while(1);
}


