#pragma once

#include <memory>
#include <vector>

#include "observer.h"

class Observable : public std::enable_shared_from_this<Observable> {
public:
  void subscribe(std::shared_ptr<Observer> observer);
  void unsubscribe(std::shared_ptr<Observer> observer);

  void notify_all();

private:
  std::vector<std::weak_ptr<Observer>> suscribers_;
};
