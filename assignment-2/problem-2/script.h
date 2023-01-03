#pragma once

class Script {
public:
  static constexpr int question_count = 8;
  static constexpr float total_marks = 210;

  Script(int cid, int sid, int eid);

  float total() { return total_; }
  void set_total(float total) { total_ = total; }

  float calc_total();

  int course_id() { return course_id_; }
  int student_id() { return student_id_; }
  int examiner_id() { return examiner_id_; }

private:
  float total_;
  float marks_[question_count];

	int id_;
  int course_id_;
  int student_id_;
  int examiner_id_;

	inline static int last_id_ = 0;
};
