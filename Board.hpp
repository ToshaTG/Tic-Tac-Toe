#pragma once
#include "Player.hpp"
#include "Move.hpp"

class Board {
    Player _cells[3][3];
public:
    Board();
    void   Reset();
    bool   InBounds(int r, int c) const;
    Player Get(int r, int c) const;
    bool   IsEmpty(int r, int c) const;
    bool   Place(int r, int c, Player p);
    bool   IsFull() const;
};
