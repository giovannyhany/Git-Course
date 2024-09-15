/*
 * linked_list.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Giovanny
 */

#ifndef LINKED_LIST_C_
#define LINKED_LIST_C_
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "platform_type.h"

void DLL_insert_at_begin(DLL_t **Head,uint32 data)
{
	DLL_t *temp_node=NULL;
	temp_node=(DLL_t *)malloc(sizeof(DLL_t));
	if(temp_node==NULL)
	{
		printf("There isn't enough space to add a new value in the linked list\n");
	}
	else if (*Head==NULL)
	{
		temp_node->DLL_previous=NULL;
		temp_node->DLL_data=data;
		temp_node->DLL_next=NULL;
		*Head=temp_node;
	}
	else
	{
		temp_node->DLL_data=data;
		temp_node->DLL_previous=NULL;
		temp_node->DLL_next=*Head;
		(*Head)->DLL_previous=temp_node;//if Head==NULL i can't get it's previous
		*Head=temp_node;
	}
}

void DLL_insert_at_end(DLL_t *Head,uint32 data)
{
	DLL_t *temp_node=NULL;
	if (Head==NULL)
	{
		printf("the linked list is empty it has no end\n");
	}
	else
	{
		temp_node=(DLL_t *)malloc(sizeof(DLL_t));
		if(temp_node==NULL)
		{
			printf("There isn't enough space to add a new value in the linked list\n");
		}
		else
		{
			while(Head->DLL_next != NULL)
			{
				Head=Head->DLL_next;
			} //Head becomes Tail
			temp_node->DLL_data=data;
			temp_node->DLL_previous=Head;
			temp_node->DLL_next=NULL;
			Head->DLL_next=temp_node;
		}
	}
}

void DLL_insert_after(DLL_t *Head,uint32 data,uint32 position)
{
	uint32 length=DLL_length(Head);
	DLL_t *temp_node=NULL;
	DLL_t *position_node=Head;
	if (position>length || position<=0)
	{
		printf("incorrect position\n");
	}
	else
	{
		temp_node=(DLL_t *)malloc(sizeof(DLL_t));
		if(temp_node==NULL)
		{
			printf("There isn't enough space to add a new value in the linked list\n");
		}
		else
		{
			while(position>1)
			{
				position_node=position_node->DLL_next;
				position--;
			}
			temp_node->DLL_data=data;
			temp_node->DLL_previous=position_node;
			temp_node->DLL_next=position_node->DLL_next;
			if (position_node->DLL_next != NULL)//in case the position isn't the end
			{
				(position_node->DLL_next)->DLL_previous=temp_node;
			}
			else
			{
				/* nothing */
			}
			position_node->DLL_next=temp_node;
		}
	}
}

void DLL_insert_before(DLL_t **Head,uint32 data,uint32 position)
{
	uint32 length=DLL_length(*Head);
	DLL_t *temp_node=NULL;
	DLL_t *position_node=*Head;
	if (position>length || position<=0)
	{
		printf("incorrect position\n");
	}
	else
	{
		temp_node=(DLL_t *)malloc(sizeof(DLL_t));
		if(temp_node==NULL)
		{
			printf("There isn't enough space to add a new value in the linked list\n");
		}
		else
		{
			while(position>1)
			{
				position_node=position_node->DLL_next;
				position--;
			}
			temp_node->DLL_data=data;
			temp_node->DLL_previous=position_node->DLL_previous;
			temp_node->DLL_next=position_node;
			if (position_node->DLL_previous != NULL)//in case the position isn't the begin
			{
				(position_node->DLL_previous)->DLL_next=temp_node;
			}
			else // in case position==1 (the begin)
			{
				*Head=temp_node;
			}
			position_node->DLL_previous=temp_node;
		}
	}
}

void DLL_delete_at_begin(DLL_t **Head)
{
	DLL_t *temp_node=*Head;
	uint32 length=DLL_length(*Head);
	if(*Head==NULL)
	{
		printf("the list is empty no values to delete\n");
	}
	else if(length==1)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->DLL_next;
		(*Head)->DLL_previous==NULL;
		free(temp_node);
		temp_node=NULL;
	}
}

void DLL_delete_at_end(DLL_t **Head)
{
	DLL_t *temp_node=*Head;
	uint32 length=DLL_length(*Head);
	if(*Head==NULL)
	{
		printf("the list is empty no values to delete\n");
	}
	else if(length == 1)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(temp_node->DLL_next != NULL)
		{
			temp_node=temp_node->DLL_next;
		}
		(temp_node->DLL_previous)->DLL_next=NULL;
		free(temp_node);
		temp_node=NULL;
	}
}

void DLL_delete_at_position(DLL_t **Head,uint32 position)
{
	DLL_t *temp_node=*Head;
	uint32 length=DLL_length(*Head);
	if( position>length || position <= 0)
	{
		printf("incorrect position\n");
	}
	else if (position==1 && length==1)
	{
		free(*Head);
		*Head=NULL;
	}
	else if (position==1 && length!=1)
	{
		*Head=(*Head)->DLL_next;
		(*Head)->DLL_previous==NULL;
		free(temp_node);
		temp_node=NULL;
	}
	else if (length == position)
	{
		while(temp_node->DLL_next != NULL)
		{
			temp_node=temp_node->DLL_next;
		}
		(temp_node->DLL_previous)->DLL_next=NULL;
		free(temp_node);
		temp_node=NULL;
	}
	else
	{
		while (position>1)
		{
			temp_node=temp_node->DLL_next;
			position--;
		}
		(temp_node->DLL_previous)->DLL_next=temp_node->DLL_next;
		(temp_node->DLL_next)->DLL_previous=temp_node->DLL_previous;
		free(temp_node);
		temp_node=NULL;
	}
}

void DLL_reverse(DLL_t **Head)
{
	DLL_t *temp=*Head;
	DLL_t *temp_address=NULL;
	uint32 length=DLL_length(*Head);
	if(*Head==NULL)
	{
		printf("the list is empty\n");
	}
	else if (length==1)
	{

	}
	else
	{
		while(length>0)
		{
			temp_address=temp->DLL_previous;
			temp->DLL_previous=temp->DLL_next;
			temp->DLL_next=temp_address;

			if(length!=1)
				temp=temp->DLL_previous;
			length--;
		}
		*Head=temp;
	}
}

void DLL_display_data(DLL_t *Head)
{
	if(Head==NULL)
	{
		printf("The linked list is empty no data can be displayed \n");
	}
	else
	{
		while(Head->DLL_next != NULL)
		{
			printf("-> %i ",Head->DLL_data);
			Head=Head->DLL_next;
		}
		printf("-> %i -> NULL \n",Head->DLL_data);
	}
}

uint32 DLL_length(DLL_t *Head)
{
	uint32 ret_val=1;
	if (Head==NULL)
	{
		ret_val=0;
	}
	else
	{
		while (Head->DLL_next != NULL)
		{
			Head=Head->DLL_next;
			ret_val++;
		}
	}
	return ret_val;
}

#endif /* LINKED_LIST_C_ */
