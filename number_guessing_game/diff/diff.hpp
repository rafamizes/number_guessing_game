#ifndef NUMBER_GUESSING_GAME_DIFF_DIFF_HPP_
#define NUMBER_GUESSING_GAME_DIFF_DIFF_HPP_

#include <number_guessing_game/guess/guess.hpp>
#include <number_guessing_game/secret/secret.hpp>

/// Represents the difference between a guessed number and the secret value.
class Diff final {
public:
  /// The difference between [secret] and [guess].
  Diff(Secret secret, Guess guess);

  /// Computes the difference between secret and guess.
  ///
  /// **returns** 0 (zero) if the _guessed_ number matches with the secret;
  /// negative if guess < secret; positive otherwise.
  int number() const noexcept;

private:
  const Secret _secret;
  const Guess _guess;
};

#endif // NUMBER_GUESSING_GAME_DIFF_DIFF_HPP_
