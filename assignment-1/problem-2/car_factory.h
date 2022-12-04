#pragma once

#include "car.h"

class CarFactory {

public:
  std::unique_ptr<Car> create(std::string_view continent);
};
