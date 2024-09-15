/*
 ============================================================================
 Name        : single_LL.c
 Author      : Giovanny Hany
 Description : single linked list
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_type.h"
#include "linked_list.h"

LL_t *LL_Head1=NULL;

int main(void)
{
	LL_insert_at_begin(&LL_Head1,11);
	LL_display_data(LL_Head1);
	LL_insert_at_begin(&LL_Head1,12);
	LL_display_data(LL_Head1);
	LL_insert_at_begin(&LL_Head1,13);
	LL_display_data(LL_Head1);
	LL_insert_at_begin(&LL_Head1,14);
	LL_display_data(LL_Head1);

	LL_middle_val(LL_Head1);

	LL_reverse1(&LL_Head1);
	printf("\nreverse 1:");
	LL_display_data(LL_Head1);

	LL_reverse2(&LL_Head1);
	printf("reverse 2:");
	LL_display_data(LL_Head1);

	LL_rotate_left(&LL_Head1,2);
	printf("rotate:");
	LL_display_data(LL_Head1);

	LL_NodeFromEnd(LL_Head1,3);

	LL_Sort(&LL_Head1);
	printf("sorted:");
	LL_display_data(LL_Head1);

	printf("=============================================================================\n");
	LL_insert_at_end(LL_Head1,10);
	LL_display_data(LL_Head1);
	LL_insert_at_end(LL_Head1,9);
	LL_display_data(LL_Head1);
	LL_insert_at_end(LL_Head1,8);
	LL_display_data(LL_Head1);

	LL_middle_val(LL_Head1);

	LL_reverse1(&LL_Head1);
	printf("\nreverse 1:");
	LL_display_data(LL_Head1);

	LL_reverse2(&LL_Head1);
	printf("reverse 2:");
	LL_display_data(LL_Head1);

	LL_rotate_left(&LL_Head1,4);
	printf("rotate:");
	LL_display_data(LL_Head1);

	LL_NodeFromEnd(LL_Head1,20);

	LL_Sort(&LL_Head1);
	printf("sorted:");
	LL_display_data(LL_Head1);

	printf("=============================================================================\n");
	LL_insert_after(LL_Head1,100,1);
	LL_display_data(LL_Head1);
	LL_insert_after(LL_Head1,99,3);
	LL_display_data(LL_Head1);
	LL_insert_after(LL_Head1,98,9);
	LL_display_data(LL_Head1);

	LL_middle_val(LL_Head1);

	LL_reverse1(&LL_Head1);
	printf("\nreverse 1:");
	LL_display_data(LL_Head1);

	LL_reverse2(&LL_Head1);
	printf("reverse 2:");
	LL_display_data(LL_Head1);

	LL_rotate_left(&LL_Head1,2);
	printf("rotate:");
	LL_display_data(LL_Head1);

	LL_Sort(&LL_Head1);
	printf("sorted:");
	LL_display_data(LL_Head1);
	printf("=============================================================================\n");
	LL_delete_at_begin(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_delete_at_begin(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_delete_at_begin(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_middle_val(LL_Head1);
	printf("=============================================================================\n");
	LL_delete_at_end(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_delete_at_end(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_delete_at_end(&LL_Head1);
	LL_display_data(LL_Head1);
	LL_middle_val(LL_Head1);
	printf("=============================================================================\n");
	LL_delete_after(&LL_Head1,2);
	LL_display_data(LL_Head1);
	LL_delete_after(&LL_Head1,1);
	LL_display_data(LL_Head1);
	LL_delete_after(&LL_Head1,1);
	LL_display_data(LL_Head1);
	LL_middle_val(LL_Head1);

	return EXIT_SUCCESS;
}
