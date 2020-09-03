/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#ifndef SRC_FACTORIES_HPP_
#define SRC_FACTORIES_HPP_

#include "src/attempts/attempts.hpp"
#include "src/diff/diff.hpp"
#include "src/diff/verbose_diff.hpp"
#include "src/farewell/farewell.hpp"
#include "src/guess/guess.hpp"
#include "src/secret/secret.hpp"

Secret secret();

Guess guess();

Diff diff(Secret secret, Guess guess);

VerboseDiff vdiff(Diff diff);

Attempts attempts(VerboseDiff vdiff, int max);

Farewell farewell(Attempts attempts, Secret secret);

#endif  // SRC_FACTORIES_HPP_
