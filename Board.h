#ifndef _BOARD_H_
#define _BOARD_H_

#define BOARD_SIZE 10

extern int board[BOARD_SIZE][BOARD_SIZE];

class Board{
    public:
    void showBoard();
    void Initializ_Board();
};
#endif