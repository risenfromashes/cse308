#pragma once

#include <memory>
#include <unordered_map>

class State;
class Context;

template <class T>
concept ValidState =
    std::derived_from<T, State> && std::constructible_from<T, Context *>;

class Context {
public:
  template <ValidState T> T *get_state_instance() {
    const char *state_name = typeid(T).name();
    auto [itr, inserted] = state_instances_.try_emplace(state_name, this);
    if (inserted) {
      return itr->second.get();
    } else {
      return state_instances_.at(state_name);
    }
  }

  State *current_state() { return state_; }

protected:
  /* state registry to only initialize states once */
  std::unordered_map<const char *, std::unique_ptr<State>> state_instances_;
  /* current state */
  State *state_ = nullptr;
};
