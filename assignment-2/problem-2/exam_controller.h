#pragma once

#include "exam_mediator.h"
#include <map>
#include <optional>
#include <unordered_map>

class ExamController : public ExamMediator {
public:
  void notify(Student *sender, ReexamineRequestEvent event) override;
  void notify(Teacher *sender, ReexamineResultEvent event) override;
  void notify(Teacher *sender, ResultEvent event) override;

  void register_student(std::shared_ptr<Student> student) override;
  void register_teacher(std::shared_ptr<Teacher> teacher) override;

  void check();
  void publish_results();

private:
  /* scripts indexed by (course_id, student_id) */
  std::map<std::pair<int, int>, Script> scripts_;
  /* students indexed by student id */
  std::unordered_map<int, std::shared_ptr<Student>> students_;
  /* teachers indexed by teacher id */
  std::unordered_map<int, std::shared_ptr<Teacher>> teachers_;
  /* examiners indexed by course id */
  std::unordered_map<int, std::shared_ptr<Teacher>> examiners_;
};