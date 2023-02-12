#include "stuff.h"
#include "company.h"

Stuff::Stuff(std::string name, Role role)
    : name_(std::move(name)), role_(role) {}

Stuff::Stuff(std::string name, Role role, std::string project_name)
    : name_(std::move(name)), role_(role),
      project_name_(std::move(project_name)) {}

void Stuff::remove() {
  recursive_remove();
  parent_->remove_child(this);
}

std::string_view Stuff::role_str(Role role) {
  switch (role) {
  case Role::MANAGER:
    return "Project Manager";
  case Role::DEVELOPER:
    return "Software Developer";
  }
  return "";
}

void Stuff::print_initials() {
  fmt::print("Name: {}\n", name_);
  fmt::print("Role: {}\n", role_str(role_));
  fmt::print("Current Project: {}\n", project_name_);
}

Manager::Manager(Company *company, std::string name, std::string project_name)
    : Stuff(name, Role::MANAGER, project_name) {
  parent_ = company;
  company->add_child(this);
}

void Manager::print_hierarchy(int depth) {
  for (int i = 0; i < depth; i++)
    fmt::print("\t");
  fmt::print("- {} ({})\n", name_, project_name_);
  for (auto &c : developers_) {
    c->print_hierarchy(depth + 1);
  }
}

void Manager::remove_child(Component *c) {
  for (int i = 0; i < developers_.size(); i++) {
    if ((Component *)developers_[i] == c) {
      developers_.erase(developers_.begin() + i);
      return;
    }
  }
}

void Manager::recursive_remove() {
  for (auto &c : developers_) {
    c->recursive_remove();
  }
  developers_.clear();
  fmt::print("Manager {} has been removed.\n", name_);
}

void Manager::add_child(Component *c) {
  developers_.push_back(dynamic_cast<Developer *>(c));
}

void Manager::print_details() {
  print_initials();
  fmt::print("Number of Supervisees: {}\n", developers_.size());
}

Company *Manager::company() { return dynamic_cast<Company *>(parent_); }

Developer::Developer(Manager *manager, std::string name)
    : Stuff(std::move(name), Role::DEVELOPER,
            std::string(manager->project_name())) {
  parent_ = manager;
  manager->add_child(this);
}

void Developer::print_hierarchy(int depth) {
  for (int i = 0; i < depth; i++)
    fmt::print("\t");
  fmt::print("- {}\n", name_);
}

void Developer::remove_child(Component *c) {
  assert(false && "Developer cannot have supervisee.");
}

void Developer::add_child(Component *c) {
  assert(false && "Developer cannot have supervisee.");
}

void Developer::print_details() { print_initials(); }

Manager *Developer::manager() { return dynamic_cast<Manager *>(parent_); }

void Developer::recursive_remove() {
  fmt::print("Developer {} has been removed.\n", name_);
}
