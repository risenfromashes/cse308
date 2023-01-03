#pragma once

#include <memory>
#include <unordered_map>
#include "event.h"
#include "exam_mediator.h"
#include "resultinfo.h"

class Student : std::enable_shared_from_this<Student> {
  public:
    Student(int id, std::shared_ptr<ExamMediator> cont = nullptr);
    void receive_result(ResultInfo result);
    void request_reexamination(int course_id);

  private:
    /* student id */
    int id_;
    /* <course_id, marks> */
    std::unordered_map<int, float> marks_;
    std::weak_ptr<ExamMediator> controller_;
};