/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef SRC_FAREWELL_FAREWELL_HPP_
#define SRC_FAREWELL_FAREWELL_HPP_

#include "attempts.hpp"
#include "secret.hpp"

// Represents the end-of-game situation for the user.
class Farewell final {
 public:
  Farewell(Attempts attempts, Secret secret);

  void say() const;

 public:
  const Attempts _attempts;
  const Secret _secret;
};

#endif  // SRC_FAREWELL_FAREWELL_HPP_
