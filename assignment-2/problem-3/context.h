#pragma once

#include <memory>
#include <unordered_map>

#include <cassert>

#include "state.h"

class Context;

template <class T>
concept ValidState =
    std::derived_from<T, State> && std::constructible_from<T, Context *>;

class Context {
public:
  template <ValidState T> T *get_state_instance() {
    const char *state_name = typeid(T).name();
    State *state;
    if (state_instances_.contains(state_name)) {
      state = state_instances_.at(state_name).get();
    } else {
      auto [itr, inserted] =
          state_instances_.emplace(state_name, std::make_unique<T>(this));
      assert(inserted);
      state = itr->second.get();
    }
    state->reset();
    return dynamic_cast<T *>(state);
  }

  State *current_state() { return state_; }
  void next_state(State *state) { state_ = state; }

protected:
  /* state registry to only initialize states once */
  std::unordered_map<const char *, std::unique_ptr<State>> state_instances_;
  /* current state */
  State *state_ = nullptr;
};
