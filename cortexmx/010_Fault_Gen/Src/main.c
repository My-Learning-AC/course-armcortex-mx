/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/
#include<stdio.h>
#include<stdint.h>

int main(void)
{
	// 1. Enable all configurable exceptions like usage fault, mem manage fault and bus fault
	uint32_t *pSHCSR = (uint32_t *)0xE000ED24;

	*pSHCSR |= (1 << 16); // MemManage Fault
	*pSHCSR |= (1 << 17); // Bus Fault
	*pSHCSR |= (1 << 18); // Usage Fault

	// 3. Lets force the processor to execute some undefined instruction
	uint32_t *pSRAM = (uint32_t *)0x20010000;
	*pSRAM = 0xFFFFFFFF;

	void (*some_address) (void);

	//some_address = (void *) (((uint32_t )pSRAM) + 1);  // +1 for the T bit    /* This generates the Usage fault of Invalid Instruction */

	some_address = (void *) ((uint32_t )pSRAM);          // T bit = 0

	some_address();

	// 4. Analyze the fault

	for(;;);
}


// 2. Implement the fault handlers
void HardFault_Handler()
{
	printf("Exception: Hard Fault\n");
	while(1);
}

void MemManage_Handler()
{
	printf("Exception: MemManage Fault\n");
	while(1);
}

void BusFault_Handler()
{
	printf("Exception: Bus Fault\n");
	while(1);
}

void UsageFault_Handler()
{
	uint32_t *pUFSR = (uint32_t *)0xE000ED2A;
	printf("Exception: Usage Fault\n");
	printf("UFSR = %lx\n", (*pUFSR) & 0xFFFF);
	while(1);
}

