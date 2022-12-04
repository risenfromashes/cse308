#pragma once

#include "pc_builder.h"
#include "ram.h"

class PCDirector {
public:
  PCDirector(std::unique_ptr<PCBuilder> builder);

  void configure_pc();

  template <std::derived_from<RAM> T> void add_ram() { builder_->add_ram<T>(); }
  template <std::derived_from<GPU> T> void add_gpu() { builder_->add_gpu<T>(); }

  PC build() { return builder_->build(); }
  std::unique_ptr<PC> build_unique() { return builder_->build_unique(); }

private:
  std::unique_ptr<PCBuilder> builder_;
};
