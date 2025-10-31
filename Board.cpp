#include "Board.hpp"
#include <algorithm>
#include <iostream>

Board::Board() { Reset(); }

Board::Board(Player fill) {
    for (auto& row : _cells) row.fill(fill);
}

void Board::Reset() {
    for (auto& row : _cells) row.fill(Player::None);
}

bool Board::InBounds(int r, int c) const {
    return r >= 0 && r < 3 && c >= 0 && c < 3;
}

Player Board::Get(int r, int c) const {
    return InBounds(r,c) ? _cells[static_cast<size_t>(r)][static_cast<size_t>(c)] : Player::None;
}

bool Board::IsEmpty(int r, int c) const {
    return InBounds(r,c) && _cells[static_cast<size_t>(r)][static_cast<size_t>(c)] == Player::None;
}

bool Board::Place(int r, int c, Player p) {
    if (!InBounds(r,c) || !IsEmpty(r,c)) return false;
    _cells[static_cast<size_t>(r)][static_cast<size_t>(c)] = p;
    return true;
}

bool Board::IsFull() const {
    return std::all_of(_cells.begin(), _cells.end(), [](const Row& row){
        return std::all_of(row.begin(), row.end(), [](Player p){ return p != Player::None; });
    });
}

std::ostream& operator<<(std::ostream& os, const Board& b) {
    for (int r=0; r<3; ++r) {
        for (int c=0; c<3; ++c) {
            const Player p = b._cells[static_cast<size_t>(r)][static_cast<size_t>(c)];
            char ch = (p==Player::X?'X':p==Player::O?'O':'.');
            os << ch << (c<2?' ':'\n');
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Board& b) {
    for (int r=0; r<3; ++r) {
        for (int c=0; c<3; ++c) {
            char ch; if(!(is >> ch)) return is;
            b._cells[static_cast<size_t>(r)][static_cast<size_t>(c)] =
                (ch=='X'||ch=='x')? Player::X :
                (ch=='O'||ch=='o'||ch=='0')? Player::O : Player::None;
        }
    }
    return is;
}
