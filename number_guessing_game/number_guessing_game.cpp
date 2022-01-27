// Copyright 2022
#include <climits>

#include <iostream>
#include <number_guessing_game/factories.hpp>

int main() {
  const Secret secret;
  /* secret.number(); */
  farewell(attempts(vdiff(diff(secret, guess())), 5), secret).say();
  /* int* intPtr = nullptr; */
  /* std::cout << "intPtr value: " << *intPtr << "\n"; */
  /* { */
    /* int aValue = 9; */
    /* intPtr = &aValue; */
  /* } */
  /* std::cout << "intPtr value: " << *intPtr << "\n"; */
  return 0;
}
