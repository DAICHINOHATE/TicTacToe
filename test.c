#include"game.h"

void menu()
{
	printf("**********************************************\n");
	printf("*************      1.play      ***************\n");
	printf("*************      0.exit      ***************\n");
	printf("**********************************************\n");
}

void game()
{
	char board[ROW][COL];//棋盘为二维数组
	InitBoard(board, ROW, COL);//初始化棋盘-空格
    DisplayBoard(board, ROW, COL);//打印棋盘
	char ret = 0;//接受游戏状态
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);//判断胜负
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
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
		default :
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
