#include "observable.h"

#include <algorithm>

void Observable::subscribe(std::shared_ptr<Observer> observer) {
  observer->set_observable(shared_from_this());
  suscribers_.push_back(observer);
}

void Observable::unsubscribe(std::shared_ptr<Observer> observer) {
  for (auto itr = suscribers_.begin(); itr != suscribers_.end(); ++itr) {
    if (itr->lock() == observer) {
      suscribers_.erase(itr);
      break;
    }
  }
}

void Observable::notify_all() {
  for (auto &sus : suscribers_) {
    if (auto ptr = sus.lock()) {
      ptr->notify();
    }
  }
}
