#include "gpu.h"

GPU::GPU() { set_type(Component::Type::GPU); }

GPU2GB::GPU2GB() {
  set_model("2 GB Graphics Card");
  set_price(6500);
}

GPU4GB::GPU4GB() {
  set_model("4 GB Graphics Card");
  set_price(7600);
}
