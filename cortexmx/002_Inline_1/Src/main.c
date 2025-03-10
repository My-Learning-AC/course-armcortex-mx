/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

int main(void)
{

	 //--------------------------------------------------------------------------------------------------
	 // Inline Example 1 : Addition of two numbers from two locations (i.e., - 0x20001000 & 0x20001004)

	__asm volatile("LDR R1, =#0x20001000");
	__asm volatile("LDR R2, =#0x20001004");
	__asm volatile("LDR R0, [R1]");
	__asm volatile("LDR R1, [R2]");
	__asm volatile("ADD R0, R0, R1");
	__asm volatile("STR R0, [R2]");

	//----------------------------------------------------------------------------------------------------



	/*
	 //-----------------------------------------------------------------------------------------------------
	 // Inline Example 2 : Move the content of 'C' variable 'val' to ARM register R0

	int val = 50;
	__asm volatile("MOV R0, %0" :  : "r"(val));
	// Can be used      __asm volatile("MOV R0, %0" :  : "r"(val) : );        also

	 //-----------------------------------------------------------------------------------------------------
	 */



	/*
	 //-----------------------------------------------------------------------------------------------------
	 // Inline Example 3 : Move an Immediate value into ARM register R0

	 //__asm volatile("MOV R0, %0" :  : "i"(50));

	 //------------------------------------------------------------------------------------------------------
	 */


	/*
	//-------------------------------------------------------------------------------------------------------
	// Inline Example 4 : Read the CONTROL register into 'control_reg' variable

	int control_reg;
	__asm volatile("MRS %0, CONTROL" : "=r"(control_reg));

	//-------------------------------------------------------------------------------------------------------
	 */


	/*
	//--------------------------------------------------------------------------------------------------------
	// Inline Example 5 : Copy the content of 'C' variable var1 to var2

	int var1 = 10, var2;
	__asm volatile("MOV %0, %1" : "=r"(var2) : "r"(var1));

	//--------------------------------------------------------------------------------------------------------
	 */



	/*
	//--------------------------------------------------------------------------------------------------------
	// Inline Example 6 : Copy the content of a pointer into another variable

	int p1, *p2;
	p2 = (int *)0x20000008;
	__asm volatile("LDR %0, [%1]" : "=r"(p1) : "r"(p2));  // p1 = *p2

	//--------------------------------------------------------------------------------------------------------
	 */


	for(;;);
}

