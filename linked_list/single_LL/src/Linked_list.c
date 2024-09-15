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

void LL_insert_at_end(LL_t *Head,uint32 data)
{
	LL_t *temp_node=NULL;
	LL_t *Tail=Head;
	if (Head==NULL)
	{
		printf("the list is empty is has no end\n");
	}
	else
	{
		temp_node=(LL_t *)malloc(sizeof(LL_t));
		if (temp_node==NULL)
		{
			printf("No space to allocate a new element at the end\n");
		}
		else
		{
			temp_node->LL_data=data;
			temp_node->LL_link=NULL;
			while(Tail->LL_link != NULL)
			{
				Tail=Tail->LL_link;
			}
			Tail->LL_link=temp_node;
		}
	}
}

void LL_insert_after(LL_t *Head,uint32 data,uint32 position)
{
	LL_t *temp_node=NULL;
	LL_t *count_position=Head;
	uint32 counter=LL_data_number(Head);
	if(position>counter || position<=0)
	{
		printf("incorrect position \n");
	}
	else
	{
		temp_node=(LL_t *)malloc(sizeof(LL_t));
		if (temp_node==NULL)
		{
			printf("No space to allocate a new element after required position\n");
		}
		else
		{
			while (position > 1)
			{
				count_position=count_position->LL_link;
				position--;
			}
			temp_node->LL_data=data;
			temp_node->LL_link=count_position->LL_link;
			count_position->LL_link=temp_node;
		}
	}
}

void LL_delete_at_begin(LL_t **Head)
{
	LL_t *temp_node=NULL;
	if (*Head==NULL)
	{
		printf("the list is empty no item to delete\n");
	}
	else if( (*Head)->LL_link == NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		temp_node=*Head;
		*Head = (temp_node)->LL_link;
		free(temp_node);
		temp_node=NULL;
	}
}

void LL_delete_at_end(LL_t **Head)
{
	LL_t *Before_Tail=*Head;
	LL_t *Tail=NULL;
	uint32 counter=LL_data_number(*Head);
	if (Head == NULL)
	{
		printf("the list is empty no item to delete\n");
	}
	else if (counter == 1)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(counter>2)
		{
			Before_Tail=Before_Tail->LL_link;
			counter--;
		}
		Tail=Before_Tail->LL_link;
		Before_Tail->LL_link=NULL;
		free(Tail);
		Tail=NULL;
	}
}

void LL_delete_after(LL_t **Head,uint32 position)
{
	LL_t *delete_node=NULL;
	LL_t *before_delete_node=*Head;
	uint32 counter=LL_data_number(*Head);
	if (Head == NULL)
	{
		printf("the list is empty no item to delete\n");
	}
	else if (position>counter || position<=0)
	{
		printf("incorrect position \n");
	}
	else if (counter==1)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while (position>1)
		{
			before_delete_node=before_delete_node->LL_link;
			position--;
		}
		delete_node=before_delete_node->LL_link;
		before_delete_node->LL_link=delete_node->LL_link;
		free(delete_node);
		delete_node=NULL;
	}
}

void LL_middle_val(LL_t *Head)
{
	if (Head==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		uint32 number=LL_data_number(Head);
		number=(number/2)+1;
		LL_t *temp=Head;
		while(number>1)
		{
			temp=temp->LL_link;
			number--;
		}
		printf("the middle val=%i\n",temp->LL_data);
	}

}

void LL_reverse1(LL_t **Head)
{
	uint32 number=LL_data_number(*Head);
	uint32 counter=0;
	LL_t *temp1=*Head;
	LL_t **ptr=NULL;
	if (Head==NULL)
	{
		printf("the list is empty\n");
	}
	else if(number==1)
	{

	}
	else
	{
		ptr=(LL_t **)calloc(number,sizeof(uint32 *));
		for(counter=0;counter<number;counter++)
		{
			ptr[counter]=temp1;
			temp1=temp1->LL_link;
		}
		temp1=*Head;
		for(counter=0;counter<number;counter++)
		{
			if(counter==0)
			{
				temp1->LL_link=NULL;
			}
			else
			{
				temp1->LL_link=ptr[counter-1];
			}
			if(counter!=number-1)
				temp1=ptr[counter+1];
		}
		*Head=ptr[counter-1];
		free(ptr);
	}
}

