#pragma once

#include <memory>
#include <string>

#include "drivetrain.h"
#include "engine.h"

class Car {
public:
  void print_details();

protected:
  Car() = default;

  std::string company_;
  std::string country_;
  std::unique_ptr<Engine> engine_;
  std::unique_ptr<DriveTrain> drivetrain_;
  std::string color_;
};

class BMW : public Car {
public:
  BMW();
};

class Toyota : public Car {
public:
  Toyota();
};

class Tesla : public Car {
public:
  Tesla();
};
