/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "secret.hpp"

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <sstream>
#include <stdexcept>

Secret::Secret() : Secret{static_cast<unsigned>(time(nullptr))} {}

Secret::Secret(unsigned seed) : _seed{seed} {}

int Secret::number() const {
  static int value = [this]() {
    srand(_seed);
    return rand() % 100;
  }();
  return value;
}

Secret::operator int() const { return this->number(); }
