#pragma once

#include "resultinfo.h"
class Script {
public:
  static constexpr int question_count = 8;
  static constexpr float total_marks = 210;

  Script(int cid, int sid);

  void evaluate(int teacher_id);
  void reevaluate(int teacher_id);

  float calc_total();

  float total() { return total_; }
  void set_total(float total) { total_ = total; }

  int id() { return id_; }
  int course_id() { return course_id_; }
  int student_id() { return student_id_; }
  int examiner_id() { return examiner_id_; }

  ResultInfo result();

private:
  float total_;
  float marks_[question_count];

  int id_;
  int course_id_;
  int student_id_;
  int examiner_id_ = -1;

  inline static int last_id_ = 0;
};
