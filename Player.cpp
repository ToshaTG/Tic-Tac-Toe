#include "Player.hpp"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

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

// ===== Lab5: Demonstrație folosire bibliotecă externă JSON =====
// Această variabilă globală rulează o singură dată, la pornirea programului,
// și salvează un fișier JSON pe disc (lab5_json_demo.json).
namespace {
bool run_json_demo = [](){
    json j;
    j["lab"]   = "Lab5";
    j["demo"]  = "json save";
    j["value"] = 123;

    std::ofstream out("lab5_json_demo.json");
    if (out.is_open()) {
        out << j.dump(4);
    }

    return true;
}();
}
