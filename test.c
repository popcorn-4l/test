#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include <stdio.h>

//������������Ϸ

void menu()
{
	printf("**********************************\n");
	printf("**********1.play  0.exit**********\n");
	printf("**********************************\n");
}

void game()
{
	//����һ�����飬�����Һͼ�����߳���������Ϣ
	//������ȫ�ǿո�
	char board[ROW][COL] = { 0 };
	char ret = 0;

	//init board
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//���������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("ѡ������������ѡ��\n");
			break;
		}
	} while (input);//��0����ѭ��
}

int main()
{
	test();

	return 0;
}