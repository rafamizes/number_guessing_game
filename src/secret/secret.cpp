/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "secret.hpp"

#include <cstdlib>
#include <ctime>

Secret::Secret() : _value{rand() % 100} {}

int Secret::number() const { return _value; }

Secret::operator int() const { return this->number(); }
