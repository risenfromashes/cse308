#pragma once

#include <fmt/format.h>

class Engine {
public:
  std::string_view type() const { return type_; }

protected:
  Engine() = default;

  void set_type(std::string type) { type_ = type; }

private:
  std::string type_;
};

class ElectricEngine : public Engine {
public:
  ElectricEngine();
};

class HydrogenFuelCellEngine : public Engine {
public:
  HydrogenFuelCellEngine();
};
