#pragma once

#include <memory>

#include "event.h"

class Student;
class Teacher;

class ExamMediator {
  public:
    virtual void notify(std::shared_ptr<Student> sender, ReexamineRequestEvent event) = 0;

    virtual void notify(std::shared_ptr<Teacher> sender, ReexamineResultEvent event) = 0;
    virtual void notify(std::shared_ptr<Teacher> sender, ReexamineRequestEvent event) = 0;

    virtual void register_student(std::shared_ptr<Student> student) = 0;
    virtual void register_teacher(std::shared_ptr<Teacher> teacher) = 0;
};