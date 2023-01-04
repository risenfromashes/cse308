#include "exam_controller.h"

#include <cctype>
#include <fmt/format.h>
#include <iostream>

#include "student.h"
#include "teacher.h"

int main() {
  auto controller = std::make_shared<ExamController>();
  std::unordered_map<int, std::shared_ptr<Student>> students;
  std::unordered_map<int, std::shared_ptr<Teacher>> teachers;

  int n_teachers, n_students;

  fmt::print("Number of teachers: ");
  std::cin >> n_teachers;

  fmt::print("Number of students: ");
  std::cin >> n_students;

  for (int i = 1; i <= n_teachers; i++) {
    auto teacher = std::make_shared<Teacher>(i, controller);
    teachers[i] = teacher;
    controller->register_teacher(teacher);
  }

  for (int i = 1; i <= n_students; i++) {
    auto student = std::make_shared<Student>(i, controller);
    students[i] = student;
    controller->register_student(student);
  }

  for (int i = 1; i <= n_teachers; i++) {
    auto teacher = teachers[i - 1];
    for (int j = 1; j <= n_students; j++) {
      // associate course with teacher
      // and generate a script for each student for each course (teacher)
      auto script = Script(i, j);
      teacher->receive_script(std::move(script));
    }
    teacher->send_result();
  }

  for (;;) {
    fmt::print("Enter 'r' to request re-examination and 'q' to quit.");

    char ch;
    std::cin >> ch;
    ch = std::tolower(ch);

    if (ch == 'q') {
      break;
    }
    if (ch != 'r') {
      fmt::print("Invalid command '{}'", ch);
      continue;
    }

    // re-examination requested
    int sid, cid;

    fmt::print("Enter student ID: ");
    std::cin >> sid;
    if (!students.contains(sid)) {
      fmt::print("Invalid student ID\n");
      continue;
    }

    fmt::print("Enter course ID: ");
    std::cin >> cid;
    if (!teachers.contains(cid)) {
      fmt::print("Invalid course ID\n");
      continue;
    }

    auto student = students[sid];
    student->request_reexamination(cid);
  }
}
