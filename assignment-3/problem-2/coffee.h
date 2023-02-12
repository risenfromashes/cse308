#pragma once

#include <string>
#include <vector>

#include "ingredient.h"

#include <fmt/format.h>

class Coffee {
public:
  const int mug_price = 100;

  virtual ~Coffee() = default;

  virtual std::string_view name() { return name_; }

  void print_description();
  virtual void print_ingredients();
  virtual int cost();

protected:
  void add_ingredient(Ingredient ingredient);

  std::string name_;
  std::vector<Ingredient> ingredients_;
};

class BlackCoffee : public Coffee {
public:
  BlackCoffee();
};

class MilkCoffee : public Coffee {
public:
  MilkCoffee();
};
