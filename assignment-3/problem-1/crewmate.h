#pragma once

class CrewMate {
public:
  virtual void intersteller_study() = 0;
  virtual void perform_maintenance() = 0;
};

class Crew : public CrewMate {
public:
  void intersteller_study() override;
  void perform_maintenance() override;
};
