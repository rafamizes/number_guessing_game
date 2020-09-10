/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef SRC_GUESS_GUESS_HPP_
#define SRC_GUESS_GUESS_HPP_

#include <string>

/**
 * Represents a guessed number.
 */
class Guess final {
 public:
  /**
   * Ctor.
   * @param msg the prompt message.
   */
  explicit Guess(std::string msg);
  /**
   * Prompts the user for a integer number
   */
  int number() const;

 private:
  std::string _msg;
};

#endif  // SRC_GUESS_GUESS_HPP_
