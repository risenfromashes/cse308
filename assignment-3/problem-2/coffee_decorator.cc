
#include "coffee_decorator.h"

CoffeeDecorator::CoffeeDecorator(std::string name,
                                 std::unique_ptr<Coffee> coffee)
    : name_(std::move(name)), coffee_(std::move(coffee)) {}

GroundBeans::GroundBeans(std::string name, std::unique_ptr<Coffee> coffee)
    : CoffeeDecorator(std::move(name), std::move(coffee)) {}
void GroundBeans::print_ingredients() {
  coffee_->print_ingredients();
  Ingredient::ground_coffee_bean.print();
}
int GroundBeans::cost() {
  return coffee_->cost() + Ingredient::ground_coffee_bean.price();
}

Milk::Milk(std::string name, std::unique_ptr<Coffee> coffee)
    : CoffeeDecorator(std::move(name), std::move(coffee)) {}
void Milk::print_ingredients() {
  coffee_->print_ingredients();
  Ingredient::milk.print();
}
int Milk::cost() { return coffee_->cost() + Ingredient::milk.price(); }

DairyCream::DairyCream(std::string name, std::unique_ptr<Coffee> coffee)
    : CoffeeDecorator(std::move(name), std::move(coffee)) {}
void DairyCream::print_ingredients() {
  coffee_->print_ingredients();
  Ingredient::dairy_cream.print();
}
int DairyCream::cost() {
  return coffee_->cost() + Ingredient::dairy_cream.price();
}

CinnamonPowder::CinnamonPowder(std::string name, std::unique_ptr<Coffee> coffee)
    : CoffeeDecorator(std::move(name), std::move(coffee)) {}
void CinnamonPowder::print_ingredients() {
  coffee_->print_ingredients();
  Ingredient::cinnamon_powder.print();
}
int CinnamonPowder::cost() {
  return coffee_->cost() + Ingredient::cinnamon_powder.price();
}

ChocolateSauce::ChocolateSauce(std::string name, std::unique_ptr<Coffee> coffee)
    : CoffeeDecorator(std::move(name), std::move(coffee)) {}
void ChocolateSauce::print_ingredients() {
  coffee_->print_ingredients();
  Ingredient::chocolate_sauce.print();
}

int ChocolateSauce::cost() {
  return coffee_->cost() + Ingredient::chocolate_sauce.price();
}
