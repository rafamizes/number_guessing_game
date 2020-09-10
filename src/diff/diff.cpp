#include "diff.hpp"

#include <utility>

Diff::Diff(Secret secret, Guess guess)
    : _secret(std::move(secret)), _guess(std::move(guess)) {}

int Diff::number() const { return _guess.number() - _secret.number(); }
