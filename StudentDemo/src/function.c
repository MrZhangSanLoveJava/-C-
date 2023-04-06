#include "function.h"

void menu(){
	printf("===================\n");
	printf("|   学生管理系统  |\n");
	printf("|   1.录入成绩    |\n");
	printf("|   2.打印成绩    |\n");
	printf("|   3.查询成绩    |\n");
	printf("|   4.平均及格    |\n");
	printf("|   5.最高最低    |\n");
	printf("|   6.汇总成绩    |\n");
	printf("|   0.退出程序    |\n");
	printf("===================\n");
}

//录入成绩
//1.获取用户输入
//2.将用户的输入存入变量中
//3.用什么变量进行存放 数值进行存放 结构体进行存放 结构体加数组
/*
每一个学生的成绩，将每一个学生的成绩存放进结构体中，用数组将30个学生的结构体存放进数组中
*/
void EnterGrades(Student* pa){
	int id = 1, flag;
	float score;
	Student student;
	for (id = 1; id <= 30; id++){
		student.id = id;
		do{
			do{
				printf("请输入第%d个学生的成绩:", id);
				//程序的严谨性
				flag = scanf("%f", &score); //如果输入的内容正确，1，0
				getchar();
			}while(flag != 1);
		}while (score < 0 || score > 100);
		student.score = score;
		if (score <= 100 && score >= 90)
			student.level = 'A';
		else if (score >= 80 && score < 90)
			student.level = 'B';
		else if (score >= 60 && score < 80)
			student.level = 'C';
		else
			student.level = 'D';
		pa[id - 1] = student;
	}
}

//打印成绩
/*
遍历一下结构体数组，再遍历结构体数组中的结构体变量是不是就可以得到学生的成绩
*/
void PrintGrades(Student* pa){
	int i;
	printf("============================\n");
	printf("|          学生成绩        |\n");
	printf("============================\n");
	printf("|  id  |  score  |  level  |\n");
	printf("----------------------------\n");
	for (i = 0; i <	N; i++){
		printf("|  %d  |  %.1f  |  %c  |\n", pa[i].id, pa[i].score, pa[i].level);
		printf("----------------------------\n");
	}
}

//查询学生成绩
/*
学号来进行查询学生的成绩
遍历一下这个学生列表
*/
void QueryGrades(Student* pa){
	int i, id, flag;
	do{
		printf("请输入学生的学号:");
		flag = scanf("%d", &id);
		getchar();
	}while(flag == 0);
	for (i = 0; i < N; i++){
		if (pa[i].id == id){
			printf("============================\n");
			printf("|         查询成功         |\n");
			printf("============================\n");
			printf("|  id  |  score  |  level  |\n");
			printf("----------------------------\n");
			printf("|  %d  |  %f  |  %c  |\n", pa[i].id, pa[i].score, pa[i].level);
			printf("----------------------------\n");
			//为什么要退出函数
			/*
			1.节约时间
			2.为了下面查询不到的输出做铺垫
			*/
			return;
		}
	}
	printf("============================\n");
	printf("|         查询失败         |\n");
	printf("============================\n");
}

//计算全部的平均分和及格率
/*
平均分计算：全班总分数 / 班级人数
及格率：及格人数 / 班级人数
*/
void AverageScore(Student* pa){
	float sum = 0.0, avg, etcl;
	int i, etc = 0;
	for (i = 0; i < N; i++){
		sum += pa[i].score;
		if (pa[i].score >= 60.0){
			etc++; //求出及格的人数
		}
	}
	avg = sum / N;
	etcl = (float)etc / N;
	printf("============================\n");
	printf("|       平均分及格率       |\n");
	printf("============================\n");
	printf("|   平均分   |    及格率   |\n");
	printf("----------------------------\n");
	printf("|   %.2f    |     %.2f     |\n", avg, etcl);
	printf("----------------------------\n");
}

//输出最高分最低分
/*
定义两个变量，并给值
*/
void MaxMinScore(Student* pa){
	float max = 0, min = pa[0].score;
	int i;
	for (i = 0; i < N; i++){
		if (max < pa[i].score)
			max = pa[i].score;
		else if (min > pa[i].score)
			min = pa[i].score;
	}
	printf("============================\n");
	printf("|       最高分最低分       |\n");
	printf("============================\n");
	printf("|   最高分   |    最低分   |\n");
	printf("----------------------------\n");
	printf("|   %.2f    |     %.2f     |\n", max, min);
	printf("----------------------------\n");
}

//汇总各等级人数
void CollectScore(Student* pa){
	int i, A_sum= 0, B_sum = 0, C_sum = 0, D_sum = 0;
	for (i = 0; i < N; i++){
		if (pa[i].level == 'A')
			A_sum++;
		else if (pa[i].level == 'B')
			B_sum++;
		else if (pa[i].level == 'C')
			C_sum++;
		else
			D_sum++;
	}
	printf("============================\n");
	printf("|       汇总各个等级       |\n");
	printf("============================\n");
	printf("|  A  |  B  |  C   |   D   |\n");
	printf("----------------------------\n");
	printf("|  %d  |  %d  |  %d  |  %d  |\n", A_sum, B_sum, C_sum, D_sum);
}