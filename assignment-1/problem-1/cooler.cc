#include "cooler.h"

Cooler::Cooler() { set_type(Component::Type::COOLER); }

CPUCooler::CPUCooler() {
  set_price(36000);
  set_model("CPU Cooler");
}

LiquidCooler::LiquidCooler() {
  set_price(17000);
  set_model("Liequid Cooler");
}
