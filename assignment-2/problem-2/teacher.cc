#include "teacher.h"
#include <fmt/core.h>
#include <optional>

Teacher::Teacher(int id, std::shared_ptr<ExamMediator> cont)
    : id_(id), controller_(cont) {}

void Teacher::receive_script(Script script) {
  scripts_.push_back(std::move(script));
}

void Teacher::receive_scripts(std::initializer_list<Script> scripts) {
  std::move(scripts.begin(), scripts.end(), std::back_inserter(scripts_));
}

void Teacher::send_result() {
  std::vector<float> marks;

  for (auto &script : scripts_) {
    script.evaluate(id_);
    marks.push_back(script.total());
  }

  auto cont = controller_.lock();
  if (cont) {
    cont->notify(this, ResultEvent{.scripts = std::move(scripts_),
                                   .marks = std::move(marks)});
    scripts_.clear();
  } else {
    fmt::print("Error: Mediator/Controller not set\n");
  }
}

void Teacher::reexamine(Script *script) {
  float old_mark = script->total();
  script->reevaluate(id_);
  auto cont = controller_.lock();
  if (cont) {
    cont->notify(this, ReexamineResultEvent{.student_id = script->student_id(),
                                            .prev_mark = old_mark,
                                            .result = script->result()});
  } else {
    fmt::print("Error: Mediator/Controller not set\n");
  }
}