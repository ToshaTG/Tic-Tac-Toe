#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include <string>

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void DrawBoard(const Board& b) = 0;
    virtual void DrawTurn(Player p) = 0;
    virtual void AnnounceWinner(Player p) = 0;
    virtual void AnnounceDraw() = 0;
    virtual void WriteText(const std::string& text) = 0;
};
