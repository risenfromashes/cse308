#pragma once

#include "component.h"

/* Abstract Coole class */
class Cooler : public Component {
protected:
  Cooler();
};

class CPUCooler : public Cooler {
public:
  CPUCooler();
};

class LiquidCooler : public Cooler {
public:
  LiquidCooler();
};
