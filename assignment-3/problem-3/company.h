#pragma once

#include <memory>
#include <string>
#include <vector>

#include <fmt/format.h>

#include "component.h"

class Manager;

class Company : public Component {
public:
  Company(std::string name);

  std::string name() { return name_; }

  void add_child(Component *c) override;
  void remove_child(Component *c) override;
  void remove() override;
  void print_hierarchy(int depth) override;
  void print_details() override;

private:
  std::string name_;
  std::vector<Manager *> managers_;
};
