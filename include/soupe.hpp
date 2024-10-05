#pragma once

#include <string>

class Soupe {
private:
    std::string name;
public:
    Soupe(std::string name);
    std::string getName();
};