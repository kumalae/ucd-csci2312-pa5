//
// Created by User on 12/10/15.
//

#include "Piece.h"

namespace Gaming {
    unsigned int Piece::__idGen = 0;

    Piece::Piece(const Game &g, const Position &p) : __game(g), __position(p), __finished(false), __turned(true) {}

    Piece::~Piece() {
        __id = 0;
        __finished = true;
        __turned = true;
    }

    std::ostream &operator<<(std::ostream &os, const Piece &piece) {
        piece.print(os);

        return os;
    }
}
