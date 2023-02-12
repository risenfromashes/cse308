#pragma once

#include <memory>

#include "coffee.h"

class CoffeeDecorator : public Coffee {
public:
  CoffeeDecorator(std::string name, std::unique_ptr<Coffee> coffee);
  std::string_view name() { return name_; }

protected:
  std::string name_;
  std::unique_ptr<Coffee> coffee_;
};

class GroundBeans : public CoffeeDecorator {
public:
  GroundBeans(std::string name, std::unique_ptr<Coffee> coffee);
  void print_ingredients() override;
  int cost() override;
};

class Milk : public CoffeeDecorator {
public:
  Milk(std::string name, std::unique_ptr<Coffee> coffee);
  void print_ingredients() override;
  int cost() override;
};

class DairyCream : public CoffeeDecorator {
public:
  DairyCream(std::string name, std::unique_ptr<Coffee> coffee);
  void print_ingredients() override;
  int cost() override;
};

class CinnamonPowder : public CoffeeDecorator {
public:
  CinnamonPowder(std::string name, std::unique_ptr<Coffee> coffee);
  void print_ingredients() override;
  int cost() override;
};

class ChocolateSauce : public CoffeeDecorator {
public:
  ChocolateSauce(std::string name, std::unique_ptr<Coffee> coffee);
  void print_ingredients() override;
  int cost() override;
};
