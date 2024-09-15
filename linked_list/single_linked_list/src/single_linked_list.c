/*
 ============================================================================
 Name        : single_linked_list.c
 Author      : Giovanny Hany
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_type.h"
#include "linked_list.h"

LL_t *LL_Head1;

int main(void) {

	LL_insert_at_begin(&LL_Head1,11);
	LL_display_data(LL_Head1);
	LL_insert_at_begin(&LL_Head1,12);
	LL_display_data(LL_Head1);

	return EXIT_SUCCESS;
}
