#include "cpu.h"

CPU::CPU() { set_type(Component::Type::CPU); }

AMDR75700X::AMDR75700X() {
  set_price(28800);
  set_model("AMD Ryzen 7 5700X Processor");
}

IntelG11I5::IntelG11I5() {
  set_price(20000);
  set_model("Intel Core i5 11th Generation Processor");
}

IntelG11I7::IntelG11I7() {
  set_price(37000);
  set_model("Intel Core i7 11th Generation Processor");
}

IntelG11I9::IntelG11I9() {
  set_price(65000);
  set_model("Intel Core i9 11th Generation Processor");
}
