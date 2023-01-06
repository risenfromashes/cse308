#include "vending_machine.h"

void VendingMachine::set_product(Product product) {
  product_ = std::move(product);
}

float VendingMachine::cost() { return product_.cost(); }
