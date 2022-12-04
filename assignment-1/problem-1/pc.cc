#include "pc.h"

#include <fmt/format.h>

void PC::print_details() {
  int i = 1;
  fmt::print("{:^70}\n", "Base Components: (Price 70000 BDT)");
  fmt::print("{:-^70}\n", "");
  for (auto &c : components_) {
    if (c->price() == 0) {
      fmt::print("{:>2}. {}\n", i, c->model());
      i++;
    }
  }
  fmt::print("{:-^70}\n", "");
  fmt::print("{:^70}\n", fmt::format("Added Components: (Price {} BDT)",
                                     (total_price_ - 70000)));
  fmt::print("{:-^70}\n", "");
  for (auto &c : components_) {
    if (c->price() > 0) {
      fmt::print("{:>2}. {:<50} - {:<6} BDT\n", i, c->model(), c->price());
      i++;
    }
  }
  fmt::print("{:-^70}\n", "");
  fmt::print("    {:<50} - {:<6} BDT\n", "Total Price", total_price_);
  fmt::print("{:-^70}\n", "");
}

PC::PC(unsigned int total_price,
       std::vector<std::unique_ptr<Component>> &&comps)
    : total_price_(total_price), components_(std::move(comps)) {}
