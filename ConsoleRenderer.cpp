#include "ConsoleRenderer.hpp"

static char Sym(Player p){ return p==Player::X?'X':p==Player::O?'O':' '; }

void ConsoleRenderer::DrawBoard(const Board& b) {
    for (int r=0;r<3;++r) {
        for (int c=0;c<3;++c) {
            std::cout << ' ' << Sym(b.Get(r,c)) << ' ';
            if (c<2) std::cout << '|';
        }
        std::cout << '\n';
        if (r<2) std::cout << "---+---+---\n";
    }
}

void ConsoleRenderer::DrawTurn(Player p) {
    std::cout << "Rand " << Sym(p) << ": ";
}

void ConsoleRenderer::AnnounceWinner(Player p) {
    std::cout << "Castigator: " << Sym(p) << "!\n";
}

void ConsoleRenderer::AnnounceDraw() {
    std::cout << "Remiza!\n";
}

void ConsoleRenderer::WriteText(const std::string& text) {
    std::cout << text << "\n";
}
