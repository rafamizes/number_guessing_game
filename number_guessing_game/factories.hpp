// Copyright 2022
// 
// Prototypes of factory functions
#ifndef NUMBER_GUESSING_GAME_FACTORIES_HPP_
#define NUMBER_GUESSING_GAME_FACTORIES_HPP_

#include "attempts/attempts.hpp"
#include "diff/diff.hpp"
#include "diff/verbose_diff.hpp"
#include "farewell/farewell.hpp"
#include "guess/guess.hpp"
#include "secret/secret.hpp"

Secret secret();

Guess guess();

Diff diff(Secret secret, Guess guess);

VerboseDiff vdiff(Diff diff);

Attempts attempts(VerboseDiff vdiff, int max);

Farewell farewell(Attempts attempts, Secret secret);

#endif  // NUMBER_GUESSING_GAME_FACTORIES_HPP_
