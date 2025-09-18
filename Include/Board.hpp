#pragma once
#include "player.hpp"
#include "move.hpp"

class Board {
    Player _cells[3][3];
public:
    Board();
    void Reset();
    bool InBounds(int r, int c);
    Player Get(int r, int c);
    bool IsEmpty(int r, int c);
    bool Place(int r, int c, Player p); 
    bool IsFull();
};
