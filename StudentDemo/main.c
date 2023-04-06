#include "function.h"

int main(){
	/*
	1.while死循环
	2.do...while死循环
	*/
	char user_input;
	Student student[N];
	do{
		 //在输入前打印一下菜单
		 menu();
		 scanf("%d", &user_input);
		 //判断用户的输入
		 //if判断 判断一个范围
		 //switch判断 判断确定值
		 switch(user_input){
		 case 1:
			 //录入成绩
			 EnterGrades(student);
			 break;
		 case 2:
			 //打印成绩
			 PrintGrades(student);
			 break;
		 case 3:
			 QueryGrades(student);
			 break;
		 case 4:
			 AverageScore(student);
			 break;
		 case 5:
			 MaxMinScore(student);
			 break;
		 case 6:
			 CollectScore(student);
			 break;
		 case 0:
			 printf("退出成功！\n");
			 break;
		 default:
			 printf("输入的选择不存在\n");
			 break;
		 }
	}while(user_input != 0);//条件语句，整数 非0就是1，0就是0
	return 1;
}