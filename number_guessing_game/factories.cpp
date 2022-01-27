// Copyright 2022
#include <number_guessing_game/factories.hpp>

Secret secret() { return Secret{}; }

Guess guess() { return Guess("Guess a number in 0..99 range: "); }

Diff diff(Secret secret, Guess guess) { return Diff(secret, guess); }

VerboseDiff vdiff(Diff diff) { return VerboseDiff(diff); }

Attempts attempts(VerboseDiff vdiff, int max) { return Attempts(vdiff, max); }

Farewell farewell(Attempts attempts, Secret secret) {
  return Farewell(attempts, secret);
}
