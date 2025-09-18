#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Move.hpp"

class GameEngine {
    Board  _board;
    Player _current;
public:
    GameEngine();
    void   Init();                
    Player Current();            
    bool   MakeMove(const Move& m);
    Player CheckWinner();        
    bool   IsDraw();
    const Board & GetBoard();
};
