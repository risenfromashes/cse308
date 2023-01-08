#include "user.h"

#include <fmt/core.h>
#include <iostream>

User::User(int id, std::string name) : id_(id), name_(std::move(name)) {}

std::shared_ptr<ABCServer> User::server() {
  return std::static_pointer_cast<ABCServer>(observable());
}

void User::notify() {
  auto f = server()->previous_state();
  auto t = server()->state();
  state_changed(f, t);
}

RegularUser::RegularUser(int id, std::string name)
    : User(id, std::move(name)) {}

PremiumUser::PremiumUser(int id, std::string name)
    : User(id, std::move(name)) {}

void RegularUser::state_changed(ServerState f, ServerState t) {
  fmt::print("\n[Regular User: {}]\n", name());
  fmt::print("Server state changed ({} => {})\n", to_str(f), to_str(t));
  int in;
  switch (f) {
  case ServerState::OPERATIONAL:
    switch (t) {
    case ServerState::PARTIALLY_DOWN:
      fmt::print("Please select one of the following options:\n");
      fmt::print("\t1. Pay $20 to enjoy full functionality using DEF server\n");
      fmt::print("\t2. Continue with limited functionality\n");
      std::cin >> in;
      full_paying_ = in == 1;
      if (full_paying_) {
        fmt::print("Your data is being copied to DEF server. Enjoy full "
                   "functionalities.\n");
      } else {
        fmt::print("You will continue to get partial functionalities until our "
                   "servers are fully operational again\n");
      }
      break;
    case ServerState::FULLY_DOWN:
      fmt::print("Please select one of the following options:\n");
      fmt::print("\t1. Pay $20 to enjoy full functionality using DEF server\n");
      fmt::print("\t2. Wait for server to become operational\n");
      std::cin >> in;
      full_paying_ = in == 1;
      if (full_paying_) {
        fmt::print("Your data is being copied to DEF server. Enjoy full "
                   "functionalities\n");
      } else {
        fmt::print("Please wait for our server to become operational again\n");
      }
      break;
    default:
      break;
    }
    break;
  case ServerState::PARTIALLY_DOWN:
    switch (t) {
    case ServerState::OPERATIONAL:
      if (full_paying_) {
        fmt::print("Your bill since last server state change: ${:.2f}\n",
                   server()->bill());
      }
      break;
    default:
      break;
    }
    break;
  case ServerState::FULLY_DOWN:
    switch (t) {
    case ServerState::OPERATIONAL:
      if (full_paying_) {
        fmt::print("Your bill since last server state change: ${:.2f}\n",
                   server()->bill());
      }
      break;
    default:
      break;
    }
    break;
  }
}

void PremiumUser::state_changed(ServerState f, ServerState t) {
  fmt::print("\n[Premium User: {}]\n", name());
  fmt::print("Server state changed ({} => {})\n", to_str(f), to_str(t));
  int in;
  switch (f) {
  case ServerState::OPERATIONAL:
    switch (t) {
    case ServerState::PARTIALLY_DOWN:
      fmt::print("Please select one of the following options:\n");
      fmt::print("\t1. Share service between ABC server and DEF server\n");
      fmt::print("\t2. Use service only from DEF server\n");
      std::cin >> in;
      use_both_servers_ = in == 1;
      if (use_both_servers_) {
        fmt::print("You will now receive service from both servers\n");
      } else {
        fmt::print("You will now receive service only from DEF server\n");
      }
      break;
    case ServerState::FULLY_DOWN:
      fmt::print("Service is now being provided by our partner DEF\n");
      break;
    default:
      break;
    }
    break;
  case ServerState::PARTIALLY_DOWN:
    switch (t) {
    case ServerState::FULLY_DOWN:
      if (use_both_servers_) {
        fmt::print("You will now receive service entirely from DEF server\n");
      }
      break;
    default:
      break;
    }
    break;
  case ServerState::FULLY_DOWN:
    break;
  }
}
