#include "abc_server.h"
#include <random>

std::string_view to_str(ServerState state) {
  switch (state) {
  case ServerState::OPERATIONAL:
    return "operational";
  case ServerState::PARTIALLY_DOWN:
    return "partially down";
  case ServerState::FULLY_DOWN:
    return "fully down";
  }
  return "";
}

ABCServer::ABCServer() { prev_state_ = state_ = ServerState::OPERATIONAL; }

void ABCServer::change_state(ServerState next_state) {
  prev_state_ = state_;
  state_ = next_state;
  notify_all();
}

float ABCServer::bill() {
  static std::random_device rd;
  static std::mt19937 rng(rd());
  static std::uniform_real_distribution<float> dist(0, 10e3);

  return dist(rng);
}
