#pragma once

#include "vending_machine.h"

class State {
public:
  virtual void add_money();
  virtual void get_return();
  virtual void refill_product();
  virtual void get_product();

protected:
  State(Context *context);

  Context *context_;
};

class VendingMachineState : public State {
protected:
  VendingMachine *context();
  VendingMachineState(VendingMachine *vm);
};

class StartState : public VendingMachineState {};
