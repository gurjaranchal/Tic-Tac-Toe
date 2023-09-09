#include "PieceType.cc" // Assuming you have a PieceType class or enum
#pragma once
using namespace std;

class PlayingPiece {
public:
    PieceType pieceType;

    PlayingPiece(PieceType pieceType) : pieceType(pieceType) {}
  
};
