/*set up idt*/
#include "x86_desc.h"
/*set gate*/
#include "isr.h"
#include "lib.h"
#include "idt.h"

//static uint8_t i_attr = 0x8E;
// static uint8_t t_attr = 0x8F;
// static uint8_t call_attr = 0x85;


/* 
 * idt_init
 *   DESCRIPTION:initializes the idt
 *   INPUTS: none
 *   OUTPUTS: none
 *   RETURN VALUE: none
 *   SIDE EFFECTS: none
 */

void idt_init()
{
	isr_set();
}




/* 
 * idt_set_gate
 *   DESCRIPTION:set the idt gates
 *   INPUTS: vector, function location, cs selector, attributes
 *   OUTPUTS: none
 *   RETURN VALUE: 0 on success
 *   SIDE EFFECTS: none
 */

void 
idt_set_gate(uint8_t vector, uint32_t base, uint16_t selector, uint8_t DPL)
{
	uint32_t idx = vector;
	//idt[idx].offset_15_00 = base & 0xFFFF;
	idt[idx].seg_selector = selector;
	idt[idx].reserved4 = 0;
	idt[idx].reserved3 = 0;
	idt[idx].reserved2 = 1;
	idt[idx].reserved1 = 1;
	idt[idx].size 		= 1;
	idt[idx].reserved0 = 0;
	idt[idx].dpl		= DPL;
	idt[idx].present   = 1;
	//idt[idx].offset_31_16 = (base >> 16) & 0xFFFF;
	SET_IDT_ENTRY(idt[idx], base);
	
	/*transfer to idt table*/
	
	
}

/* 
 * isr_set
 *   DESCRIPTION:set the isr gates in idt
 *   INPUTS: vector, function location, cs selector, attributes
 *   OUTPUTS: none
 *   RETURN VALUE: 0 on success
 *   SIDE EFFECTS: none
 */
void
isr_set()
{
	
	/* isr# is the handler entry*/
	
	idt_set_gate(0, (uint32_t)isr_0, KERNEL_CS, 0);
	idt_set_gate(1, (uint32_t)isr_1, KERNEL_CS, 0);
	idt_set_gate(2, (uint32_t)isr_2, KERNEL_CS, 0);
	idt_set_gate(3, (uint32_t)isr_3, KERNEL_CS, 0);
	
	idt_set_gate(4, (uint32_t)isr_4, KERNEL_CS, 0);
	idt_set_gate(5, (uint32_t)isr_5, KERNEL_CS, 0);
	idt_set_gate(6, (uint32_t)isr_6, KERNEL_CS, 0);
	idt_set_gate(7, (uint32_t)isr_7, KERNEL_CS, 0);
	
	idt_set_gate(8, (uint32_t)isr_8, KERNEL_CS, 0);

	idt_set_gate(10, (uint32_t)isr_10, KERNEL_CS, 0);
	idt_set_gate(11, (uint32_t)isr_11, KERNEL_CS, 0);
	
	idt_set_gate(12, (uint32_t)isr_12, KERNEL_CS, 0);
	idt_set_gate(13, (uint32_t)isr_13, KERNEL_CS, 0);
	idt_set_gate(14, (uint32_t)isr_14, KERNEL_CS, 0);

	
	idt_set_gate(16, (uint32_t)isr_16, KERNEL_CS, 0);
	idt_set_gate(17, (uint32_t)isr_17, KERNEL_CS, 0);
	idt_set_gate(18, (uint32_t)isr_18, KERNEL_CS, 0);
	idt_set_gate(19, (uint32_t)isr_19, KERNEL_CS, 0);


	/* init other idt*/
	idt_set_gate(33, (uint32_t)keyboard_handler, KERNEL_CS, 0);	//init keyboard 33	
	idt_set_gate(40, (uint32_t)rtc_handler, KERNEL_CS, 0);		//init rtc 40
	
	/*macro to load the idtr*/
	printf("Finished setting ISR\n");
}






