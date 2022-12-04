#pragma once

#include "component.h"

class RAM : public Component {
protected:
  RAM();
};

class RAM8GB2666 : public RAM {
public:
  RAM8GB2666();
};

class RAM8GB3200 : public RAM {
public:
  RAM8GB3200();
};
