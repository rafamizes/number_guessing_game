// Copyright 2022
#include <number_guessing_game/attempts/attempts.hpp>
#include <number_guessing_game/diff/diff.hpp>
#include <number_guessing_game/diff/verbose_diff.hpp>
#include <number_guessing_game/farewell/farewell.hpp>
#include <number_guessing_game/guess/guess.hpp>
#include <number_guessing_game/secret/secret.hpp>
int main() {
  constexpr int maxAttempts = 5;
  const Secret secret;
  Farewell{
    Attempts{
      VerboseDiff{
        Diff{
          secret,
          Guess{"Guess a number in 0..99 range: "}
        }
      },
      maxAttempts
    },
    secret
  }.say();

  return 0;
}
