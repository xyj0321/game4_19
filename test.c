#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
//测试游戏
//
void menu() 
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}
void game()
{
	//printf("扫雷\n");//测试一下当前代码是否有错误即可
	//雷信息的设置
	//1.布置好雷的信息
	char mine[ROWS][COLS] = {0};
	//2.排查出雷的信息
	char show[ROWS][COLS] = {0};
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show ,ROWS, COLS,'*');
	//打印
//	DisPlay(mine, ROW, COL);
	DisPlay(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
    DisPlay(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择");
			break;
		}
	} while (input);
}
int main()
{
	test();//测试游戏
	return 0;
}