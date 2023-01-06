#include "state.h"
#include <fmt/core.h>

void VendingMachineState::add_money() { //
  fmt::print("[Response] Cannot add money at the moment\n");
}

void VendingMachineState::get_return() { //
  fmt::print("[Response] Cannot add money at the moment\n");
}

void VendingMachineState::refill_product() { //
  fmt::print("[Response] Refill not required currently\n");
}

void VendingMachineState::get_product() { //
  fmt::print("[Response] Cannot get product at the moment\n");
}

void StartState::add_money() {}
void StartState::get_return() {}
void StartState::get_product() {}
void StartState::refill_product() {}

void UnpaidState::add_money() {}
void UnpaidState::get_return() {}
void UnpaidState::get_product() {}
void UnpaidState::refill_product() {}

void PaidState::add_money() {}
void PaidState::get_return() {}
void PaidState::get_product() {}
void PaidState::refill_product() {}

void OverpaidState::add_money() {}
void OverpaidState::get_return() {}
void OverpaidState::get_product() {}
void OverpaidState::refill_product() {}

void VacantState::add_money() {}
void VacantState::get_return() {}
void VacantState::get_product() {}
void VacantState::refill_product() {}
