#include <string>
#include "PlayingPiece.cc" // Assuming you have a PlayingPiece class header
using namespace std;

class Player {
public:
    string name;
    PlayingPiece playingPiece;

    Player(const string& name, PlayingPiece playingPiece) : name(name), playingPiece(playingPiece) {}

    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    PlayingPiece getPlayingPiece() const{
        return playingPiece;
    }

    void setPlayingPiece(PlayingPiece newPlayingPiece) {
        playingPiece = newPlayingPiece;
    }
};
