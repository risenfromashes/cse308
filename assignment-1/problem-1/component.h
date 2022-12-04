#pragma once

#include <string>
#include <string_view>

/* Abstract Component Base Class */
class Component {
public:
  enum class Type { HDD, MOBO, DVD, COOLER, CPU, GPU, RAM };

  virtual ~Component() = default;

  unsigned int price() { return price_; }
  Type type() { return type_; }
  std::string_view model() { return model_; }

protected:
  Component() = default;

  void set_price(unsigned int price) { price_ = price; }
  void set_type(Type type) { type_ = type; }
  void set_model(std::string model) { model_ = std::move(model); }

private:
  unsigned int price_;
  Type type_;
  std::string model_;
};
