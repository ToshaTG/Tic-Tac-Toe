#pragma once
#include <iosfwd>

struct Move {
    int row{0};
    int col{0};

    // ctor implicit
    Move() = default;

    // ctor cu parametri
    Move(int r, int c) : row(r), col(c) {}

    // ctor de copiere / operator=
    Move(const Move&) = default;
    Move& operator=(const Move&) = default;

    // comparare
    bool operator==(const Move& other) const { return row == other.row && col == other.col; }
    bool operator!=(const Move& other) const { return !(*this == other); }
    bool operator<(const Move& other)  const { return (row < other.row) || (row == other.row && col < other.col); }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const Move& m);
    friend std::istream& operator>>(std::istream& is, Move& m);
};
