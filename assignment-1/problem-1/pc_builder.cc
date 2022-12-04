#include "pc_builder.h"
#include "cooler.h"
#include "cpu.h"
#include "dvddrive.h"
#include "hdd.h"
#include "motherboard.h"
#include <algorithm>
#include <fmt/format.h>
#include <memory>

PC PCBuilder::build() {
  auto price = calc_price();
  return PC(price, std::move(components_));
}

std::unique_ptr<PC> PCBuilder::build_unique() {
  auto price = calc_price();
  return std::unique_ptr<PC>(new PC(price, std::move(components_)));
}

unsigned int PCBuilder::calc_price() {
  unsigned int price = 70000;
  for (auto &c : components_) {
    price += c->price();
  }
  return price;
}

void PCBuilder::add_motherboard() {
  components_.push_back(std::make_unique<MotherBoard>());
}

void PCBuilder::add_hdd() {
  components_.push_back(std::make_unique<HardDiskDrive>());
}

void I5PCBuilder::add_cpu() {
  components_.push_back(std::make_unique<IntelG11I5>());
}

void I5PCBuilder::add_cooler() {
  components_.push_back(std::make_unique<CPUCooler>());
}

void I5PCBuilder::add_dvddrive() {}

void I7PCBuilder::add_cpu() {
  components_.push_back(std::make_unique<IntelG11I7>());
}

void I7PCBuilder::add_cooler() {
  components_.push_back(std::make_unique<LiquidCooler>());
}

void I7PCBuilder::add_dvddrive() {}

void I9PCBuilder::add_cpu() {
  components_.push_back(std::make_unique<IntelG11I9>());
}

void I9PCBuilder::add_cooler() {}

void I9PCBuilder::add_dvddrive() {
  components_.push_back(std::make_unique<DVDDrive>());
}

void GamingPCBuilder::add_cpu() {
  components_.push_back(std::make_unique<AMDR75700X>());
}

void GamingPCBuilder::add_cooler() {}

void GamingPCBuilder::add_dvddrive() {}
