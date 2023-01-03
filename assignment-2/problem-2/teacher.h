#pragma once

#include <memory>
#include <vector>

#include "exam_mediator.h"
#include "script.h"

class Teacher {
public:
  Teacher(int id, std::shared_ptr<ExamMediator> mediator = nullptr);

  void send_result();
  void reexamine(std::shared_ptr<Script> script);

private:
  /* teacher id */
  int id;
  std::vector<Script> scripts_;
  std::weak_ptr<ExamMediator> controller_;
};