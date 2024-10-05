/*
 * Management.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Giovanny
 */
#include <stdio.h>
#include <stdlib.h>
#include "Management.h"
#include "PlatformType.h"

StudentList *Head=NULL;

void AddStudent(const StudentData *const Ptr)
{
	StudentList *NewData=NULL;
	StudentList *temp=Head;
	uint8 found=0;
	if (Head==NULL)
	{
		NewData=(StudentList *)malloc(sizeof(StudentList));
		if (NewData==NULL)
		{
				printf("ERROR!! there isn't enough space to add new student\n");
		}
		else
		{
			(NewData->Data).ID=Ptr->ID;
			for (int i=0;i<50;i++)
				(NewData->Data).Name[i]=Ptr->Name[i];
			(NewData->Data).Age=Ptr->Age;
			(NewData->Data).GPA=Ptr->GPA;
			NewData->Next=NULL;
			Head=NewData;
			printf("\t\tData added successfully :)\n");
		}
	}

	else
	{
		while (temp->Next != NULL)
		{
			if ((temp->Data).ID==Ptr->ID)
			{
				found=1;
				break;
			}
			else
			{
				temp=temp->Next;
			}
		}

		if ((temp->Data).ID==Ptr->ID)//to check ID value at last element
			found=1;

		if (found==0)
		{
			NewData=(StudentList *)malloc(sizeof(StudentList));
			if (NewData==NULL)
			{
				printf("ERROR!! there isn't enough space to add new student\n");
			}
			else
			{
				(NewData->Data).ID=Ptr->ID;
				for (int i=0;i<50;i++)
					(NewData->Data).Name[i]=Ptr->Name[i];
				(NewData->Data).Age=Ptr->Age;
				(NewData->Data).GPA=Ptr->GPA;
				NewData->Next=NULL;
				temp->Next=NewData;
				printf("\t\tData added successfully :)\n");
			}
		}
		else
		{
			printf("ERROR!! the ID you entered is repeated\n");
		}
	}
}

void DisplayStudents(void)
{
	StudentList *temp=Head;
	uint16 i=1;
	if(Head==NULL)
	{
		printf("There isn't any student yet\n");
	}
	else
	{
		while(temp->Next != NULL)
		{
			printf("student %i-> ID:%i   ",i,temp->Data.ID);
			printf("Name:%s   ",temp->Data.Name);
			printf("Age:%i   ",temp->Data.Age);
			printf("GPA:%0.2f\n",temp->Data.GPA);
			i++;
			if (temp->Next != NULL)
				temp=temp->Next;
		}

		printf("student %i-> ID:%i   ",i,temp->Data.ID);
		printf("Name:%s   ",temp->Data.Name);
		printf("Age:%i   ",temp->Data.Age);
		printf("GPA:%0.2f\n",temp->Data.GPA);
	}
}

void SearchStudentByID(int ID)
{
	StudentList *temp=Head;
	uint8 found=0;
	if(Head==NULL)
	{
		printf("There isn't any student yet\n");
	}
	else
	{
		while (temp->Next != NULL)
		{
			if ((temp->Data).ID==ID)
			{
				found=1;
				break;
			}
			else
			{
				temp=temp->Next;
			}
		}

		if ((temp->Data).ID==ID)//to check ID value at last element
			found=1;

		if (found==1)
		{
			printf("ID:%i   ",temp->Data.ID);
			printf("Name:%s   ",temp->Data.Name);
			printf("Age:%i   ",temp->Data.Age);
			printf("GPA:%0.2f\n",temp->Data.GPA);
		}
		else
		{
			printf("Student with that ID isn't found\n");
		}
	}
}

void UpdateStudent(int ID)
{
	StudentList *temp=Head;
	uint8 found=0;
	if(Head==NULL)
	{
		printf("There isn't any student yet\n");
	}
	else
	{
		while (temp->Next != NULL)
		{
			if ((temp->Data).ID==ID)
			{
				found=1;
				break;
			}
			else
			{
				temp=temp->Next;
			}
		}

		if ((temp->Data).ID==ID)//to check ID value at last element
			found=1;

		if (found==1)
		{
			printf("Enter the new Name:");
			scanf("%s",(temp->Data).Name);
			fflush(stdin);
			printf("Enter the new age:");
			scanf("%i",&(temp->Data).Age);
			fflush(stdin);
			printf("Enter the new GPA:");
			scanf("%f",&(temp->Data).GPA);
			fflush(stdin);
			printf("\t\tData changed successfully :)\n");
		}
		else
		{
			printf("Student with that ID isn't found\n");
		}
	}
}

float CalculateAverageGPA(void)
{
	StudentList *temp=Head;
	float GPA_Sum=0;
	uint16 StudentNum=1;
	if(Head==NULL)
	{
		printf("There isn't any student yet\n");
	}
	else
	{
		while (temp->Next != NULL)
		{
			GPA_Sum+=(temp->Data).GPA;
			temp=temp->Next;
			StudentNum++;
		}
		GPA_Sum+=(temp->Data).GPA;
	}

	return GPA_Sum/StudentNum;
}

void SearchHighestGPA(void)
{
	StudentList *temp=Head;
	float max=(temp->Data).GPA;
	if(Head==NULL)
	{
		printf("There isn't any student yet\n");
	}
	else
	{
		while (temp->Next != NULL)
		{
			if((temp->Data).GPA>max)
				max=(temp->Data).GPA;
			temp=temp->Next;
		}
		if((temp->Data).GPA>max)
			max=(temp->Data).GPA;

		temp=Head;

		while (temp->Next != NULL)
		{
			if((temp->Data).GPA==max)
			{
				printf("ID:%i   ",temp->Data.ID);
				printf("Name:%s   ",temp->Data.Name);
				printf("Age:%i   ",temp->Data.Age);
				printf("GPA:%0.2f\n",temp->Data.GPA);
			}
			temp=temp->Next;
		}
		if((temp->Data).GPA==max)
		{
			printf("ID:%i   ",temp->Data.ID);
			printf("Name:%s   ",temp->Data.Name);
			printf("Age:%i   ",temp->Data.Age);
			printf("GPA:%0.2f\n",temp->Data.GPA);
		}
	}
}

void DeleteStudent(int ID)
{
	StudentList *tempReq=Head;
	StudentList *tempBeforeReq=Head;
	uint8 begin=0;
	uint8 found=0;
	if(Head==NULL)
	{
		printf("There isn't any student to delete\n");
	}
	else
	{
		while (tempReq->Next != NULL)
		{
			if ((tempReq->Data).ID==ID)
			{
				found=1;
				break;
			}
			else
			{
				tempReq=tempReq->Next;
				begin++;
				if (begin>1)
					tempBeforeReq=tempBeforeReq->Next;
			}
		}
		if ((tempReq->Data).ID==ID)
			found=1;

		if(tempReq==Head && found==1)
		{
			Head=tempReq->Next;
			free(tempReq);
		}
		else if(found==1)
		{
			tempBeforeReq->Next=tempReq->Next;
			free(tempReq);
		}
		else
		{
			printf("Student with that ID isn't found\n");
		}
	}
}
