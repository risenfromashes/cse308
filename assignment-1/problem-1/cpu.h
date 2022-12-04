#pragma once

#include "component.h"

class CPU : public Component {
protected:
  CPU();
};

class AMDR75700X : public CPU {
public:
  AMDR75700X();
};

class IntelG11I5 : public CPU {
public:
  IntelG11I5();
};

class IntelG11I7 : public CPU {
public:
  IntelG11I7();
};

class IntelG11I9 : public CPU {
public:
  IntelG11I9();
};
