#include <iostream>

#include "car.h"
#include "car_factory.h"

char take_char() {
  static std::string line;
  std::getline(std::cin, line);
  return line.empty() ? 0 : line[0];
}

int main() {
  char c;
  for (;;) {
    fmt::print("Please choose your continental location:\n");
    fmt::print("1. Asia\n");
    fmt::print("2. Europe\n");
    fmt::print("3. United States\n");
    fmt::print("Select a number: [1-3] ");

    c = take_char();

    if (c < '1' || c > '3') {
      fmt::print("Please enter a valid number.\n");
    } else {
      break;
    }
  }

  std::string_view continent;
  switch (c) {
  case '1':
    continent = "Asia";
    break;
  case '2':
    continent = "Europe";
    break;
  case '3':
    continent = "United States";
    break;
  }

  CarFactory factory;
  std::unique_ptr<Car> car = factory.create(continent);

  fmt::print("{:=^50}\n", "");
  fmt::print("{:^50}\n", "Car Details");
  fmt::print("{:=^50}\n", "");
  car->print_details();
}
