#include "student.h"
#include <memory>

#include <fmt/format.h>

Student::Student(int id, std::shared_ptr<ExamMediator> cont)
    : id_(id), controller_(cont) {}

void Student::receive_result(ResultInfo result) {
  fmt::print("[Student #{:>6}] Received {:>5.1f} in course #{}\n", id_,
             result.mark, result.course_id);
  marks_[result.course_id] = result.mark;
}

void Student::receive_reresult(ResultInfo result) {
  if (!marks_.contains(result.course_id)) {
    fmt::print("Error: Invalid re-examination result received\n");
    return;
  }
  float old_mark = marks_[result.course_id];
  if (old_mark != result.mark) {
    fmt::print(
        "[Student #{:>6}] Mark in course #{} updated ({:>5.1f} => {:>5.1f})\n",
        id_, result.course_id, old_mark, result.mark);

    marks_[result.course_id] = result.mark;
  } else {
    fmt::print("[Student #{:>6}] Mark in course #{} remained same after "
               "re-examination\n",
               id_, result.course_id);
  }
}

void Student::request_reexamination(int course_id) {
  if (!marks_.contains(course_id)) {
    fmt::print("Error: Invalid course Id provided\n");
  } else {
    fmt::print("[Student #{:>6}] Re-examine requested for course #{}\n", id_,
               course_id);

    auto cont = controller_.lock();
    if (cont) {
      cont->notify(this, {.course_id = course_id});
    } else {
      fmt::print("Error: No mediator/controller set\n");
    }
  }
}