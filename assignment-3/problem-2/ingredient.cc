#include "ingredient.h"
#include <fmt/format.h>

const Ingredient Ingredient::water = Ingredient("Water", 0);

const Ingredient Ingredient::ground_coffee_bean =
    Ingredient("Ground Coffee Beans", 20);

const Ingredient Ingredient::milk = Ingredient("Milk", 20);

const Ingredient Ingredient::dairy_cream = Ingredient("Dairy Cream", 20);

const Ingredient Ingredient::cinnamon_powder =
    Ingredient("Cinnamon Powder", 20);

const Ingredient Ingredient::chocolate_sauce =
    Ingredient("Chocolate Sauce", 20);

void Ingredient::print() const {
  fmt::print("◼ {} - {} BDT\n", name(), price());
}