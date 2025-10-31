#include "GameEngine.hpp"
#include <array>

void GameEngine::Init() {
    _board.Reset();
    _current = Player::X;
}

bool GameEngine::MakeMove(const Move& m) {
    if (!_board.InBounds(m.row, m.col)) return false;
    if (!_board.IsEmpty(m.row, m.col))  return false;
    if (!_board.Place(m.row, m.col, _current)) return false;
    _current = (_current == Player::X ? Player::O : Player::X);
    return true;
}

Player GameEngine::CheckWinner() const {
    auto same3 = [&](int r0,int c0,int r1,int c1,int r2,int c2)->Player{
        const Player a = _board.Get(r0,c0);
        if (a==Player::None) return Player::None;
        return (a==_board.Get(r1,c1) && a==_board.Get(r2,c2)) ? a : Player::None;
    };

    for (int r=0; r<3; ++r) if (auto w = same3(r,0,r,1,r,2); w!=Player::None) return w;
    for (int c=0; c<3; ++c) if (auto w = same3(0,c,1,c,2,c); w!=Player::None) return w;
    if (auto w = same3(0,0,1,1,2,2); w!=Player::None) return w;
    if (auto w = same3(0,2,1,1,2,0); w!=Player::None) return w;

    return Player::None;
}

bool GameEngine::IsDraw() const { return _board.IsFull() && CheckWinner()==Player::None; }
