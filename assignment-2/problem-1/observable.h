#pragma once

#include <memory>
#include <vector>

#include "observer.h"

class Observable {
public:
  void subscribe(std::shared_ptr<Observer> observer);
  void unsubscribe(std::shared_ptr<Observer> observer);

  void notify_all();

private:
  std::vector<std::shared_ptr<Observer>> suscribers_;
};
