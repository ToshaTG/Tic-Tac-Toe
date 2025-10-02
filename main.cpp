#include <iostream>
#include <sstream>
#include "GameEngine.hpp"

static char sym(Player p){ return p==Player::X?'X':p==Player::O?'O':' '; }
static void printBoard(const Board& b){
    for(int r=0;r<3;++r){
        for(int c=0;c<3;++c){ std::cout<<" "<<sym(b.Get(r,c))<<" "; if(c<2) std::cout<<"|"; }
        std::cout<<"\n"; if(r<2) std::cout<<"---+---+---\n";
    }
}

int main(){
    GameEngine g; g.Init();
    std::cout<<"Tic-Tac-Toe. (r c) sau q\n";
    while(true){
        printBoard(g.GetBoard());
        if (auto w=g.CheckWinner(); w!=Player::None){ std::cout<<"Castigator: "<<(w==Player::X?"X":"O")<<"\n"; break; }
        if (g.IsDraw()){ std::cout<<"Remiza!\n"; break; }

        std::cout<<"Rand "<<(g.Current()==Player::X?"X":"O")<<": ";
        std::string line; if(!std::getline(std::cin,line)) break;
        if(line=="q"||line=="Q") break;
        int r=-1,c=-1; std::stringstream ss(line); ss>>r>>c; if(!ss){ std::cout<<"Intrare invalida.\n"; continue; }
        if(!g.MakeMove(Move{r,c})) std::cout<<"Mutare invalida.\n";
    }
    return 0;
}
