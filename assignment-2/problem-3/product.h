#pragma once

#include <string>

class Product {
public:
  Product(int id, std::string name, float cost);

  int id() { return id_; }
  float cost() { return cost_; }
  std::string_view name() { return name_; }

private:
  int id_;
  std::string name_;
  float cost_;
};
