#pragma once

#include <string>

class DriveTrain {
public:
  std::string_view type() const { return type_; }

protected:
  DriveTrain() = default;

  void set_type(std::string type) { type_ = type; }

private:
  std::string type_;
};

class RearWheelDriveTrain : public DriveTrain {
public:
  RearWheelDriveTrain();
};

class AllWheelDriveTrain : public DriveTrain {
public:
  AllWheelDriveTrain();
};
