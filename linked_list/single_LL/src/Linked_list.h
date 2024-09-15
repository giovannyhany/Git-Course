/*
 * linked_list.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Giovanny
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "platform_type.h"

typedef struct LL_st
{
	uint32 LL_data;
	struct LL_st *LL_link;
}LL_t;

void LL_insert_at_begin(LL_t **Head,uint32 data);
void LL_insert_at_end(LL_t *Head,uint32 data);
void LL_insert_after(LL_t *Head,uint32 data,uint32 position);
void LL_delete_at_begin(LL_t **Head);
void LL_delete_at_end(LL_t **Head);
void LL_delete_after(LL_t **Head,uint32 position);
void LL_middle_val(LL_t *Head);
void LL_reverse1(LL_t **Head);
void LL_reverse2(LL_t **Head);
void LL_rotate_left(LL_t **Head,uint32 RotNum);
void LL_NodeFromEnd(LL_t *Head,uint32 Num);
void LL_Sort(LL_t **Head);//using insertion sort
void LL_display_data(LL_t *Head);
uint32 LL_data_number(LL_t *Head);

#endif /* LINKED_LIST_H_ */
