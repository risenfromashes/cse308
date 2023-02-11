#pragma once

class Ingredient {
public:
  const static Ingredient water;
  const static Ingredient ground_coffee_bean;
  const static Ingredient milk;
  const static Ingredient dairy_cream;
  const static Ingredient cinnamon_powder;
  const static Ingredient chocolate_sauce;

  const char *name() { return name_; }
  int price() { return price_; }

private:
  Ingredient(const char *name, int price) : name_(name), price_(price) {}

  const char *name_;
  int price_;
};