// Copyright 2022
#include <number_guessing_game/farewell/farewell.hpp>

#include <iostream>

Farewell::Farewell(Attempts attempts, Secret secret)
    : _attempts(attempts), _secret(secret) {}

void Farewell::say() const {
  if (!_attempts.matches()) {
    std::cout << "You lost, sorry. It was: " << _secret.number() << "\n";
  }
  std::cout << "Thanks for playing with me!\n";
}
