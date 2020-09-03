#include "attempts.hpp"

Attempts::Attempts(VerboseDiff vdiff, int max) : _vdiff{vdiff}, _max{max} {}

bool Attempts::matches() const {
  int attempt = 0;
  while (attempt <= _max && _vdiff.number() != 0) {
    ++attempt;
  }
  return attempt <= _max;
}

Attempts::operator bool() const { return this->matches(); }
