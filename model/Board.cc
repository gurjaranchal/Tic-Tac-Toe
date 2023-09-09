#include <vector>
#include <utility>
#include <iostream>
#include "PlayingPiece.cc" // Assuming you have a PlayingPiece class header

class Board {
public:
    int size;
    std::vector<std::vector<PlayingPiece*>> board;

public:
    Board(int s){
        size = s;
        board.resize(s, std::vector<PlayingPiece*>(size, nullptr));
    }

    bool addPiece(int row, int column, PlayingPiece* playingPiece) {
        if (board[row][column] != nullptr) {
            return false;
        }
        board[row][column] = playingPiece;
        return true;
    }

    std::vector<std::pair<int, int>> getFreeCells() {
        std::vector<std::pair<int, int>> freeCells;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == nullptr) {
                    freeCells.emplace_back(i, j);
                }
            }
        }

        return freeCells;
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != nullptr) {
                    if(board[i][j]->pieceType == PieceType::X)
                    std::cout << "X" << "   ";
                    else 
                    std::cout << "O" << "   ";
                } else {
                    std::cout << "    ";
                }
                std::cout << " | ";
            }
            std::cout << std::endl;
        }
    }
};
