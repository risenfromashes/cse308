#pragma once

#include <initializer_list>
#include <memory>
#include <vector>

#include "exam_mediator.h"
#include "script.h"

class Teacher : public std::enable_shared_from_this<Teacher> {
public:
  Teacher(int id, std::shared_ptr<ExamMediator> mediator = nullptr);

  int id() { return id_; }
  void receive_script(Script script);
  void receive_scripts(std::initializer_list<Script> scripts);
  void send_result();
  void reexamine(Script *script);

private:
  /* teacher id */
  int id_;
  std::vector<Script> scripts_;
  std::weak_ptr<ExamMediator> controller_;
};