#include "ram.h"

RAM::RAM() { set_type(Component::Type::RAM); }

RAM8GB2666::RAM8GB2666() {
  set_price(2620);
  set_model("8GB 2666 MHz DDR4 RAM");
}

RAM8GB3200::RAM8GB3200() {
  set_price(2620);
  set_model("8GB 3200 MHz DDR4 RAM");
}
