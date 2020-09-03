#ifndef SRC_ATTEMPTS_ATTEMPTS_HPP_
#define SRC_ATTEMPTS_ATTEMPTS_HPP_

#include "verbose_diff.hpp"

// User attempts to guess the secret number.
class Attempts final {
 public:
  Attempts(VerboseDiff diff, int max);

  bool matches() const;
  operator bool() const;

 private:
  const VerboseDiff _vdiff;
  const int _max;
};
#endif  // SRC_ATTEMPTS_ATTEMPTS_HPP_
