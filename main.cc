#include<iostream>
#include "TicTacToeGame.cc" 
// Assuming you have a TicTacToeGame class header
using namespace std;
int main() { 
    TicTacToeGame* game = new TicTacToeGame();
    game->initializeGame();
    std::cout<< game->startGame() << std::endl;
    cout << "Game winner is: " <<endl;
    return 0;
}
