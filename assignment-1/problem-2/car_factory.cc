#include "car_factory.h"

std::unique_ptr<Car> CarFactory::create(std::string_view continent) {
  if (continent == "Asia") {
    return std::make_unique<Toyota>();
  } else if (continent == "Europe") {
    return std::make_unique<BMW>();
  } else if (continent == "United States") {
    return std::make_unique<Tesla>();
  }
  return nullptr;
}
