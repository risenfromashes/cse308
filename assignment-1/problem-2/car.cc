#include "car.h"

void Car::print_details() {
  fmt::print("{:<25}: {}\n", "Company", company_);
  fmt::print("{:<25}: {}\n", "Manufacturing Company", country_);
  fmt::print("{:<25}: {}\n", "Engine Type", engine_->type());
  fmt::print("{:<25}: {}\n", "Drive Train Type", drivetrain_->type());
  fmt::print("{:<25}: {}\n", "Color", color_);
}

BMW::BMW() {
  company_ = "BMW";
  country_ = "Germany";
  engine_ = std::make_unique<ElectricEngine>();
  drivetrain_ = std::make_unique<RearWheelDriveTrain>();
  color_ = "Black";
}

Toyota::Toyota() {
  company_ = "Toyota";
  country_ = "Japan";
  engine_ = std::make_unique<HydrogenFuelCellEngine>();
  drivetrain_ = std::make_unique<RearWheelDriveTrain>();
  color_ = "Red";
}

Tesla::Tesla() {
  company_ = "Tesla";
  country_ = "United States";
  engine_ = std::make_unique<ElectricEngine>();
  drivetrain_ = std::make_unique<AllWheelDriveTrain>();
  color_ = "White";
}
