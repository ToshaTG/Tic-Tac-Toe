#pragma once

namespace ttt {

/// Reprezintă starea unei celule / jucătorul curent.
enum class Player {
    None = 0,
    X,
    O
};

/// Comută jucătorul: X -> O, O -> X, None rămâne None.
Player Next(Player p) noexcept;

} // namespace ttt
