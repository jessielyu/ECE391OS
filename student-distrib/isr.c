// c code for handling interrupts
//interrupt service routines
#include "isr.h"
#include "lib.h"
#include "types.h"
#include "rtc.h"
#include "i8259.h"
#include "idt.h"
#include "keyboard.h"

/*
IVT Offset | INT #     | Description
-----------+-----------+-----------------------------------
0x0000     | 0x00      | Divide by 0
0x0004     | 0x01      | Reserved
0x0008     | 0x02      | NMI Interrupt
0x000C     | 0x03      | Breakpoint (INT3)
0x0010     | 0x04      | Overflow (INTO)
0x0014     | 0x05      | Bounds range exceeded (BOUND)
0x0018     | 0x06      | Invalid opcode (UD2)
0x001C     | 0x07      | Device not available (WAIT/FWAIT)
0x0020     | 0x08      | Double fault
0x0024     | 0x09      | Coprocessor segment overrun
0x0028     | 0x0A      | Invalid TSS
0x002C     | 0x0B      | Segment not present
0x0030     | 0x0C      | Stack-segment fault
0x0034     | 0x0D      | General protection fault
0x0038     | 0x0E      | Page fault
0x003C     | 0x0F      | Reserved
0x0040     | 0x10      | x87 FPU error
0x0044     | 0x11      | Alignment check
0x0048     | 0x12      | Machine check
0x004C     | 0x13      | SIMD Floating-Point Exception
0x00xx     | 0x14-0x1F | Reserved
0x0xxx     | 0x20-0xFF | User definable
*/

/*
*	interrupt serveice routine
*	Coding Style: standard C
*	Inputs: a register_t data structure (see isr.h)
*	Outputs: none
*	Other: print interrupt message on terminal
*
*/
void isr_0(register_t reg)
{
	asm volatile("cli");
	clear();
	set_x(0);
	set_y(0);
	printf("\nDivide Error\n");
	blue_screen();
	
		asm volatile("sti		\n\
		leave		\n\
		iret		\n\
		");
}

void isr_1(register_t reg)
{
		asm volatile(
		"cli"
		);
		clear();
		set_x(0);
	set_y(0);
printf("\nReserved\n");
blue_screen();
		asm volatile("sti;leave;iret");
}

void isr_2(register_t reg)
{
			asm volatile(
		"cli"
		);
clear();		
printf("\nNonmaskable external interrupt\n");
asm volatile("sti;leave;iret");
}

void isr_3(register_t reg)
{
	
		asm volatile(
		"cli"
		);
clear();
set_x(0);
set_y(0);		
printf("\nBreakpoint\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_4(register_t reg)
{
		asm volatile(
		"cli"
		);
		clear();
	set_x(0);
	set_y(0);
printf("\nOverflow\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_5(register_t reg)
{
		asm volatile(
		"cli"
		);	
		clear();
	set_x(0);
	set_y(0);
printf("\nBOUND Range Exceeded\n");
blue_screen();
asm volatile("sti;leave;iret");
}		

void isr_6(register_t reg)
{
		asm volatile(
		"cli"
		);
		clear();
	set_x(0);
	set_y(0);
printf("\nInvalid Opcode\n");
blue_screen();
asm volatile("sti;leave;iret");
}	
			
			
void isr_7(register_t reg)
{		
		asm volatile(
		"cli"
		);
	clear();
	set_x(0);
	set_y(0);	
printf("\nDevice Not Avaliable (No Math Coprocessor)\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_8(register_error_t reg)
{		
		asm volatile(
		"cli"
		);	
clear();
	set_x(0);
	set_y(0);
printf("\nDouble Fault\n");
blue_screen();
asm volatile("sti;leave;iret");
}		
			
			
void isr_9(register_t reg)		
{
			asm volatile(
		"cli"
		);
clear();
	set_x(0);
	set_y(0);
printf("\nCoprocessor Segment Overrun\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_10(register_error_t reg)
{		
		asm volatile(
		"cli"
		);	
clear();
	set_x(0);
	set_y(0);
printf("\nInvalid TSS\n");
blue_screen();
asm volatile("sti;leave;iret");
}	
	
void isr_11(register_error_t reg)
{
		asm volatile("cli");
clear();
	set_x(0);
	set_y(0);
printf("\nSegment Not Present\n");
blue_screen();
asm volatile("sti;leave;iret");
}		

void isr_12(register_error_t reg)
{
	asm volatile("cli");
	clear();
		set_x(0);
	set_y(0);
printf("\nStack-Segment Fault\n");
asm volatile("sti;leave;iret");
}
		
void isr_13(register_error_t reg)
{
	asm volatile("cli");
	clear();
		set_x(0);
	set_y(0);
printf("\nGeneral Protection\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_14(register_error_t reg)
{
asm volatile("cli");
clear();
	set_x(0);
	set_y(0);	
printf("\nPage Fault\n");
asm volatile("sti;leave;iret");
}

void isr_15(register_t reg)
{	
asm volatile("cli");
clear();	
	set_x(0);
	set_y(0);	
printf("\nx87 FPU Floating-Point Error\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_16(register_t reg)
{	
asm volatile("cli");
clear();
	set_x(0);
	set_y(0);		
printf("\nAlignment Check\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_17(register_t reg)
{	
asm volatile("cli");
clear();	
	set_x(0);
	set_y(0);	
printf("\nMachine Check\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_18(register_t reg)
{	
asm volatile("cli");
clear();
	set_x(0);
	set_y(0);
printf("\nSIMD FLoating-Point Exception\n");
blue_screen();
asm volatile("sti;leave;iret");
}

void isr_19(register_t reg)
{	
asm volatile("cli");
clear();		
	set_x(0);
	set_y(0);
printf("\ninterrupt not identified");
blue_screen();
asm volatile("sti;leave;iret");
}
	// }
	// if(RPL == 0)
	// {
		// printf("exception in kernel\n");
	// }
	// else
	// {
		// printf("exception in user\n");
	// }
// }

/* 
 * keyboard_handler
 *
 *   DESCRIPTION: func to handle keyboard interrupts
 *   INPUTS: none
 *   OUTPUTS: echo key in terminal
 *   RETURN VALUE: none
 *   SIDE EFFECTS: none
 */
void keyboard_handler()
{

	cli();
	asm volatile("pushal");
	unsigned int input = 0;
	input = inb(KEYBOARD_PORT);
	unsigned char output;
	output = code_set[input];
	send_eoi(KB_IRQ);
	if(input < RELEASE_VAL)
	putc(output);
	asm volatile("popal");
	sti();
	asm("leave;iret");
}

/* 
 * rtc_handler
 *
 *   DESCRIPTION: func to handle rtc interrupts
 *   INPUTS: none
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: none
 */
void rtc_handler()
{
	asm("pushal");
	outb(0x0C, RTC_PORT);	// select register C
	inb(RTC_CMOS_PORT);	
	send_eoi(RTC_IRQ);

	sti();
	asm("popal;leave;iret");
}
