// Copyright 2022
#include <number_guessing_game/diff/diff.hpp>
#include <utility>

Diff::Diff(Secret secret, Guess guess)
    : _secret{std::move(secret)}, _guess{std::move(guess)} {}

int Diff::number() const noexcept { return _guess.number() - _secret.number(); }
