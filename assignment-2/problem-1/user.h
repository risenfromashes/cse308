#pragma once

#include <string>

#include "abc_server.h"
#include "observer.h"

class User : public Observer {
public:
  int id() { return id_; }
  std::string_view name() { return name_; }
  std::shared_ptr<ABCServer> server();

  virtual void notify() override;
  virtual ~User() = default;

  virtual void state_changed(ServerState f, ServerState t) = 0;

protected:
  User(int id, std::string name);
  int id_;
  std::string name_;
};

class RegularUser : public User {
public:
  RegularUser(int id, std::string name);
  void state_changed(ServerState f, ServerState t) override;

private:
  bool full_paying_ = false;
};

class PremiumUser : public User {
public:
  PremiumUser(int id, std::string name);
  void state_changed(ServerState f, ServerState t) override;

private:
  bool use_both_servers_ = false;
};
