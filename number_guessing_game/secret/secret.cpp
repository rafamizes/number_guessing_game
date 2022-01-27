#include <number_guessing_game/secret/secret.hpp>

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string_view>
Secret::Secret() : Secret{static_cast<unsigned>(time(nullptr))} {}

Secret::Secret(unsigned seed) : _seed{seed} {}

int Secret::number() const noexcept {
  static int value = [this]() {
    srand(_seed);
    return rand() % 100;
  }();
  return value;
}
