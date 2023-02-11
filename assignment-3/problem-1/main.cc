#include <memory>
#include <vector>

#include "imposter_adapter.h"

int main() {
  std::vector<std::unique_ptr<CrewMate>> crew;

  /* create objects */
  for (int i = 0; i < 4; i++) {
    crew.push_back(std::make_unique<Crew>());
  }
  for (int i = 0; i < 2; i++) {
    crew.push_back(std::make_unique<ImposterAdapter>());
  }

  /* play */
  for (int i = 0; i < 6; i++) {
    crew[i]->intersteller_study();
    crew[i]->perform_maintenance();
  }
}