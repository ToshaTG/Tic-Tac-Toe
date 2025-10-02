#include "GameEngine.hpp"

GameEngine::GameEngine() : _current(Player::X) {}

void GameEngine::Init() {
    _board.Reset();
    _current = Player::X;
}

Player GameEngine::Current() { return _current; }

bool GameEngine::MakeMove(const Move& m) {
    if (!_board.InBounds(m.row, m.col)) return false;
    if (!_board.IsEmpty(m.row, m.col))  return false;
    if (!_board.Place(m.row, m.col, _current)) return false;
    _current = (_current == Player::X ? Player::O : Player::X);
    return true;
}

Player GameEngine::CheckWinner() {
    auto same3 = [&](Player a, Player b, Player c){ return a!=Player::None && a==b && b==c; };

    for (int r=0; r<3; ++r) if (same3(_board.Get(r,0), _board.Get(r,1), _board.Get(r,2))) return _board.Get(r,0);
    for (int c=0; c<3; ++c) if (same3(_board.Get(0,c), _board.Get(1,c), _board.Get(2,c))) return _board.Get(0,c);
    if (same3(_board.Get(0,0), _board.Get(1,1), _board.Get(2,2))) return _board.Get(1,1);
    if (same3(_board.Get(0,2), _board.Get(1,1), _board.Get(2,0))) return _board.Get(1,1);
    return Player::None;
}

bool GameEngine::IsDraw() { return _board.IsFull() && CheckWinner()==Player::None; }

const Board& GameEngine::GetBoard() { return _board; }
