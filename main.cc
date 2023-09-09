#include<iostream>
#include "TicTacToeGame.cc" 
using namespace std;

int main() { 
    TicTacToeGame* game = new TicTacToeGame();
    game->initializeGame();
    game->startGame();
    return 0;
}
