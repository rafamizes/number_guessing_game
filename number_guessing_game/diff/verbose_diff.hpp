#ifndef NUMBER_GUESSING_GAME_DIFF_VERBOSE_DIFF_HPP_
#define NUMBER_GUESSING_GAME_DIFF_VERBOSE_DIFF_HPP_

/* #include "number_guessing_game/diff/diff.hpp" */

#include "diff.hpp"

/**
 * Diff that helps the user with tips.
 */
class VerboseDiff final {
 public:
  /// The difference [diff] between the guessed and secret number.
  explicit VerboseDiff(Diff diff);

  /// Computes the difference between secret and guess.
  int number() const;

 private:
  Diff _diff;
};

#endif  // NUMBER_GUESSING_GAME_DIFF_VERBOSE_DIFF_HPP_
