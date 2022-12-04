#pragma once

#include "component.h"

class MotherBoard : public Component {
public:
  MotherBoard();

private:
  unsigned int dimm_slots_;
};
