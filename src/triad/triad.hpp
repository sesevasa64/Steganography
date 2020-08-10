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
    Triad();
    Triad(Pixels& pixels);
    std::string encrypt();
    void decrypt(BitStream stream);
};