/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include "guess.hpp"
#include <iostream>
#include <utility>

Guess::Guess(std::string msg) : _msg{std::move(msg)} {}

int Guess::number() const {
  std::cout << _msg;
  int guess;
  std::cin >> guess;
  return guess;
}
Guess::operator int() const { return this->number(); }
