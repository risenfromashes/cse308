#pragma once

#include "gpu.h"
#include "pc.h"
#include "ram.h"
#include <concepts>

class PCBuilder {
public:
  void add_motherboard();
  void add_hdd();
  virtual void add_cpu() = 0;
  virtual void add_cooler() = 0;
  virtual void add_dvddrive() = 0;
  template <std::derived_from<GPU> T> void add_gpu();
  template <std::derived_from<RAM> T> void add_ram();

  PC build();
  std::unique_ptr<PC> build_unique();

protected:
  std::vector<std::unique_ptr<Component>> components_;

private:
  unsigned int calc_price();
};

class I5PCBuilder : public PCBuilder {
public:
  void add_cpu() override;
  void add_cooler() override;
  void add_dvddrive() override;
};

class I7PCBuilder : public PCBuilder {
public:
  void add_cpu() override;
  void add_cooler() override;
  void add_dvddrive() override;
};

class I9PCBuilder : public PCBuilder {
public:
  void add_cpu() override;
  void add_cooler() override;
  void add_dvddrive() override;
};

class GamingPCBuilder : public PCBuilder {
public:
  void add_cpu() override;
  void add_cooler() override;
  void add_dvddrive() override;
};

/* template functions */
template <std::derived_from<GPU> T> void PCBuilder::add_gpu() {
  components_.push_back(std::make_unique<T>());
}

template <std::derived_from<RAM> T> void PCBuilder::add_ram() {
  components_.push_back(std::make_unique<T>());
}
