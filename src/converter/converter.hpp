#pragma once
#include <string>
#include <vector>
#include "../triad/triad.hpp"

class Converter {
private:
    std::string str;
    std::vector<Triad> triads;
public:
    Converter(std::string str);
};