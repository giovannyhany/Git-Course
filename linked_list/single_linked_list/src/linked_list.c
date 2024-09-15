/*
 * linked_list.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Giovanny
 */
#include <stdio.h>
#include <stdlib.h>
#include "platform_type.h"
#include "linked_list.h"

void LL_insert_at_begin(LL_t **Head,uint32 data)
{
	LL_t *temp_node=NULL;
	if (Head==NULL)
	{
		printf("NULL is passed to LL_insert_at_begin function\n");
	}
	else
	{
		temp_node=(LL_t *)malloc(sizeof(LL_t));
		if (temp_node==NULL)
		{
			printf("No space to allocate a new element at the begin\n");
		}
		else
		{
			temp_node->LL_data=data;
			temp_node->LL_link=*Head;
			*Head=temp_node;
		}
	}
}

void LL_insert_at_end(LL_t *Head,uint32 data)
{

}

void LL_insert_after(LL_t **Head,uint32 data,uint32 position)
{

}

void LL_delete_at_begin(LL_t **Head)
{

}

void LL_delete_at_end(LL_t *Head)
{

}

void LL_delete_after(LL_t **Head,uint32 data,uint32 position)
{

}

void LL_display_data(LL_t *Head)
{
	LL_t *temp_node=Head;
	if (Head==NULL)
	{
		printf("NULL is passed to LL_display_data function\n");
	}
	else
	{
		while (temp_node->LL_link != NULL)
		{
			printf("-> %i ",temp_node->LL_data);
			temp_node=temp_node->LL_link;
		}
		printf("-> %i -> NULL ",temp_node->LL_data);
	}
}

uint32 LL_data_number(LL_t *Head)
{
	uint32 number=0;



	return number;
}

