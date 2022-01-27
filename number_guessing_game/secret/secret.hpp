// Copyright 2022
#ifndef NUMBER_GUESSING_GAME_SECRET_SECRET_HPP_
#define NUMBER_GUESSING_GAME_SECRET_SECRET_HPP_

/// The secret number.
class Secret final {
 public:
  /// Initializes the rand function with a default seed value.
  Secret();
  /// Initializes the rand function with [seed].
  explicit Secret(unsigned seed);

  /// Returns the randomly generated secret number in range 0 .. 99.
  int number() const noexcept;

 private:
  const unsigned _seed;
};

#endif  // NUMBER_GUESSING_GAME_SECRET_SECRET_HPP_
