#define _CRT_SECURE_NO_WARNINGS
//游戏实现模块
#include"game.h"
//初始化布置雷棋盘信息
void InitBoard(char board[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =set;//不能写为‘set’
		}
	}
}
//打印棋牌信息
void DisPlay(char board[ROWS][COLS], int row, int col)
{
	//打印列号
	for (int i = 0; i<=col;i++)
	{
		printf("%d ",i);//打印列号用整形
	}
	printf("\n");//打印一行换行
	for (int i = 1;i<=row; i++)//打印第几行
	{
		////打印n行的内容
		////打印列号，加上一列
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

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count =EASY_COUNT;
	//思路，在棋盘上设置10个雷，布置雷只需在[1][1]-[9][9]中布置，布置i，j取1-9的随机数，布置一个雷count
	while (count)
	{
		int i = rand() % row + 1;//随机数%9=0-8，rand函数使用需要调用srand，且只需要一次
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
//扫雷
//思路，玩家输入棋盘坐标[9][9]之内,1.是雷，被炸死，游戏结束，打印雷盘，2.不是雷，打印周围雷的个数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x= 0;
	int y= 0;
	int win = 0;
	//是雷
	//81-10=71个非雷区，完成71次之后扫雷成功
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >=1 && x <= row &&y >=1 && y <= col)
		{
			//1.是雷
			if (mine[x][y] == '1')
			{
				printf("被炸死，游戏结束\n");
				DisPlay(mine, row, col);
				break;
			}
			//2.不是雷
			else
			{
				//遍历坐标周围雷的个数
				int count = get_mine_count(mine, x, y);
				//统计在show上面，并打印
				show[x][y] = count + '0';
				DisPlay(show,row,col);//打印show棋盘
				win++;
			}
		}
		else
		{
			printf("输入坐标不合法\n");
		}
		if (win == row*col - EASY_COUNT)
		{ 
			printf("恭喜你排雷成功\n");
			DisPlay(mine, row, col);
		}
	}

}