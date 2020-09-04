/**
 * Copyright © 2020 Platis.
 *
 * All rights reserved.
 */
#include <iostream>
#include "factories.hpp"

int main() {
  Secret secret_num = secret();
  farewell(attempts(vdiff(diff(secret_num, guess())), 5), secret_num).say();
}
