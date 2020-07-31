#pragma once
#include <string>
#include <vector>
#include "../pixel/pixel.hpp"

typedef std::vector<Pixel> pixel_array;

class Triad {
private:
    pixel_array array;
    std::string text;
public:
    Triad(pixel_array array, std::string text);
    void decrypt();
};