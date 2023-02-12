#pragma once

#include "component.h"

#include <cassert>
#include <fmt/format.h>
#include <string>
#include <string_view>
#include <vector>

class Company;
class Developer;

class Stuff : public Component {
public:
  enum class Role { MANAGER, DEVELOPER };

  Stuff(std::string name, Role role);
  Stuff(std::string name, Role role, std::string project_name);
  virtual ~Stuff() = default;

  std::string name() { return name_; }
  std::string project_name() { return project_name_; }

  void remove() override;

protected:
  virtual void recursive_remove() = 0;
  std::string_view role_str(Role role);
  void print_initials();

  Component *parent_;
  std::string name_;
  std::string project_name_;
  Role role_;
};

class Manager : public Stuff {

public:
  Manager(Company *company, std::string name, std::string project_name);
  void print_hierarchy(int depth) override;
  void remove_child(Component *c) override;
  void recursive_remove() override;
  void add_child(Component *c) override;
  void print_details() override;
  Company *company();

private:
  std::vector<Developer *> developers_;
};

class Developer : public Stuff {

public:
  Developer(Manager *manager, std::string name);
  void print_hierarchy(int depth) override;
  void remove_child(Component *c) override;
  void recursive_remove() override;
  void add_child(Component *c) override;
  void print_details() override;
  Manager *manager();
};
