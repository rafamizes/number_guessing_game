/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef SRC_DIFF_DIFF_HPP_
#define SRC_DIFF_DIFF_HPP_

#include "guess.hpp"
#include "secret.hpp"

class Diff final {
 public:
  Diff(Secret secret, Guess guess);

  int number() const;

  operator int() const;

 private:
  const Secret _secret;
  const Guess _guess;
};

#endif  // SRC_DIFF_DIFF_HPP_

