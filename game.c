#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘-空格
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			printf("|");
		}
		printf("\n");
		if (i < col - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				printf("|");
			}
			printf("\n");
		}
	}
	printf("\n\n\n");
}

void PlayerMove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家走>\n");
	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && x <= col)//判断坐标合法性
		{
			if (board[x - 1][y - 1] == ' ')//玩家输入的是位置，要转化为数组位置
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)//电脑下棋
{
	printf("电脑走:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
			if (board[x][y] == ' ')//电脑是余数算出来的，不用再-1
			{
				board[x][y] = '#';
				break;
			}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)//判断胜负
//1.玩家赢了 - *
//2.电脑赢了 - #
//3.平局 - Q
//4.游戏继续 - C
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 0; i < row; i++)//行
	{
		count = 0;
		for (j = 0; j < col-1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
			{
				count++;
				if (count == col - 1)
				{
					return board[i][j];
				}
			}
			else
			{
				break;
			}
		}
	}

	for (j = 0; j < col; j++)//列
	{
		count = 0;
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i][j] != ' ')
			{
				count++;
				if (count == row - 1)
				{
					return board[i][j];
				}
			}
			else
			{
				break;
			}
		}
	}

	count = 0;
	for (i = 0; i < row-1; i++)//对角线1
	{
		if (board[i][i] == board[i+1][i+1] && board[i][i] != ' ')
		{
			count++;
			if (count == row - 1)
			{
				return board[i][i];
			}
		}
		else
		{
			break;
		}
	}

	count = 0;
	for (i = 0, j = col - 1; i < row - 1; i++, j--)//对角线2
	{
		if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
		{
			count++;
			if (count == row - 1)
			{
				return board[i][j];
			}
		}
		else
		{
			break;
		}
	}
	
	int ret = IsFull(board, row, col);//判断棋盘是否已满
	if (ret)
	{
		return 'Q';
	}
	return 'C';
}
