#pragma once

class Context;
class VendingMachine;

class State {
public:
  virtual ~State() = default;

  /* default reset behavour: do nothing */
  virtual void reset() {}

protected:
  State(Context *context);

  Context *context_;
};

class VendingMachineState : public State {
public:
  virtual ~VendingMachineState() = default;

  /* default implementations */
  /* refuse everything */

  // assume out of stock
  virtual void add_money(float money);
  // assume out of stock
  virtual void get_return();
  // assume out of stock
  virtual void get_product();
  // assume in stock
  virtual void refill_product(unsigned int quantity);

protected:
  VendingMachineState(Context *context);
  VendingMachine *context();
};

class StartState : public VendingMachineState {
public:
  StartState(Context *context);
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void reset() override;

private:
  float paid_amount_;
};

class PaidState : public VendingMachineState {
public:
  PaidState(Context *context);
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
};

class OverPaidState : public VendingMachineState {
public:
  OverPaidState(Context *context);
  void add_money(float money) override;
  void get_return() override;
  void get_product() override;
  void reset() override;

  void set_return(float amount);

private:
  float return_amount_;
};

class VacantState : public VendingMachineState {
public:
  VacantState(Context *context);
  void refill_product(unsigned int quantity) override;
};
