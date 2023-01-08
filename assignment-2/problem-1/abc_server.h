#pragma once

#include "observable.h"

enum class ServerState { OPERATIONAL, PARTIALLY_DOWN, FULLY_DOWN };

std::string_view to_str(ServerState state);

class ABCServer : public Observable {
public:
  ABCServer();

  ServerState state() { return state_; }
  ServerState previous_state() { return prev_state_; }

  void change_state(ServerState next_state);

  float bill();

private:
  ServerState state_;
  ServerState prev_state_;
};
