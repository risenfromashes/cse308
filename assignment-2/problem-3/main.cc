#include <iostream>

#include "vending_machine.h"

#include <fmt/core.h>

int main() {
  Product cocacola(1, "Cocacola", 50.0);
  VendingMachine vending_machine(cocacola, 20);

  for (;;) {
    vending_machine.status();

    fmt::print("Press a button [1-8]\n");
    fmt::print("1. Get {}\n", vending_machine.product_name());
    fmt::print("2. Insert money\n");
    fmt::print("3. Get return\n");
    fmt::print("4. Refill stock\n");
    fmt::print("5. Quit\n");

    char ch;
    float money;

    std::cin >> ch;

    fmt::print("\n");
    switch (ch) {
    case '1':
      vending_machine.get_product();
      break;
    case '2':
      fmt::print("Enter amount [BDT]: ");
      std::cin >> money;
      fmt::print("\n");
      vending_machine.add_money(money);
      break;
    case '3':
      vending_machine.get_return();
      break;
    case '4':
      vending_machine.refill(20);
      break;
    case '5':
      return 0;
    default:
      fmt::print("Invalid Button '{}'\n", ch);
      break;
    }
    fmt::print("\n");
  }
}
