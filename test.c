#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
//������Ϸ
//
void menu() 
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}
void game()
{
	//printf("ɨ��\n");//����һ�µ�ǰ�����Ƿ��д��󼴿�
	//����Ϣ������
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = {0};
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = {0};
	//��ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show ,ROWS, COLS,'*');
	//��ӡ
//	DisPlay(mine, ROW, COL);
	DisPlay(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
    DisPlay(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}
	} while (input);
}
int main()
{
	test();//������Ϸ
	return 0;
}