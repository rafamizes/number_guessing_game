#include <number_guessing_game/guess/guess.hpp>

#include <iostream>
#include <utility>

Guess::Guess(std::string msg) : _msg{std::move(msg)} {}

int Guess::number() const noexcept {
  std::cout << _msg;
  int guess;
  std::cin >> guess;
  return guess;
}
