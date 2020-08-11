#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../pixel/pixel.hpp"
#include "../bitstream/bitsteam.hpp"

typedef std::shared_ptr<Pixel> SPixel;
typedef std::vector<SPixel> Pixels;

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