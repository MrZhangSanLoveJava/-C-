#include "function.h"

int main(){
	/*
	1.while��ѭ��
	2.do...while��ѭ��
	*/
	char user_input;
	Student student[N];
	do{
		 //������ǰ��ӡһ�²˵�
		 menu();
		 scanf("%d", &user_input);
		 //�ж��û�������
		 //if�ж� �ж�һ����Χ
		 //switch�ж� �ж�ȷ��ֵ
		 switch(user_input){
		 case 1:
			 //¼��ɼ�
			 EnterGrades(student);
			 break;
		 case 2:
			 //��ӡ�ɼ�
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
			 printf("�˳��ɹ���\n");
			 break;
		 default:
			 printf("�����ѡ�񲻴���\n");
			 break;
		 }
	}while(user_input != 0);//������䣬���� ��0����1��0����0
	return 1;
}