#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include "model/Board.cc"
#include "model/Player.cc" // Assuming you have a Player class header
#include "model/PlayingPieceX.cc" // Assuming you have a PlayingPieceX class header
#include "model/PlayingPieceO.cc" // Assuming you have a PlayingPieceO class header
using namespace std;

class TicTacToeGame {
public:
    deque<Player> players;
    Board* gameBoard = new Board(3);

public:
    TicTacToeGame(){
        
    }
    void initializeGame() {
        // Creating 2 Players
        players.clear();
        PlayingPieceX crossPiece;
        Player player1("Player1", crossPiece);

        PlayingPieceO noughtsPiece;
        Player player2("Player2", noughtsPiece);

        players.push_back(player1);
        players.push_back(player2);
    }

    void startGame() {
        bool noWinner = true;
        while (noWinner) {
            // Take out the player whose turn it is and also put the player back in the queue
            Player playerTurn = players.front();
            players.pop_front();

            // Get the free spaces from the board
            gameBoard->printBoard();
            vector<pair<int, int>> freeSpaces = gameBoard->getFreeCells();
            if (freeSpaces.empty()) {
                noWinner = false;
                continue;
            }

            cout << "Player: " << playerTurn.getName() << " Enter row and column: ";
            int inputRow, inputColumn;
            cin >> inputRow >> inputColumn;

            // Place the piece
            bool pieceAddedSuccessfully = gameBoard->addPiece(inputRow, inputColumn, playerTurn.getPlayingPiece());
            if (!pieceAddedSuccessfully) {
                // Player cannot insert the piece into this cell; player has to choose another cell
                cout << "Incorrect position chosen, try again" << std::endl;
                players.push_front(playerTurn);
                continue;
            }
            players.push_back(playerTurn);
            bool winner = isThereWinner(inputRow, inputColumn, playerTurn.getPlayingPiece().pieceType);
            if (winner) {
                cout<<"Game Winner is: "<<playerTurn.getName();
                return;
            }
        }

        cout<<"Game Tie!!! ";
    }

    bool isThereWinner(int row, int column, PieceType pieceType) {
        bool rowMatch = true;
        bool columnMatch = true;
        bool diagonalMatch = true;
        bool antiDiagonalMatch = true;

        char player;
        if(pieceType == PieceType::X){
            player='X';
        }else {
            player ='O';
        }

        // Need to check in row
        for (int i = 0; i < 3; i++) {
            if (gameBoard->board[row][i] == ' ' || gameBoard->board[row][i] != player) {
                rowMatch = false;
            }
        }

        // Need to check in column
        for (int i = 0; i < 3; i++) {
            if (gameBoard->board[i][column] == ' ' || gameBoard->board[i][column] != player) {
                columnMatch = false;
            }
        }

        // Need to check forward diagonals
        for (int i = 0, j = 0; i < 3; i++, j++) {
            if (gameBoard->board[i][j] == ' '|| gameBoard->board[i][j] !=player) {
                diagonalMatch = false;
            }
        }

        // Need to check backward diagonals
        for (int i = 0, j = 2; i < 3; i++, j--) {
            if (gameBoard->board[i][j] == ' ' || gameBoard->board[i][j] != player) {
                antiDiagonalMatch = false;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
    }
};

