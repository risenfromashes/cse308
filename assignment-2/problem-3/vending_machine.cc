#include "vending_machine.h"
#include <fmt/core.h>

VendingMachine::VendingMachine(Product product, unsigned int stock)
    : product_(std::move(product)), n_stock_(stock) {
  /* set starting state */
  next_state(get_state_instance<StartState>());
}

std::string_view VendingMachine::product_name() { return product_.name(); }
float VendingMachine::cost() { return product_.cost(); }

int VendingMachine::stock() { return n_stock_; }

Product VendingMachine::push_product() {
  n_stock_--;
  return product_;
}

void VendingMachine::increase_stock(unsigned int quantity) {
  n_stock_ += quantity;
}

VendingMachineState *VendingMachine::state() {
  return static_cast<VendingMachineState *>(state_);
}

void VendingMachine::status() {
  fmt::print(
      "[Vending Machine] Product Cost: {:>5.2f} BDT | {} product in stock\n",
      cost(), stock());
}

void VendingMachine::add_money(float money) { state()->add_money(money); }

void VendingMachine::get_return() { state()->get_return(); }

void VendingMachine::get_product() { state()->get_product(); }

void VendingMachine::refill(unsigned int quantity) {
  state()->refill_product(quantity);
}
