#include "coffee_factory.h"

std::unique_ptr<Coffee> CoffeeFactory::create(CoffeeType type) {
  using enum CoffeeType;
  switch (type) {
  case AMERICANO:
    return std::make_unique<GroundBeans>("Americano",
                                         std::make_unique<BlackCoffee>());
  case ESPRESSO:
    return std::make_unique<DairyCream>("Espresso",
                                        std::make_unique<BlackCoffee>());
  case CAPPUCCINO:
    return std::make_unique<CinnamonPowder>("Cappuccino",
                                            std::make_unique<MilkCoffee>());
  case MOCHA:
    return std::make_unique<ChocolateSauce>("Mocha",
                                            std::make_unique<MilkCoffee>());
  }
}
