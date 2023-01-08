#include "abc_server.h"
#include "user.h"
#include <fmt/core.h>
#include <iostream>

int main() {
  auto server = std::make_shared<ABCServer>();
  auto user1 = std::make_shared<RegularUser>(1, "John");
  auto user2 = std::make_shared<PremiumUser>(2, "Doe");
  server->subscribe(user1);
  server->subscribe(user2);
  for (;;) {
    char in;
    fmt::print("\nEnter next server state: (or 'q' to quit)\n");
    fmt::print("\t1. Operational State\n");
    fmt::print("\t2. Partially Down State\n");
    fmt::print("\t3. Fully Down State\n");
    std::cin >> in;
    switch (in) {
    case '1':
      server->change_state(ServerState::OPERATIONAL);
      break;
    case '2':
      server->change_state(ServerState::PARTIALLY_DOWN);
      break;
    case '3':
      server->change_state(ServerState::FULLY_DOWN);
      break;
    case 'q':
      return 0;
    }
  }
}
