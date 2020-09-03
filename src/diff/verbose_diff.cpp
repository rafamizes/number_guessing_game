/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "verbose_diff.hpp"
#include <iostream>

VerboseDiff::VerboseDiff(Diff diff) : _diff{diff} {}

int VerboseDiff::number() const {
  const auto diff = _diff.number();
  if (diff < 0) {
    std::cout << "Too small.\n";
  } else if (diff > 0) {
    std::cout << "Too big.\n";
  } else {
    std::cout << "Bingo!\n";
  }
  return diff;
}

VerboseDiff::operator int() const { return this->number(); }
