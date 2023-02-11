#include "imposter_adapter.h"

#include <iostream>

void ImposterAdapter::intersteller_study() {
  std::cout << "Studying intersteller objects" << std::endl;
  imposter_.sabotage();
}

void ImposterAdapter::perform_maintenance() {
  std::cout << "Performing spaceship maintenance tasks" << std::endl;
  imposter_.damage();
}
