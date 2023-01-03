#pragma once

#include "exam_mediator.h"

class ExamController : public ExamMediator{
  
  public:
    void notify(std::shared_ptr<Student> sender, ReexamineRequestEvent event) override;
    void notify(std::shared_ptr<Teacher> sender, ReexamineResultEvent event) override;
    void notify(std::shared_ptr<Teacher> sender, ResultEvent event) override;
    void register_student(std::shared_ptr<Student> student) override;
    void register_teacher(std::shared_ptr<Teacher> teacher) override;
};