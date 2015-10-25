/* 
 *  Paging.c
 *  ECE391OS Fall 2015
 *  Group: Yeliangchen
 *  Member: Boyu Li, Xiaoyi Chen, Jiexin Lyu, Yujia Dong
 *  Paging by: Jiexin Lyu
 */


#include "Paging.h"
#include "lib.h"


#define VID_INDEX 184
#define CR0 0x80000001
 
page_direc_entry page_directory[1024] __attribute__((aligned (0x1000))) = {{0}};
page_table_entry page_table_1[1024] __attribute__((aligned (0x1000))) = {{0}};


/*
 *  init_paging()
 *  Inputs: none
 *  Outputs: none
 *  Description: 
 *      This function will initialize paging. This function creates a page directory and
 *      sets the first two page directory entries to be memory blocks for the kernel space 
 *      and video memory. Kernel space is one large 4MB block, and video memory will be 
 *      divided into 4kB blocks. The blocks are organized in page table at the bottom which 
 *      loops through the 1024 address locations and sets the page_base_address to their 
 *      location in memory. Then at the end, we use inline assembly to set the paging 
 *      registers in memory.
 */
void init_paging()
{
    int i = 0;
    int j = 0;
    uint32_t address = 0x00000000;

    (page_directory[0]).page_base_address = ((uint32_t)page_table_1 >> 12); 
    (page_directory[0]).read_write = 1;
    (page_directory[0]).user_supervisor = 0;
    (page_directory[0]).write_through = 0;
    (page_directory[0]).cache_disabled = 0;
    (page_directory[0]).accessed = 0;
    (page_directory[0]).reserved = 0;
    (page_directory[0]).size = 0;                   
    (page_directory[0]).global_page = 0;
    (page_directory[0]).available = 0;
       
    (page_directory[1]).page_base_address = 0x400;
    (page_directory[1]).present = 1;
    (page_directory[1]).read_write = 1;
    (page_directory[1]).user_supervisor = 0;
    (page_directory[1]).write_through = 0;
    (page_directory[1]).cache_disabled = 0;
    (page_directory[1]).accessed = 0;
    (page_directory[1]).reserved = 0;
    (page_directory[1]).size = 1;                   
    (page_directory[1]).global_page = 0;
    (page_directory[1]).available = 0;
       
    for(i=2; i<1024; i++) {
        (page_directory[i]).present = 0;
        (page_directory[i]).page_base_address = 0x0;
        (page_directory[i]).read_write = 0;
        (page_directory[i]).user_supervisor = 0;
        (page_directory[i]).write_through = 0;
        (page_directory[i]).cache_disabled = 0;
        (page_directory[i]).accessed = 0;
        (page_directory[i]).reserved = 0;
        (page_directory[i]).size = 0;                   
        (page_directory[i]).global_page = 0;
        (page_directory[i]).available = 0;
               
        }
    
    /* initialize page table */   
    for(j=0; j<1024; j++) {
        (page_table_1[j]).present = 0;
        (page_table_1[j]).page_base_address = (address >> 12);
        (page_table_1[j]).read_write = 1;
        (page_table_1[j]).user_supervisor = 1;
        (page_table_1[j]).write_through = 0;
        (page_table_1[j]).cache_disabled = 0;
        (page_table_1[j]).accessed = 0;
        (page_table_1[j]).dirty = 0;
        (page_table_1[j]).page_table_attribute_index = 0;
        (page_table_1[j]).global_page = 0;
        (page_table_1[j]).available = 0;
               
        address += 0x1000;
    }

    (page_table_1[VID_INDEX]).present = 1;

    /* use inline assembly to setup the page registers */           
    asm volatile("movl %cr4, %eax");
    asm volatile("movl $0x00000010, %eax");
    asm volatile("movl %eax, %cr4");       
    asm volatile("mov %0, %%cr3":: "r"(page_directory):"cc", "eax");
    asm volatile("mov %0, %%cr0":: "r"(CR0):"cc", "eax");

    return;
}
