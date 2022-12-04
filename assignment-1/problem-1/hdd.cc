#include "hdd.h"

HardDiskDrive::HardDiskDrive() {
  set_price(0); // included in base price
  set_type(Component::Type::HDD);
  set_model("1 TB HDD");
}
