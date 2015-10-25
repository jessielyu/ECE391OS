#ifndef ISR_H
#define ISR_H

#include "types.h"
typedef struct registers_error
{
	
	uint32_t err_code;
	uint32_t eip, cs, eflags,useresp, ss;

} register_error_t;

typedef struct registers
{
	
	uint32_t eip, cs, eflags,useresp, ss;

} register_t;

extern void isr_0(register_t reg);
extern void isr_1(register_t reg);
extern void isr_2(register_t reg);
extern void isr_3(register_t reg);
extern void isr_4(register_t reg);
extern void isr_5(register_t reg);
extern void isr_6(register_t reg);
extern void isr_7(register_t reg);
extern void isr_8(register_error_t reg);
extern void isr_9(register_t);
extern void isr_10(register_error_t reg);
extern void isr_11(register_error_t reg);
extern void isr_12(register_error_t reg);
extern void isr_13(register_error_t reg);
extern void isr_14(register_error_t reg);
extern void isr_15(register_t reg);
extern void isr_16(register_t reg);
extern void isr_17(register_t reg);
extern void isr_18(register_t reg);
extern void isr_19(register_t reg);

//other isr
extern void keyboard_handler();
extern void rtc_handler();
#endif
