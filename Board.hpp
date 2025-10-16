#pragma once
#include "Player.hpp"
#include "Move.hpp"
#include <iosfwd>

class Board {
    Player _cells[3][3];
public:
    // ctor implicit: tabla goală
    Board();

    // ctor cu parametri: umple toată tabla cu aceeași valoare (default None)
    explicit Board(Player fill);

    // ctor de copiere / operator=
    Board(const Board& other);
    Board& operator=(const Board& other);

    // API existent
    void   Reset();
    bool   InBounds(int r, int c) const;
    Player Get(int r, int c) const;
    bool   IsEmpty(int r, int c) const;
    bool   Place(int r, int c, Player p);
    bool   IsFull() const;

    // comparare
    bool operator==(const Board& other) const;
    bool operator!=(const Board& other) const { return !(*this == other); }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    friend std::istream& operator>>(std::istream& is, Board& b);
};
