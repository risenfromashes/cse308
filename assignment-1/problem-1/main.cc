#include "gpu.h"
#include "pc_builder.h"
#include "pc_director.h"
#include <cassert>
#include <cctype>
#include <fmt/format.h>
#include <iostream>

char take_char() {
  static std::string line;
  std::getline(std::cin, line);
  return line.empty() ? 0 : std::tolower(line[0]);
}

void take_order() {
  char c;

  for (;;) {
    fmt::print("\nThe following base PC bundles are available:\n");
    fmt::print("1. AMD Ryzen 7 5700X Gaming PC\n");
    fmt::print("2. Intel Core-i5 11th Gen PC\n");
    fmt::print("3. Intel Core-i7 11th Gen PC\n");
    fmt::print("4. Intel Core-i9 11th Gen PC\n");
    fmt::print("Please select type [1-4] ");

    c = take_char();

    if (c == 'e') {
      fmt::print("You have to at least order one item to close order.\n");
    } else if (c < '1' || c > '4') {
      fmt::print("Invalid input. Please choose between 1 to 4.\n");
    } else {
      break;
    }
  }

  std::unique_ptr<PCBuilder> builder;
  switch (c) {
  case '1':
    builder = std::make_unique<GamingPCBuilder>();
    break;
  case '2':
    builder = std::make_unique<I5PCBuilder>();
    break;
  case '3':
    builder = std::make_unique<I7PCBuilder>();
    break;
  case '4':
    builder = std::make_unique<I9PCBuilder>();
    break;
  }

  PCDirector director(std::move(builder));
  director.configure_pc();

  for (;;) {
    fmt::print(
        "\nYou may add any of the following custom components to the base "
        "system.\n");
    fmt::print("1. 8 GB 2666 MHz DDR4 RAM\n");
    fmt::print("2. 8 GB 3200 MHz DDR4 RAM\n");
    fmt::print("3. 2 GB VRAM Graphics Card\n");
    fmt::print("4. 4 GB VRAM Graphics Card\n");
    fmt::print("Please choose [1-4] (Press E to finish order) ");

    c = take_char();
    if (c == 'e') {
      break;
    } else if (c == 'o') {
      fmt::print("You have to finish current order first.\n");
      fmt::print("Do you want to finish this order? [y/n] ");

      c = take_char();
      if (c == 'y') {
        break;
      } else if (c != 'n') {
        fmt::print("Invalid Input. Returning to order.\n");
      }
    } else if (c < '1' || c > '4') {
      fmt::print("Invalid input. Please choose between 1 to 4.\n");
    } else {
      switch (c) {
      case '1':
        director.add_ram<RAM8GB2666>();
        break;
      case '2':
        director.add_ram<RAM8GB3200>();
        break;
      case '3':
        director.add_gpu<GPU2GB>();
        break;
      case '4':
        director.add_gpu<GPU4GB>();
        break;
      }
    }
  }

  fmt::print("{:=^70}\n", "");
  fmt::print("{:^70}\n", "Order Summary");
  fmt::print("{:=^70}\n", "");

  PC pc = director.build();
  pc.print_details();
}

int main() {
  char c;
  for (;;) {
    fmt::print("\nPress O to start a new order. Enter Q to quit.\n");
    c = take_char();
    switch (c) {
    case 'q':
      fmt::print("\nThank you for using our service.\n");
      return 0;
    case 'o':
      take_order();
      break;
    case 'e':
      fmt::print("No ongoing order. Press O to start new order.\n");
      break;
    default:
      fmt::print("Invalid input.\n");
      break;
    }
  }
}
