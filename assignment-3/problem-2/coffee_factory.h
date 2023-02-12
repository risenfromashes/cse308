#pragma once

#include "coffee_decorator.h"

enum class CoffeeType { AMERICANO, ESPRESSO, CAPPUCCINO, MOCHA };

class CoffeeFactory {
public:
  static std::unique_ptr<Coffee> create(CoffeeType type);
};
