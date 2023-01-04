#include "script.h"
#include "resultinfo.h"
#include <cmath>
#include <ctime>
#include <random>

Script::Script(int cid, int sid)
    : id_(last_id_++), course_id_(cid), student_id_(sid) {}

void Script::evaluate(int teacher_id) {
  examiner_id_ = teacher_id;

  using uniform_t = std::uniform_real_distribution<float>;
  using normal_t = std::normal_distribution<float>;

  const float marks_per_question = total_marks / question_count;
  static std::random_device rd;
  static std::mt19937 rng(rd());

  static normal_t dist_marks(0.7 * marks_per_question,
                             0.2 * marks_per_question);

  static uniform_t dist_error(0, 1);
  static normal_t dist_total(1, 0.2);

  for (int i = 0; i < question_count; i++) {
    marks_[i] = std::min(dist_marks(rng), marks_per_question);
  }

  auto actual_total = calc_total();

  /* 55% probability of mistake + (at least once every 5 id) */
  if (dist_error(rng) < 0.55 || id_ % 5 == 0) {
    total_ = std::min(dist_total(rng) * actual_total, total_marks);
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
