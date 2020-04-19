#define _CRT_SECURE_NO_WARNINGS
//��Ϸʵ��ģ��
#include"game.h"
//��ʼ��������������Ϣ
void InitBoard(char board[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =set;//����дΪ��set��
		}
	}
}
//��ӡ������Ϣ
void DisPlay(char board[ROWS][COLS], int row, int col)
{
	//��ӡ�к�
	for (int i = 0; i<=col;i++)
	{
		printf("%d ",i);//��ӡ�к�������
	}
	printf("\n");//��ӡһ�л���
	for (int i = 1;i<=row; i++)//��ӡ�ڼ���
	{
		////��ӡn�е�����
		////��ӡ�кţ�����һ��
		printf("%d ",i);
		for (int j = 1;j<=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//'0 ' - '0'=0
//'3' - '0'=3

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count =EASY_COUNT;
	//˼·��������������10���ף�������ֻ����[1][1]-[9][9]�в��ã�����i��jȡ1-9�������������һ����count
	while (count)
	{
		int i = rand() % row + 1;//�����%9=0-8��rand����ʹ����Ҫ����srand����ֻ��Ҫһ��
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
		
			board[i][j] = '1';
			count--;
		}
		
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
//ɨ��
//˼·�����������������[9][9]֮��,1.���ף���ը������Ϸ��������ӡ���̣�2.�����ף���ӡ��Χ�׵ĸ���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x= 0;
	int y= 0;
	int win = 0;
	//����
	//81-10=71�������������71��֮��ɨ�׳ɹ�
	while (win<row*col-EASY_COUNT)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >=1 && x <= row &&y >=1 && y <= col)
		{
			//1.����
			if (mine[x][y] == '1')
			{
				printf("��ը������Ϸ����\n");
				DisPlay(mine, row, col);
				break;
			}
			//2.������
			else
			{
				//����������Χ�׵ĸ���
				int count = get_mine_count(mine, x, y);
				//ͳ����show���棬����ӡ
				show[x][y] = count + '0';
				DisPlay(show,row,col);//��ӡshow����
				win++;
			}
		}
		else
		{
			printf("�������겻�Ϸ�\n");
		}
		if (win == row*col - EASY_COUNT)
		{ 
			printf("��ϲ�����׳ɹ�\n");
			DisPlay(mine, row, col);
		}
	}

}