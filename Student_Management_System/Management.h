/*
 * Management.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Giovanny
 */

#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_
#include "PlatformType.h"

typedef struct Student
{
	int ID;
	char Name[50];
	int Age;
	float GPA;
}StudentData;

typedef struct node
{
	StudentData Data;
	struct node *Next;
}StudentList;


void AddStudent(const StudentData *const Ptr);
void DisplayStudents(void);
void SearchStudentByID(int ID);
void UpdateStudent(int ID);
float CalculateAverageGPA(void);
void SearchHighestGPA(void);
void DeleteStudent(int ID);


#endif /* MANAGEMENT_H_ */
