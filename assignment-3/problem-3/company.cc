#include "company.h"
#include "stuff.h"

Company::Company(std::string name) : name_(std::move(name)) {}

void Company::print_hierarchy(int depth) {
  fmt::print("- {}\n", name_);
  for (auto &c : managers_) {
    c->print_hierarchy(depth + 1);
  }
}

void Company::print_details() {
  fmt::print("Company Name: {}\n", name_);
  fmt::print("Number of Projects: {}\n", managers_.size());
}

void Company::remove_child(Component *c) {
  for (int i = 0; i < managers_.size(); i++) {
    if ((Component *)managers_[i] == c) {
      managers_.erase(managers_.begin() + i);
      return;
    }
  }
}

void Company::remove() {
  for (auto &m : managers_) {
    m->recursive_remove();
  }
  managers_.clear();
  fmt::print("Company {} has been removed.\n", name_);
}

void Company::add_child(Component *c) {
  managers_.push_back(dynamic_cast<Manager *>(c));
}
