#pragma once

#include <memory>

class Observable;

class Observer {
  friend class Observable;

public:
  virtual void notify() = 0;
  virtual ~Observer() = default;

  std::shared_ptr<Observable> observable() { return observable_; }

private:
  void set_observable(std::shared_ptr<Observable> observable) {
    observable_ = observable;
  }

  std::shared_ptr<Observable> observable_;
};
