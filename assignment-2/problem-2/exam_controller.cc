#include "exam_controller.h"

#include "student.h"
#include "teacher.h"
#include <fmt/core.h>
#include <random>

void ExamController::notify(Student *sender, ReexamineRequestEvent event) {
  if (!examiners_.contains(event.course_id)) {
    fmt::print("Error: Re-examination requested for invalid course\n");
    return;
  }
  if (!scripts_.contains({event.course_id, sender->id()})) {
    fmt::print("Error: Re-examination requested for invalid script\n");
    return;
  }

  auto examiner = examiners_[event.course_id];
  auto script = &scripts_[{event.course_id, sender->id()}];

  examiner->reexamine(script);
}

void ExamController::notify(Teacher *sender, ReexamineResultEvent event) {
  if (!students_.contains(event.student_id)) {
    fmt::print("Error: Re-examination result received for invalid student\n");
  }

  auto student = students_[event.student_id];

  if (event.prev_mark == event.result.mark) {
    fmt::print("[Exam Controller] Mark unchanged for student #{} in course #{} "
               "after re-examination\n",
               event.student_id, event.result.course_id);
  } else {
    fmt::print("[Exam Controller] Mark changed ({} => {}) for student #{} in "
               "course #{} "
               "after re-examination\n",
               event.prev_mark, event.result.mark, event.student_id,
               event.result.course_id);
  }

  student->receive_reresult(event.result);
}

void ExamController::notify(Teacher *sender, ResultEvent event) {
  for (auto &script : event.scripts) {
    fmt::print("[Exam Controller] Student #{} obtained {} in course #{}\n",
               script.student_id(), script.total(), script.course_id());

    examiners_[script.course_id()] = sender->shared_from_this();
    scripts_[{script.course_id(), script.student_id()}] = std::move(script);
  }
}

void ExamController::check() {
  static std::mt19937 rng;
  static std::uniform_real_distribution<double> dist(0, 1);
  for (auto &[_, script] : scripts_) {
    // 55% probabilty of controller correcting mistakes
    if (dist(rng) > 0.55) {
      continue;
    }

    float actual_total = script.calc_total();
    if (script.total() != actual_total) {
      float old_total = script.total();
      script.set_total(actual_total);

      fmt::print("[Exam Controller] Correction of marks for student #{} in "
                 "course #{} ({} => {})\n",
                 script.student_id(), script.course_id(), old_total,
                 actual_total);
    }
  }
}

void ExamController::publish_results() {
  for (auto &[_, script] : scripts_) {
    if (!students_.contains(script.student_id())) {
      fmt::print("Error: Invalid student-id in script #{}\n", script.id());
      continue;
    }

    auto student = students_[script.student_id()];
    student->receive_result(script.result());
  }
}

void ExamController::register_student(std::shared_ptr<Student> student) {
  if (students_.contains(student->id())) {
    fmt::print("Error: Examinee with ID #{} already exists in registry\n",
               student->id());
    return;
  }
  students_[student->id()] = student;
}

void ExamController::register_teacher(std::shared_ptr<Teacher> teacher) {
  if (teachers_.contains(teacher->id())) {
    fmt::print("Error: Examiner with ID #{} already exists in registry\n",
               teacher->id());
    return;
  }
  teachers_[teacher->id()] = teacher;
}
