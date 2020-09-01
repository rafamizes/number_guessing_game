/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include <stdlib.h>

#include <iostream>
#include <string>

int rand_number();

int main() {
  std::cout << "Welcome to the Number Guessing Game!\n";
  const auto number = rand_number();
  auto attempt = 0;
  while (attempt < 5) {
    std::cout << "Guess a number in 0..99 range: ";
    int guess;
    std::cin >> guess;
    if (guess > number) {
      std::cout << "Too big.\n";
    } else if (guess < number) {
      std::cout << "Too small.\n";
    } else {
      break;
    }
    ++attempt;
  }
  if (attempt < 5) {
    std::cout << "Bingo!\n";
  } else {
    std::cout << "You lost, sorry; it was: " << number << "\n";
  }
  std::cout << "Thanks for playing with me!\n";
  return 0;
}

int rand_number() {
  srand(time(NULL));
  return rand() % 100;
}
