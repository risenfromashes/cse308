#pragma once

#include <memory>

struct Event {};

struct ResultEvent : public Event {};

struct ReexamineRequestEvent : public Event {
  int course_id;
};

struct ReexamineResultEvent: public Event {};