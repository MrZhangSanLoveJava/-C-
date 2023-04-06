#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <stdio.h>

#define N 30

//创建结构体
typedef struct Student{
	int id;			//学号
	float score;	//成绩
	char level;		//等级
}Student;

//函数声明
void menu();
void EnterGrades(Student*);
void PrintGrades(Student*);
void QueryGrades(Student*);
void AverageScore(Student*);
void MaxMinScore(Student*);
void CollectScore(Student*);

#endif