void LL_reverse2(LL_t **Head)
{
	LL_t *prev=NULL,*curr=*Head,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->LL_link;
		curr->LL_link=prev;
		prev=curr;
		curr=next;
	}
	*Head=prev;
}

void LL_rotate_left(LL_t **Head,uint32 RotNum)
{
	LL_t *Tail=*Head;
	LL_t *next=NULL;
	uint32 number=LL_data_number(*Head);
	if (Head==NULL)
	{
		printf("the list is empty\n");
	}
	else if(number==1)
	{

	}
	else
	{
		while(Tail->LL_link != NULL)
		{
			Tail=Tail->LL_link;
		}

		while(RotNum>0)
		{
			next=(*Head)->LL_link;
			Tail->LL_link=*Head;
			(*Head)->LL_link=NULL;
			Tail=Tail->LL_link;
			*Head=next;
			RotNum--;
		}
	}
}

void LL_NodeFromEnd(LL_t *Head,uint32 Num)
{
	LL_t *temp=Head;
	uint32 Length=LL_data_number(Head);
	if (Num > Length)
	{
		printf("The list doesn't contain that position\n");
	}
	else
	{
		uint32 move=Length-Num;
		while(move>0)
		{
			temp=temp->LL_link;
			move--;
		}
		printf("the Node (%i) is number %i from the end\n",temp->LL_data,Num);
	}

}

void LL_Sort(LL_t **Head)
{
	LL_t *temp=*Head;
	LL_t *Before_temp=NULL;
	LL_t *compare=(*Head)->LL_link;
	LL_t *compare_next=compare->LL_link;
	uint32 Length=LL_data_number(*Head);
	uint32 counter1=0,counter2=0;
	if (Head==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		for(counter1=0;counter1<Length-1;counter1++)
		{
			for(counter2=0;counter2<=counter1;counter2++)
			{
				if( counter2==0 && (temp->LL_data)>(compare->LL_data) )
				{
					while(temp->LL_link != compare )
					{
						temp=temp->LL_link;
					}
					temp->LL_link=compare->LL_link;
					compare->LL_link=*Head;
					*Head=compare;
					break;
				}
				else if ( (temp->LL_data)>(compare->LL_data) )
				{
					while(temp->LL_link != compare )
					{
						temp=temp->LL_link;
					}
					temp->LL_link=compare->LL_link;
					compare->LL_link=Before_temp->LL_link;
					Before_temp->LL_link=compare;
					break;
				}
				else
				{
					Before_temp=temp;
					temp=temp->LL_link;
				}
			}
			Before_temp=NULL;
			temp=*Head;
			compare=compare_next;
			if(compare != NULL)
				compare_next=compare->LL_link;
		}
	}
}

void LL_display_data(LL_t *Head)
{
	LL_t *temp_node=Head;
	if (Head==NULL)
	{
		printf("the list is empty no data can be displayed\n");
	}
	else
	{
		while (temp_node->LL_link != NULL)
		{
			printf("-> %i ",temp_node->LL_data);
			temp_node=temp_node->LL_link;
		}
		printf("-> %i -> NULL\n",temp_node->LL_data);
	}
}

uint32 LL_data_number(LL_t *Head)
{
	uint32 number=1;
	LL_t *temp_node=Head;
	if (Head==NULL)
	{
			number=0;
	}
	else
	{
		while (temp_node->LL_link != NULL)
		{
			temp_node=temp_node->LL_link;
			number++;
		}
	}
	return number;
}
