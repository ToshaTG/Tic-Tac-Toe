#include "Move.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Move& m) {
    return os << m.row << ' ' << m.col;
}

std::istream& operator>>(std::istream& is, Move& m) {
    return is >> m.row >> m.col;
}
