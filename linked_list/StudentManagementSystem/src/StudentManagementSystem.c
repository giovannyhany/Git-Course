/*
 ============================================================================
 Name        : StudentManagementSystem.c
 Author      : giovanny hany
 Description : Student Management System
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Management.h"
#include "PlatformType.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	uint8 UserChoice=0;
	StudentData NewData;
	uint32 ID=0;
	float AVG_GPA=0;
	uint8 Terminate=0;
	while(Terminate==0)
	{
		printf("1-Add a new student--->(Write 1)\n");
		printf("2-Display students--->(Write 2)\n");
		printf("3-Search for a student--->(Write 3)\n");
		printf("4-Update student information--->(Write 4)\n");
		printf("5-Calculate average GPA--->(Write 5)\n");
		printf("6-Find the highest GPA--->(Write 6)\n");
		printf("7-Delete a student--->(Write 7)\n");
		printf("8-Terminate--->(Write 8)\n");
		printf("------------------------------------------------------------\n");
		printf("choice:");
		scanf("%i",&UserChoice);

		switch(UserChoice)
		{
		case 1:
			printf("Enter your ID:");
			scanf("%i",&(NewData.ID));
			fflush(stdin);
			printf("Enter your Name:");
			scanf("%s",(NewData.Name));
			fflush(stdin);
			printf("Enter your age:");
			scanf("%i",&(NewData.Age));
			fflush(stdin);
			printf("Enter your GPA:");
			scanf("%f",&(NewData.GPA));
			fflush(stdin);
			AddStudent(&NewData);
			break;

		case 2:
			DisplayStudents();
			break;

		case 3:
			printf("Enter the ID you want to search:");
			scanf("%i",&ID);
			fflush(stdin);
			SearchStudentByID(ID);
			break;

		case 4:
			printf("Enter the ID of the student to update his/her information:");
			scanf("%i",&ID);
			fflush(stdin);
			UpdateStudent(ID);
			break;

		case 5:
			AVG_GPA=CalculateAverageGPA();
			printf("Average GPA=%0.2f\n",AVG_GPA);
			break;

		case 6:
			SearchHighestGPA();
			break;

		case 7:
			printf("Enter the ID of the student to delete his/her information:");
			scanf("%i",&ID);
			fflush(stdin);
			DeleteStudent(ID);
			break;

		case 8:
			Terminate=1;
			break;

		default:
			printf("Wrong choice!! PLease choose the proper case.\n");
			break;
		}

		printf("============================================================\n\n");
	}

	printf("\t\t\tThank you!!! \n");
	return EXIT_SUCCESS;
}
