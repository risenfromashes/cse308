#include "student.h"
#include <memory>

#include <fmt/format.h>

Student::Student(int id, std::shared_ptr<ExamMediator> cont) : id_(id) {
  if (cont) {
    controller_ = cont;
  }
}

void Student::receive_result(ResultInfo event) {}

void Student::request_reexamination(int course_id) {
  if (!marks_.contains(course_id)) {
    fmt::print("Error: Invalid course Id provided\n");
  } else {
    fmt::print("Re-examine requested from student #{} for course #{}\n", id_,
               course_id);
    auto cont = controller_.lock();
    if (cont) {
      controller_.lock()->notify(shared_from_this(), {.course_id = course_id});
    } else {
      fmt::print("Error: No mediator/controller set\n");
    }
  }
}