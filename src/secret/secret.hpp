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
class Secret final {
 public:
  Secret();
  // Ctor.
  // @param seed the seed for initializing rand function.
  explicit Secret(unsigned seed);
  /**
   * The randomly generated secret number.
   * @return a random number in rage 0..99.
   */
  int number() const;

  operator int() const;

 private:
  const unsigned _seed;
};

#endif  // _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_HPP_
