#include <stdio.h>
#include <iostream>
#include <cstdio>

#include "Game.h"
#include "Board.h"

Game::Game() {
}

void Game::play(){
    int res;
    myboard.Initializ_Board();
    myboard.showBoard();

    while(1){
        setStone(playerID);
        myboard.showBoard();
        res=isGameContinue(ANTI_PLAYER(playerID));
        if(res==1){
            playerID=ANTI_PLAYER(playerID);
        }else{
            std::cout << "player" << ANTI_PLAYER(playerID) << "の置く場所がありません" << std::endl;
            if(isGameContinue(playerID)==0){
                isWinner();
                break;
            }
        }
    }
}

void Game::setStone(int playerID){
    char inputChar;
    do{
        std::cout << "player" << playerID << "の番です" << std::endl;
        std::cout << "置く場所を入力" << std::endl;
        std::cout << "縦>";
        std::cin >> x;
        std::cout << "横>" ;
        std::cin >> y;
    }while(checkStone(x,y,playerID));//return0
    board[x][y]=playerID;
    turnoverStone(x,y,playerID);
}

void Game::turnoverStone(int x, int y, int playerID){
    int res;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            res=checkBoard_search(x,y,i,j,playerID);
            if(res>0){
                for(int k=0;k<=res;k++){
                    board[x+i*k][y+j*k]=playerID;//石をひっくり返す処理
                }
            }
        }
    }
}

bool Game::checkStone(int x, int y, int playerID){
    int res;
    if(board[x][y] != 0){
        std::cout << "すでに石があります" << std::endl;
        return 1;
    }

    res=checkBoard(x,y,playerID);
    return res;
}

int Game::checkBoard(int x, int y, int playerID){
    int res;
    int count;

    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            res=checkBoard_search(x,y,i,j, playerID);
            count=count+res;
        }
    }

    if(count>0){
        return 0;//ひっくり返せる
    }
    return 1;//
}

int Game::checkBoard_search(int x, int y, int a, int b, int playerID){
    int canset = 0;

    // ループしながら相手の石を見つける
    for (int i = 1; ; i++) {
        int newX = x + i * a;
        int newY = y + i * b;

        // 境界チェック：ボードの外に出たら終了
        if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
            return 0;
        }

        // 相手の駒がある場合
        if (board[newX][newY] == ANTI_PLAYER(playerID)) {
            canset++;
        }
        // 自分の駒がある場合
        else if (board[newX][newY] == playerID) {
            return canset; // 相手の駒を挟んでいるので確定
        }
        // 空の場所、またはそれ以外の場合
        else {
            return 0; // 挟めないので終了
        }
    }
}
//プレイヤーに置く場所があるかどうか
bool Game::isGameContinue(int playerID){
    int res;
    for(int i=1;i<BOARD_SIZE-1;i++){
        for(int j=1;j<BOARD_SIZE-1;j++){
            res=checkBoard(i,j,playerID);
            if(res==0){
                return 1;//ゲームを続ける
            }
        }
    }
    return 0;
}

void Game::isWinner(){
    int player_one;
    int player_second;

    for(int i=1;i<BOARD_SIZE-1;i++){
        for(int j=1;j<BOARD_SIZE-1;j++){
            if(board[i][j] = 1){
                player_one++;
            }
            if(board[i][j] = 2){
                player_second++;
            }
        }
    }

    if(player_one>player_second){
        std::cout << "player1の勝利です" << std::endl;
    }
    else if(player_one<player_second){
        std::cout << "player2の勝利です" << std::endl;
    }
    else if(player_one==player_second){
         std::cout << "引き分けです" << std::endl;
    }
}
