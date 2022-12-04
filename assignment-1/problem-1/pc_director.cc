#include "pc_director.h"
#include <cassert>

PCDirector::PCDirector(std::unique_ptr<PCBuilder> builder)
    : builder_(std::move(builder)) {
  assert(builder_ && "Cannot pass null builder");
}

void PCDirector::configure_pc() {
  builder_->add_motherboard();
  builder_->add_cpu();
  builder_->add_hdd();
  builder_->add_cooler();
  builder_->add_dvddrive();
}
