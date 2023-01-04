#pragma once

#include <memory>
#include <vector>

#include "resultinfo.h"
#include "script.h"

struct Event {};

struct ResultEvent : public Event {
  std::vector<Script> scripts;
  std::vector<float> marks;
};

struct ReexamineRequestEvent : public Event {
  int course_id;
};

struct ReexamineResultEvent : public Event {
  int student_id;
  float prev_mark;
  ResultInfo result;
};