#include <stdio.h>
#include <iostream>
#include <cstdio>

#include "Game.h"
#include "Board.h"

Game::Game() {
}

void Game::play(){
    int res;
    myboard.showBoard();

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
    int res=0;
    int count;

    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            res=checkBoard_search(x,y,i,j, playerID);
            if(res>0){//
                for(int k=0;k<=res;k++){
                    board[x+i*res][y+j*res]=playerID;//石をひっくり返す処理
                }
            }
            res=0;
            count=count+res;
        }
    }

    if(count>0){
        return 0;//石をひっくり返した
    }
    return 1;//
}

int Game::checkBoard_search(int x, int y, int a, int b, int playerID){
    int canset=0;
    
    for(int i=1; board[x+i*a][y+i*b] == ANTI_PLAYER(playerID); i++){//PlayerIDの石がある場所までループ
        canset=canset+1;
    }
    return canset;
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
