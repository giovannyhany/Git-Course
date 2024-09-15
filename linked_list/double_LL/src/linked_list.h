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

typedef struct DLL_st
{
	uint32 DLL_data;
	struct DLL_st *DLL_previous;
	struct DLL_st *DLL_next;
}DLL_t;

void DLL_insert_at_begin(DLL_t **Head,uint32 data);
void DLL_insert_at_end(DLL_t *Head,uint32 data);
void DLL_insert_after(DLL_t *Head,uint32 data,uint32 position);
void DLL_insert_before(DLL_t **Head,uint32 data,uint32 position);
void DLL_delete_at_begin(DLL_t **Head);
void DLL_delete_at_end(DLL_t **Head);
void DLL_delete_at_position(DLL_t **Head,uint32 position);
void DLL_reverse(DLL_t **Head);
void DLL_display_data(DLL_t *Head);
uint32 DLL_length(DLL_t *Head);

#endif /* LINKED_LIST_H_ */
