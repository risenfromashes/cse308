#include "dvddrive.h"

DVDDrive::DVDDrive() {
  set_price(0); // included in base price
  set_type(Component::Type::DVD);
  set_model("DVD Drive");
}
