#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <stdio.h>

#define N 30

//�����ṹ��
typedef struct Student{
	int id;			//ѧ��
	float score;	//�ɼ�
	char level;		//�ȼ�
}Student;

//��������
void menu();
void EnterGrades(Student*);
void PrintGrades(Student*);
void QueryGrades(Student*);
void AverageScore(Student*);
void MaxMinScore(Student*);
void CollectScore(Student*);

#endif