// Copyright 2022
#ifndef NUMBER_GUESSING_GAME_FAREWELL_FAREWELL_HPP_
#define NUMBER_GUESSING_GAME_FAREWELL_FAREWELL_HPP_

#include <number_guessing_game/attempts/attempts.hpp>
#include <number_guessing_game/secret/secret.hpp>

/// Represents the end-of-game situation for the user.
class Farewell final {
 public:
  /// Sets the user [attempts] to guess [secret].
  Farewell(Attempts attempts, Secret secret);

  /// Says the final status of the game.
  void say() const;

 public:
  const Attempts _attempts;
  const Secret _secret;
};

#endif  // NUMBER_GUESSING_GAME_FAREWELL_FAREWELL_HPP_
