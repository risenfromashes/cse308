#pragma once

#include "crewmate.h"
#include "imposter.h"

class ImposterAdapter : public CrewMate {
public:
  void intersteller_study() override;
  void perform_maintenance() override;

private:
  Imposter imposter_;
};
