// Copyright 2022
#ifndef NUMBER_GUESSING_GAME_ATTEMPTS_ATTEMPTS_HPP_
#define NUMBER_GUESSING_GAME_ATTEMPTS_ATTEMPTS_HPP_

#include <number_guessing_game/diff/verbose_diff.hpp>

/// User attempts to guess the secret number.
class Attempts final {
 public:
  /// [vdiff] the difference between guessed and secret number.
  /// [max] the maximum number of attempts.
  Attempts(VerboseDiff vdiff, int max);

  /// Checkes whether the secret number has been guessed.
  /// return true if matched; false otherwise.
  bool matches() const noexcept;

 private:
  const VerboseDiff _vdiff;
  const int _max;
};

#endif  // NUMBER_GUESSING_GAME_ATTEMPTS_ATTEMPTS_HPP_
