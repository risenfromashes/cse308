#pragma once

#include "component.h"

class GPU : public Component {
protected:
  GPU();
};

class GPU2GB : public GPU {
public:
  GPU2GB();
};

class GPU4GB : public GPU {
public:
  GPU4GB();
};
