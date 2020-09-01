/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "secret.hh"

#include <cstdlib>
#include <ctime>

Secret::Secret() : Secret(time(0)) {}

Secret::Secret(unsigned int seed) { srand(seed); }

int Secret::number() const { return rand() % 100; }

Secret::operator int() const { return this->number(); }
