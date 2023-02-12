#include "coffee_decorator.h"
#include "coffee_factory.h"

#include <fmt/format.h>
#include <iostream>

std::unique_ptr<Coffee> take_custom_order(std::unique_ptr<Coffee> c) {
  for (;;) {
    fmt::print("What do you want to add to your coffee?\n");
    fmt::print("1. Coffee Beans\n");
    fmt::print("2. Milk\n");
    fmt::print("3. Dairy Cream\n");
    fmt::print("4. Cinnamon Powder\n");
    fmt::print("5. Chocolate Sauce\n");
    fmt::print("6. Confirm Order\n");

    char ch;
    std::cin >> ch;
    switch (ch) {
    case '1':
      c = std::make_unique<GroundBeans>("Custom Coffee", std::move(c));
      break;
    case '2':
      c = std::make_unique<Milk>("Custom Coffee", std::move(c));
      break;
    case '3':
      c = std::make_unique<DairyCream>("Custom Coffee", std::move(c));
      break;
    case '4':
      c = std::make_unique<CinnamonPowder>("Custom Coffee", std::move(c));
      break;
    case '5':
      c = std::make_unique<ChocolateSauce>("Custom Coffee", std::move(c));
      break;
    case '6':
      return c;
    default:
      fmt::print("Invalid choice.\n");
      break;
    }
  }
}

int main() {
  char ch;
  for (;;) {
    fmt::print("Welcome to the কফি টং!\n");
    std::vector<std::unique_ptr<Coffee>> orders;

    bool done = false;
    int total_bill = 0;

    while (!done) {
      fmt::print("Place your order\n");
      fmt::print("1. Americano\n");
      fmt::print("2. Espresso\n");
      fmt::print("3. Cappuccino\n");
      fmt::print("4. Mocha\n");
      fmt::print("5. Customized Black Coffee\n");
      fmt::print("6. Customized Milk Coffee\n");
      fmt::print("7. Finish Order\n");

      std::cin >> ch;
      std::unique_ptr<Coffee> c;

      switch (ch) {
      case '1':
        c = CoffeeFactory::create(CoffeeType::AMERICANO);
        break;
      case '2':
        c = CoffeeFactory::create(CoffeeType::ESPRESSO);
        break;
      case '3':
        c = CoffeeFactory::create(CoffeeType::CAPPUCCINO);
        break;
      case '4':
        c = CoffeeFactory::create(CoffeeType::MOCHA);
        break;
      case '5':
        c = take_custom_order(std::make_unique<BlackCoffee>());
        break;
      case '6':
        c = take_custom_order(std::make_unique<MilkCoffee>());
        break;
      case '7':
        done = true;
        break;
      default:
        fmt::print("Invalid choice.\n");
        break;
      }

      if (c) {
        total_bill += c->cost();
        orders.push_back(std::move(c));
        fmt::print("Order placed successfully!\n\n");
      }
    }

    // print the order summary
    fmt::print("Bill - {} BDT", total_bill);
    fmt::print("================================\n\n");
    for (auto &c : orders) {
      c->print_description();
    }
    fmt::print("\n");
  }
}
