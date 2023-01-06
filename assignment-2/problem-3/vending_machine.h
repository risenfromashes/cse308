#pragma once

#include <vector>

#include "context.h"
#include "product.h"

class VendingMachine : public Context {
public:
  VendingMachine(Product product, unsigned int n_stock);

  std::string_view product_name();
  float cost();
  int stock();
  void increase_stock(unsigned int quantity);
  Product push_product();
  void status();

  void add_money(float money);
  void get_return();
  void get_product();
  void refill(unsigned int quantity);

private:
  VendingMachineState *state();

  Product product_;
  unsigned int n_stock_;
};
