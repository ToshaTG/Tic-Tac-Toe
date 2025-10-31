#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "GameEngine.hpp"
#include "ConsoleRenderer.hpp"
#include "Move.hpp"

int main(){
    GameEngine g; 
    g.Init();
    g.SetRenderer(std::make_unique<ConsoleRenderer>());

    auto* R = g.RendererPtr();
    if (R) R->WriteText("Tic-Tac-Toe (lab04). Introdu mutari 'r c' (0..2) sau 'q' pentru iesire.");

    while(true){
        if (R) {
            R->DrawBoard(g.GetBoard());
            auto w = g.CheckWinner();
            if (w != Player::None) { R->AnnounceWinner(w); break; }
            if (g.IsDraw()) { R->AnnounceDraw(); break; }
            R->DrawTurn(g.Current());
        }

        std::string line;
        if(!std::getline(std::cin, line)) break;
        if(line=="q" || line=="Q") break;

        std::stringstream ss(line);
        Move m; 
        if(!(ss >> m)) { if(R) R->WriteText("Intrare invalida."); continue; }

        if(!g.MakeMove(m)) { if(R) R->WriteText("Mutare invalida."); }
    }
    return 0;
}
