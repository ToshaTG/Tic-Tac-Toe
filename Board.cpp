#include "Board.hpp"

Board::Board() { Reset(); }

void Board::Reset() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            _cells[r][c] = Player::None;
}

bool Board::InBounds(int r, int c) const {
    return r >= 0 && r < 3 && c >= 0 && c < 3;
}

Player Board::Get(int r, int c) const {
    return InBounds(r, c) ? _cells[r][c] : Player::None;
}

bool Board::IsEmpty(int r, int c) const {
    return InBounds(r, c) && _cells[r][c] == Player::None;
}

bool Board::Place(int r, int c, Player p) {
    if (!InBounds(r, c) || !IsEmpty(r, c)) return false;
    _cells[r][c] = p;
    return true;
}

bool Board::IsFull() const {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (_cells[r][c] == Player::None) return false;
    return true;
}
