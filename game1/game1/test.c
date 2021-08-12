#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include <stdio.h>

//测试三子棋游戏

void menu()
{
	printf("**********************************\n");
	printf("**********1.play  0.exit**********\n");
	printf("**********************************\n");
}

void game()
{
	//创建一个数组，存放玩家和计算机走出的棋盘信息
	//数组内全是空格
	char board[ROW][COL] = { 0 };
	char ret = 0;

	//init board
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//计算机下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
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
			printf("选择有误，请重新选择。\n");
			break;
		}
	} while (input);//非0重新循环
}

int main()
{
	test();

	return 0;
}