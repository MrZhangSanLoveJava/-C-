#include "function.h"

void menu(){
	printf("===================\n");
	printf("|   ѧ������ϵͳ  |\n");
	printf("|   1.¼��ɼ�    |\n");
	printf("|   2.��ӡ�ɼ�    |\n");
	printf("|   3.��ѯ�ɼ�    |\n");
	printf("|   4.ƽ������    |\n");
	printf("|   5.������    |\n");
	printf("|   6.���ܳɼ�    |\n");
	printf("|   0.�˳�����    |\n");
	printf("===================\n");
}

//¼��ɼ�
//1.��ȡ�û�����
//2.���û���������������
//3.��ʲô�������д�� ��ֵ���д�� �ṹ����д�� �ṹ�������
/*
ÿһ��ѧ���ĳɼ�����ÿһ��ѧ���ĳɼ���Ž��ṹ���У������齫30��ѧ���Ľṹ���Ž�������
*/
void EnterGrades(Student* pa){
	int id = 1, flag;
	float score;
	Student student;
	for (id = 1; id <= 30; id++){
		student.id = id;
		do{
			do{
				printf("�������%d��ѧ���ĳɼ�:", id);
				//������Ͻ���
				flag = scanf("%f", &score); //��������������ȷ��1��0
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

//��ӡ�ɼ�
/*
����һ�½ṹ�����飬�ٱ����ṹ�������еĽṹ������ǲ��ǾͿ��Եõ�ѧ���ĳɼ�
*/
void PrintGrades(Student* pa){
	int i;
	printf("============================\n");
	printf("|          ѧ���ɼ�        |\n");
	printf("============================\n");
	printf("|  id  |  score  |  level  |\n");
	printf("----------------------------\n");
	for (i = 0; i <	N; i++){
		printf("|  %d  |  %.1f  |  %c  |\n", pa[i].id, pa[i].score, pa[i].level);
		printf("----------------------------\n");
	}
}

//��ѯѧ���ɼ�
/*
ѧ�������в�ѯѧ���ĳɼ�
����һ�����ѧ���б�
*/
void QueryGrades(Student* pa){
	int i, id, flag;
	do{
		printf("������ѧ����ѧ��:");
		flag = scanf("%d", &id);
		getchar();
	}while(flag == 0);
	for (i = 0; i < N; i++){
		if (pa[i].id == id){
			printf("============================\n");
			printf("|         ��ѯ�ɹ�         |\n");
			printf("============================\n");
			printf("|  id  |  score  |  level  |\n");
			printf("----------------------------\n");
			printf("|  %d  |  %f  |  %c  |\n", pa[i].id, pa[i].score, pa[i].level);
			printf("----------------------------\n");
			//ΪʲôҪ�˳�����
			/*
			1.��Լʱ��
			2.Ϊ�������ѯ������������̵�
			*/
			return;
		}
	}
	printf("============================\n");
	printf("|         ��ѯʧ��         |\n");
	printf("============================\n");
}

//����ȫ����ƽ���ֺͼ�����
/*
ƽ���ּ��㣺ȫ���ܷ��� / �༶����
�����ʣ��������� / �༶����
*/
void AverageScore(Student* pa){
	float sum = 0.0, avg, etcl;
	int i, etc = 0;
	for (i = 0; i < N; i++){
		sum += pa[i].score;
		if (pa[i].score >= 60.0){
			etc++; //������������
		}
	}
	avg = sum / N;
	etcl = (float)etc / N;
	printf("============================\n");
	printf("|       ƽ���ּ�����       |\n");
	printf("============================\n");
	printf("|   ƽ����   |    ������   |\n");
	printf("----------------------------\n");
	printf("|   %.2f    |     %.2f     |\n", avg, etcl);
	printf("----------------------------\n");
}

//�����߷���ͷ�
/*
������������������ֵ
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
	printf("|       ��߷���ͷ�       |\n");
	printf("============================\n");
	printf("|   ��߷�   |    ��ͷ�   |\n");
	printf("----------------------------\n");
	printf("|   %.2f    |     %.2f     |\n", max, min);
	printf("----------------------------\n");
}

//���ܸ��ȼ�����
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
	printf("|       ���ܸ����ȼ�       |\n");
	printf("============================\n");
	printf("|  A  |  B  |  C   |   D   |\n");
	printf("----------------------------\n");
	printf("|  %d  |  %d  |  %d  |  %d  |\n", A_sum, B_sum, C_sum, D_sum);
}