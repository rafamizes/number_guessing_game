// Copyright 2022
#ifndef NUMBER_GUESSING_GAME_GUESS_GUESS_HPP_
#define NUMBER_GUESSING_GAME_GUESS_GUESS_HPP_

#include <string>

/// Represents a number to be guessed.
class Guess final {
 public:
  /// [msg] the prompt message.
  explicit Guess(std::string msg);

  /// Prompts the user for a integer number and returns it;
  int number() const noexcept;

 private:
  std::string _msg;
};

#endif  // NUMBER_GUESSING_GAME_GUESS_GUESS_HPP_
