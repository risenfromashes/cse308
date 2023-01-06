#include "product.h"

Product::Product(int id, std::string name, float cost)
    : id_(id), name_(std::move(name)), cost_(cost) {}
