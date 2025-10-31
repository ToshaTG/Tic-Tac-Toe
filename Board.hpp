#pragma once
#include "Player.hpp"
#include "Move.hpp"
#include <array>
#include <iosfwd>

class Board {
public:
    using Row  = std::array<Player, 3>;
    using Grid = std::array<Row, 3>;

private:
    Grid _cells{};

public:
    Board();                       // implicit
    explicit Board(Player fill);   // umple tabla

    Board(const Board&) = default;
    Board& operator=(const Board&) = default;

    void   Reset();
    bool   InBounds(int r, int c) const;
    Player Get(int r, int c) const;
    bool   IsEmpty(int r, int c) const;
    bool   Place(int r, int c, Player p);
    bool   IsFull() const;

    bool operator==(const Board& other) const { return _cells == other._cells; }
    bool operator!=(const Board& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    friend std::istream& operator>>(std::istream& is, Board& b);
};
