/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "src/secret/secret.hh"

#include <cstdlib>
#include <ctime>

Secret::Secret() : Secret(time(0)) {}

Secret::Secret(unsigned int seed) { srand(seed); }

int Secret::number() const { return rand() % 100; }
