#pragma once

#include "vending_machine.h"

class State {
protected:
  State(Context *context);

  Context *context_;
};

class VendingMachineState : public State {
public:
  /* default implementations */

  // don't accept money
  virtual void add_money(float money);
  // don't provide return
  virtual void get_return();
  // don't return product
  virtual void get_product();
  // don't accept refill
  virtual void refill_product();

protected:
  VendingMachine *context();
  virtual ~VendingMachineState() = default;

  VendingMachineState(VendingMachine *vm);
};

class StartState : public VendingMachineState {
public:
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void refill_product() override;

  void reset();

private:
  float paid_amount_;
};

class PaidState : public VendingMachineState {
public:
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void refill_product() override;
};

class OverpaidState : public VendingMachineState {
public:
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void refill_product() override;

  void set_return(float amount);

private:
  float return_amount_;
};

class VacantState : public VendingMachineState {
public:
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void refill_product() override;
};
