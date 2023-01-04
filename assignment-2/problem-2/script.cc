#include "script.h"
#include "resultinfo.h"
#include <random>

Script::Script(int cid, int sid)
    : id_(last_id_++), course_id_(cid), student_id_(sid) {}

void Script::evaluate(int teacher_id) {
  examiner_id_ = teacher_id;

  using dist_t = std::uniform_real_distribution<float>;
  static std::mt19937 rng;

  static dist_t dist_marks(0, total_marks / question_count);
  static dist_t dist_error(0, 1);

  for (int i = 0; i < question_count; i++) {
    marks_[i] = dist_marks(rng);
  }

  auto actual_total = calc_total();
  dist_t dist_total(0, actual_total);

  /* 55% probability of mistake + (at least once every 5 id) */
  if (dist_error(rng) < 0.55 || id_ % 5 == 0) {
    total_ = dist_total(rng);
  } else {
    total_ = actual_total;
  }
}

ResultInfo Script::result() {
  return {.course_id = course_id_, .examiner_id = examiner_id_, .mark = total_};
}

void Script::reevaluate(int teacher_id) {
  examiner_id_ = teacher_id;
  total_ = calc_total();
}

float Script::calc_total() {
  float ret = 0;
  for (int i = 0; i < question_count; i++) {
    ret += marks_[i];
  }
  return ret;
}
