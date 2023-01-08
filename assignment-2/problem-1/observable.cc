#include "observable.h"

#include <algorithm>

void Observable::subscribe(std::shared_ptr<Observer> observer) {
  suscribers_.push_back(observer);
}

void Observable::unsubscribe(std::shared_ptr<Observer> observer) {
  auto itr = std::lower_bound(suscribers_.begin(), suscribers_.end(), observer);
  if (*itr == observer) {
    suscribers_.erase(itr);
  }
}

void Observable::update() {
  for (auto sus : suscribers_) {
    sus->notify();
  }
}
