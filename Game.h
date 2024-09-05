#ifndef _GAME_H
#define _GAME_H

#include "Board.h"

#define BOARD_SIZE 10
#define ANTI_PLAYER(anti_player) (3-(anti_player))//相手プレイヤー

class Game{
    private:
    int playerID = 1;
    Board myboard;
    int checkBoard_search(int x, int y, int a, int b, int playerID);

    public:
    int x,y;
    void play();
    void setStone(int playerID);
    bool checkStone(int x, int y,int playerID);
    int checkBoard(int x, int y, int playerID);
    void isWinner();
    bool isGameContinue(int playerID);
    void showWinner(int playerID);
    void changePlayer();
    void turnoverStone(int x, int y, int playerID);
    Game();
};
#endif