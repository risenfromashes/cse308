#include "state.h"
#include <fmt/core.h>

void VendingMachineState::add_money(float money) { //
  fmt::print("[Vending Machine] Cannot add money at the moment\n");
}

void VendingMachineState::get_return() { //
  fmt::print("[Vending Machine] Cannot add money at the moment\n");
}

void VendingMachineState::refill_product() { //
  fmt::print("[Vending Machine] Refill not required currently\n");
}

void VendingMachineState::get_product() { //
  fmt::print("[Vending Machine] Cannot get product at the moment\n");
}

void StartState::add_money(float money) {
  fmt::print("[Vending Machine] {:>5.2f} BDT received\n", money);
}

void StartState::get_return() {
  fmt::print("[Vending Machine] Product cost {:>5.2f} BDT, you have only "
             "entered {:>5.2f} BDT\n",
             context()->cost(), paid_amount_);
}

void StartState::get_product() {}

void StartState::refill_product() {}

void PaidState::add_money(float money) {}

void PaidState::get_return() {}

void PaidState::get_product() {}

void PaidState::refill_product() {}

void OverpaidState::add_money(float money) {}

void OverpaidState::get_return() {}

void OverpaidState::get_product() {}

void OverpaidState::refill_product() {}

void VacantState::add_money(float money) {}

void VacantState::get_return() {}

void VacantState::get_product() {}

void VacantState::refill_product() {}
