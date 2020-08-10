#pragma once
#include <string>
#include <vector>
#include "../pixel/pixel.hpp"
#include "../bitstream/bitsteam.hpp"

typedef std::vector<Pixel> Pixels;

class Triad {
private:
    Pixels pixels;
    BitStream stream;
public:
    Triad(Pixels pixels, BitStream stream);
    std::string encrypt();
    void decrypt();
};