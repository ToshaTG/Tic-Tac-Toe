#include "Board.hpp"
#include <iostream>

Board::Board() { Reset(); }

Board::Board(Player fill) {
    for (int r=0;r<3;++r)
        for (int c=0;c<3;++c)
            _cells[r][c] = fill;
}

Board::Board(const Board& other) {
    for (int r=0;r<3;++r)
        for (int c=0;c<3;++c)
            _cells[r][c] = other._cells[r][c];
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        for (int r=0;r<3;++r)
            for (int c=0;c<3;++c)
                _cells[r][c] = other._cells[r][c];
    }
    return *this;
}

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
    for (int r=0; r<3; ++r)
        for (int c=0; c<3; ++c)
            if (_cells[r][c] == Player::None) return false;
    return true;
}

bool Board::operator==(const Board& other) const {
    for (int r=0;r<3;++r)
        for (int c=0;c<3;++c)
            if (_cells[r][c] != other._cells[r][c]) return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Board& b) {
    for (int r=0;r<3;++r) {
        for (int c=0;c<3;++c) {
            Player p = b._cells[r][c];
            char ch = (p==Player::X?'X':p==Player::O?'O':'.');
            os << ch << (c<2 ? ' ' : '\n');
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Board& b) {
    for (int r=0;r<3;++r) {
        for (int c=0;c<3;++c) {
            char ch;
            if (!(is >> ch)) return is;
            if (ch=='X'||ch=='x') b._cells[r][c]=Player::X;
            else if (ch=='O'||ch=='o'||ch=='0') b._cells[r][c]=Player::O;
            else b._cells[r][c]=Player::None;
        }
    }
    return is;
}
