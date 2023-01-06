#include "state.h"
#include <fmt/core.h>

#include "vending_machine.h"

State::State(Context *context) : context_(context) {}

VendingMachineState::VendingMachineState(Context *context) : State(context) {}

VendingMachine *VendingMachineState::context() {
  return static_cast<VendingMachine *>(context_);
}

void VendingMachineState::add_money(float money) { //
  fmt::print("[Vending Machine] Sorry, currently out of stock\n");
}

void VendingMachineState::get_return() { //
  fmt::print("[Vending Machine] You have no return and sorry, currently out of "
             "stock\n");
}

void VendingMachineState::get_product() { //
  fmt::print("[Vending Machine] Sorry, currently out of stock\n");
}

void VendingMachineState::refill_product(unsigned int quantity) { //
  fmt::print(
      "[Vending Machine] Refill not required currently, {} products in stock\n",
      context()->stock());
}

StartState::StartState(Context *context) : VendingMachineState(context) {}

void StartState::reset() { paid_amount_ = 0.f; }

void StartState::add_money(float money) {

  if (money < 0) {
    fmt::print("[Vending Machine] [Error] Invalid money amount\n", money,
               paid_amount_);
    return;
  }

  paid_amount_ += money;
  fmt::print("[Vending Machine] {:>5.2f} BDT received, total {:>5.2f} BDT\n",
             money, paid_amount_);

  float rem = context()->cost() - paid_amount_;

  if (rem == 0) {

    auto next_state = context()->get_state_instance<PaidState>();
    context()->next_state(next_state);

  } else if (rem < 0) {

    auto next_state = context()->get_state_instance<OverPaidState>();
    next_state->set_return(-rem);
    context()->next_state(next_state);

  } else {

    fmt::print("[Vending Machine] Please pay {:>5.2f} BDT\n", rem);
  }
}

void StartState::get_return() {
  fmt::print("[Vending Machine] You have no return; you have only "
             "entered {:>5.2f} BDT out of product cost {:>5.2f} BDT\n",
             paid_amount_, context()->cost());
}

void StartState::get_product() {
  fmt::print("[Vending Machine] You haven't paid the product cost {:>5.2f} "
             "BDT; you have only "
             "entered {:>5.2f} BDT\n",
             context()->cost(), paid_amount_);
}

PaidState::PaidState(Context *context) : VendingMachineState(context) {}

void PaidState::add_money(float money) {
  fmt::print("[Vending Machine] You have already paid the product cost "
             "{:>5.2f} BDT\n",
             context()->cost());
}

void PaidState::get_return() {

  fmt::print("[Vending Machine] You have no return; you have paid the"
             " product cost {:>5.2f} BDT exactly\n",
             context()->cost());
}

void PaidState::get_product() {
  auto product = context()->push_product();
  fmt::print("[Vending Machine] Here is our {}\n", product.name());
  fmt::print("[Vending Machine] Thank you for using our service ^_^\n");

  State *next_state;
  if (context()->stock()) {
    next_state = context()->get_state_instance<StartState>();
  } else {
    next_state = context()->get_state_instance<VacantState>();
  }
  context()->next_state(next_state);
}

OverPaidState::OverPaidState(Context *context) : VendingMachineState(context) {}

void OverPaidState::add_money(float money) {
  fmt::print("[Vending Machine] You have already paid a surplus amount of "
             "{:>5.2f} BDT\n",
             return_amount_);
}

void OverPaidState::get_return() {
  fmt::print("[Vending Machine] Here is your return of {:>5.2f} BDT\n",
             return_amount_);
  auto next_state = context()->get_state_instance<PaidState>();
  context()->next_state(next_state);
}

void OverPaidState::get_product() {
  fmt::print(
      "[Vending Machine] Please take your return of {:>5.2f} BDT first\n",
      return_amount_);
}

void OverPaidState::set_return(float amount) { return_amount_ = amount; }

void OverPaidState::reset() { return_amount_ = 0.f; }

VacantState::VacantState(Context *context) : VendingMachineState(context) {}

void VacantState::refill_product(unsigned int quantity) {
  fmt::print("[Vending Machine] Refilled with {} products successfully\n",
             quantity);
}
