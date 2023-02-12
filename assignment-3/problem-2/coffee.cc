#include "coffee.h"

void Coffee::print_description() {
  fmt::print("{} - {} BDT\n", name(), cost());
  fmt::print("Ingredients:\n");
  fmt::print("-------------------------------\n");
  print_ingredients();
}

void Coffee::print_ingredients() {
  for (auto &ing : ingredients_) {
    ing.print();
  }
}

int Coffee::cost() {
  int price = mug_price;
  for (auto &ing : ingredients_) {
    price += ing.price();
  }
  return price;
}

void Coffee::add_ingredient(Ingredient ingredient) {
  ingredients_.push_back(ingredient);
}

BlackCoffee::BlackCoffee() {
  ingredients_.push_back(Ingredient::water);
  ingredients_.push_back(Ingredient::ground_coffee_bean);
}

MilkCoffee::MilkCoffee() {
  ingredients_.push_back(Ingredient::milk);
  ingredients_.push_back(Ingredient::ground_coffee_bean);
}
