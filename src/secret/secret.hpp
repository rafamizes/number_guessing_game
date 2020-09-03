/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_HPP_
#define _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_HPP_
/**
 * The secret number.
 */
class Secret {
 public:
  Secret();
  /**
   * The randomly generated secret number.
   * @return a random number in rage 0..99.
   */
  int number() const;

  operator int() const;

 private:
  const int _value;
};

#endif  // _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_HPP_
