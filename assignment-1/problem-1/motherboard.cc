#include "motherboard.h"

MotherBoard::MotherBoard() {
  set_price(0); // included in base price
  set_type(Component::Type::MOBO);
  set_model("Generic Motherboard");
}
