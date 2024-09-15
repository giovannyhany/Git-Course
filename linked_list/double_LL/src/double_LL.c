/*
 ============================================================================
 Name        : double_LL.c
 Author      : givanny hany
 Description : double linked list
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "platform_type.h"

DLL_t *DLL1=NULL;

int main(void) {

	DLL_insert_at_begin(&DLL1,11);
	DLL_display_data(DLL1);
	DLL_insert_at_begin(&DLL1,12);
	DLL_display_data(DLL1);
	DLL_insert_at_begin(&DLL1,13);
	DLL_display_data(DLL1);

	DLL_reverse(&DLL1);
	printf("reverse: ");
	DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_insert_at_end(DLL1,10);
	DLL_display_data(DLL1);
	DLL_insert_at_end(DLL1,9);
	DLL_display_data(DLL1);
	DLL_insert_at_end(DLL1,8);
	DLL_display_data(DLL1);

	DLL_reverse(&DLL1);
	printf("reverse: ");
	DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_insert_after(DLL1,100,1);
	DLL_display_data(DLL1);
	DLL_insert_after(DLL1,99,3);
	DLL_display_data(DLL1);
	DLL_insert_after(DLL1,98,8);
	DLL_display_data(DLL1);
	DLL_insert_after(DLL1,97,9);
	DLL_display_data(DLL1);
	DLL_reverse(&DLL1);
		printf("reverse: ");
		DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_insert_before(&DLL1,500,3);
	DLL_display_data(DLL1);
	DLL_insert_before(&DLL1,600,6);
	DLL_display_data(DLL1);
	DLL_insert_before(&DLL1,50,1);
	DLL_display_data(DLL1);
	DLL_insert_before(&DLL1,60,1);
	DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_delete_at_begin(&DLL1);
	DLL_display_data(DLL1);
	DLL_delete_at_begin(&DLL1);
	DLL_display_data(DLL1);
	DLL_delete_at_begin(&DLL1);
	DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_delete_at_end(&DLL1);
	DLL_display_data(DLL1);
	DLL_delete_at_end(&DLL1);
	DLL_display_data(DLL1);
	DLL_delete_at_end(&DLL1);
	DLL_display_data(DLL1);
	printf("========================================================\n");
	DLL_delete_at_position(&DLL1,1);
	DLL_display_data(DLL1);
	DLL_delete_at_position(&DLL1,2);
	DLL_display_data(DLL1);
	DLL_delete_at_position(&DLL1,6);
	DLL_display_data(DLL1);

	return EXIT_SUCCESS;
}
