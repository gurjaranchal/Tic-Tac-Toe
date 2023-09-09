#include<iostream>
#include "TicTacToeGame.cc" 
using namespace std;

int main() { 
    TicTacToeGame* game = new TicTacToeGame();
    game->initializeGame();
    cout<< game->startGame() << std::endl;
    cout << "Game winner is: " <<endl;
    return 0;
}
