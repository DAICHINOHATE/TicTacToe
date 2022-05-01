#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘-空格
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘-本质上是打印数组
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋
char IsWin(char board[ROW][COL], int row, int col);//判断胜负
//1.玩家赢了 - *
//2.电脑赢了 - #
//3.平局 - Q
//4.游戏继续 - C
