#include "triad.hpp"
#include "../config.hpp"

Triad::Triad(Pixels pixels, BitStream stream) 
: pixels(pixels), stream(stream) {}

void Triad::decrypt() {
    for(int i = 0; i < minimum_bits; i += bits_in_pixel) {
        auto colors = pixels[i].getColor();
        for(int j = 0; j < components; j++) {
            for(int k = 0; k < used_bits; k++) {
                colors[j] |= (1u << stream[i + j * used_bits + k]);
            }
        }
        pixels[i].draw();
    }
}

std::string Triad::encrypt() {
    Bits bits(minimum_bits);
    for(int i = 0; i < minimum_bits; i += bits_in_pixel) {
        auto colors = pixels[i].getColor();
        for(int j = 0; j < components; j++) {
            for(int k = 0; k < used_bits; k++) {
                bits[i + j * used_bits + k] = (colors[j] >> k) && 1;
            }
        }
    }
    return StrStream(bits).getStr();
}