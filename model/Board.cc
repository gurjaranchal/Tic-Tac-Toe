#include <vector>
#include <utility>
#include <iostream>
#include "PlayingPiece.cc" // Assuming you have a PlayingPiece class header
using namespace std;
class Board {
public:
    int size;
    vector<vector<char>> board;

public:
    Board(int s){
        size = s;
        board.resize(s,vector<char>(s,' '));
    }

    bool addPiece(int row, int column, PlayingPiece playingPiece) {
        if (board[row][column] != ' ') {
            return false;
        }
        char player = 'X';
        if(playingPiece.pieceType ==PieceType::O){
            player = 'O';
        }
        board[row][column] = player;
        return true;
    }

    vector<pair<int, int>> getFreeCells() {
        vector<pair<int, int>> freeCells;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == ' ') {
                    freeCells.emplace_back(i, j);
                }
            }
        }

        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != ' ') {
                    cout << board[i][j] << "   ";
                } else {
                    cout << "    ";
                }
                cout << " | ";
            }
            cout << endl;
        }
    }
};
