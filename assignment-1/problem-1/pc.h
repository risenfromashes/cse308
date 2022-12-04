#pragma once

#include "component.h"

#include <memory>
#include <vector>

class PC {
  friend class PCBuilder;

public:
  void print_details();
  const auto &components() { return components_; }

private:
  PC(unsigned int total_price, std::vector<std::unique_ptr<Component>> &&comps);

  unsigned int total_price_;
  std::vector<std::unique_ptr<Component>> components_;
};
