#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include "model/Board.cc"
// #include "Board.h" // Assuming you have a Board class header
#include "model/Player.cc" // Assuming you have a Player class header
#include "model/PlayingPieceX.cc" // Assuming you have a PlayingPieceX class header
#include "model/PlayingPieceO.cc" // Assuming you have a PlayingPieceO class header
using namespace std;

class TicTacToeGame {
public:
    std::deque<Player> players;
    Board* gameBoard = new Board(3);

public:
    TicTacToeGame(){
        
    }
    void initializeGame() {
        // Creating 2 Players
        players.clear();
        PlayingPieceX* crossPiece;
        Player player1("Player1", crossPiece);

        PlayingPieceO* noughtsPiece;
        Player player2("Player2", noughtsPiece);

        players.push_back(player1);
        players.push_back(player2);

        // Initialize the board
      //  gameBoard = new Board(3);
    }

    std::string startGame() {
        bool noWinner = true;
        while (noWinner) {
            // Take out the player whose turn it is and also put the player back in the queue
            Player playerTurn = players.front();
            players.pop_front();

            // Get the free spaces from the board
            gameBoard->printBoard();
            std::vector<std::pair<int, int>> freeSpaces = gameBoard->getFreeCells();
            if (freeSpaces.empty()) {
                noWinner = false;
                continue;
            }

            // Read user input
            cout << "Player: " << playerTurn.getName() << " Enter row,column: ";
            int inputRow, inputColumn;
            cin >> inputRow >> inputColumn;
            cout<<inputRow << " " << inputColumn<<endl;
            // Place the piece
            bool pieceAddedSuccessfully = gameBoard->addPiece(inputRow, inputColumn, playerTurn.getPlayingPiece());
            if (!pieceAddedSuccessfully) {
                // Player cannot insert the piece into this cell; player has to choose another cell
                std::cout << "Incorrect position chosen, try again" << std::endl;
                players.push_front(playerTurn);
                continue;
            }
            players.push_back(playerTurn);

            bool winner = isThereWinner(inputRow, inputColumn, playerTurn.getPlayingPiece()->pieceType);
            if (winner) {
                return playerTurn.getName();
            }
        }

        return "tie";
    }

    bool isThereWinner(int row, int column, PieceType pieceType) {
        bool rowMatch = true;
        bool columnMatch = true;
        bool diagonalMatch = true;
        bool antiDiagonalMatch = true;

        // Need to check in row
        for (int i = 0; i < 3; i++) {
            if (gameBoard->board[row][i] == nullptr || gameBoard->board[row][i]->pieceType != pieceType) {
                rowMatch = false;
            }
        }

        // Need to check in column
        for (int i = 0; i < 3; i++) {
            if (gameBoard->board[i][column] == nullptr || gameBoard->board[i][column]->pieceType != pieceType) {
                columnMatch = false;
            }
        }

        // Need to check diagonals
        for (int i = 0, j = 0; i < 3; i++, j++) {
            if (gameBoard->board[i][j] == nullptr || gameBoard->board[i][j]->pieceType != pieceType) {
                diagonalMatch = false;
            }
        }

        // Need to check anti-diagonals
        for (int i = 0, j = 2; i < 3; i++, j--) {
            if (gameBoard->board[i][j] == nullptr || gameBoard->board[i][j]->pieceType!= pieceType) {
                antiDiagonalMatch = false;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
    }
};

