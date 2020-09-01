/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_H_
#define _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_H_
/**
 * The secret number.
 */
class Secret {
 public:
  Secret();
  explicit Secret(unsigned int seed);
  /**
   * The randomly generated secret number.
   * @return a random number in rage 0..99.
   */
  int number() const;
};

#endif  // _NUMBER_GUESSING_GAME_SRC_SECRET_SECRET_H_
