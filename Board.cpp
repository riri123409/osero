#include <stdio.h>
#include <iostream>
#include "Board.h"

#define BOARD_SIZE 10

int board[BOARD_SIZE][BOARD_SIZE] = {0};  // グローバル変数の定義と初期化

void Board::Initializ_Board(){
    for(int i=0;i<BOARD_SIZE;i++){
        board[0][i] = -1;
        board[i][0] = -1;
        board[i][BOARD_SIZE] = -1;
        board[BOARD_SIZE][i] = -1;
    }
    board[4][5] = board[5][4] = 1;
    board[4][4] = board[5][5] = 2;
}

void Board::showBoard(){
    printf("    1  2  3  4  5  6  7  8");
    printf("\n");
    for(int i = 1; i < BOARD_SIZE-1; i++)
    {
        printf("%d |", i);
        for(int j = 1; j < BOARD_SIZE-1; j++)
        {
            switch (board[i][j])
            {
            case -1:
                printf(" -1");
                break;

            case 0:
                printf("  |");
                break;

            case 1:
                printf(" ○|");
                break;

            case 2:
                printf(" ●|");
                break;
            }
           //printf("board[%d][%d]=%d\n",i,j,board[i][j]);
        }
        printf("\n");
        printf("---------------------------");
        printf("\n");
    }
}