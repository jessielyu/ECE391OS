/* 
 * Paging.h
 * ECE391OS Fall 2015
 * Group: Yeliangchen
 * Member: Boyu Li, Xiaoyi Chen, Jiexin Lyu, Yujia Dong
 * Paging by: Jiexin Lyu
 */

#ifndef _PAGING_H
#define _PAGING_H


#include "types.h"
#include "x86_desc.h"


/* 
 * page_table_entry struct
 */
typedef union page_table_entry
{
        uint32_t val;
        struct {
                uint32_t present : 1;
                uint32_t read_write : 1;
                uint32_t user_supervisor : 1;
                uint32_t write_through : 1;
                uint32_t cache_disabled : 1;
                uint32_t accessed : 1;
                uint32_t dirty : 1;
                uint32_t page_table_attribute_index : 1;
                uint32_t global_page : 1;
                uint32_t available : 3;
                uint32_t page_base_address : 20;
        } __attribute__((packed));
}page_table_entry;


/* 
 * page_directory_entry struct
 */
typedef union page_directory_entry
{
        uint32_t val;
        struct {
                uint32_t present : 1;
                uint32_t read_write : 1;
                uint32_t user_supervisor : 1;
                uint32_t write_through : 1;
                uint32_t cache_disabled : 1;
                uint32_t accessed : 1;
                uint32_t reserved : 1;
                uint32_t size : 1;
                uint32_t global_page : 1;
                uint32_t available : 3;
                uint32_t page_base_address : 20;
        } __attribute__((packed));
}page_direc_entry;
 
void init_paging();

#endif
