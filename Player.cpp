#include "Player.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Player p) {
    switch (p) {
        case Player::X:    os << 'X'; break;
        case Player::O:    os << 'O'; break;
        case Player::None: os << '.'; break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Player& p) {
    char ch;
    if (!(is >> ch)) return is;
    if (ch=='X' || ch=='x') p = Player::X;
    else if (ch=='O' || ch=='o' || ch=='0') p = Player::O;
    else p = Player::None;
    return is;
}
