#pragma once

#include "observer.h"

enum class ServerState { OPERATIONAL, PARTIALLY_DOWN, FULLY_DOWN };

class ABCCompany : public Observer {
public:
  ABCCompany();

private:
  ServerState curr_state_;
  ServerState prev_state_;
};
