#pragma once

class Component {
public:
  virtual void add_child(Component *c) = 0;
  virtual void remove_child(Component *c) = 0;
  virtual void remove() = 0;

  virtual void print_hierarchy(int depth = 0) = 0;
  virtual void print_details() = 0;

  virtual ~Component() = default;
};
