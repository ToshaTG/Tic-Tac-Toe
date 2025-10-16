#pragma once
#include "Renderer.hpp"
#include <iostream>

class ConsoleRenderer : public Renderer {
public:
    void DrawBoard(const Board& b) override;
    void DrawTurn(Player p) override;
    void AnnounceWinner(Player p) override;
    void AnnounceDraw() override;
    void WriteText(const std::string& text) override;
};
