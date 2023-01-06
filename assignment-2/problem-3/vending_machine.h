#pragma once

#include <vector>

#include "context.h"
#include "product.h"

class VendingMachine : public Context {
public:
  void set_product(Product product);
  float cost();

private:
  Product product_;
};
