/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef SRC_DIFF_VERBOSE_DIFF_HPP_
#define SRC_DIFF_VERBOSE_DIFF_HPP_

#include "diff.hpp"

class VerboseDiff final {
 public:
  VerboseDiff(Diff diff);

  int number() const;

  operator int() const;

 private:
  const Diff _diff;
};

#endif  // SRC_DIFF_DIFF_HPP_

