#include "soupe.hpp"

Soupe::Soupe(std::string name) {
    this->name = name;
}

std::string Soupe::getName() {
    return this->name;
}