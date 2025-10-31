#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Move.hpp"
#include "Renderer.hpp"
#include <memory>

class GameEngine {
    Board  _board;
    Player _current{Player::X};
    std::unique_ptr<Renderer> _renderer; // smart pointer

public:
    GameEngine() = default;

    void   Init();
    Player Current() const { return _current; }
    bool   MakeMove(const Move& m);
    Player CheckWinner() const;
    bool   IsDraw() const;
    const Board& GetBoard() const { return _board; }

    // injectăm un renderer
    void SetRenderer(std::unique_ptr<Renderer> r) { _renderer = std::move(r); }
    Renderer* RendererPtr() { return _renderer.get(); }
};
