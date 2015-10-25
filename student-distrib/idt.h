#ifndef _IDT_H
#define _IDT_H

extern void idt_init();
extern void isr_set();
extern void
idt_set_gate(uint8_t vector, uint32_t base, uint16_t selector, uint8_t DPL);

// extern unsigned char code_set[0x59];



#endif