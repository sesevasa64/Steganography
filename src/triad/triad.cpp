#include "triad.hpp"
#include "../config.hpp"

Triad::Triad() : pixels() {}

Triad::Triad(Pixels& pixels) : pixels(pixels) {}

void Triad::decrypt(BitStream stream) {
    for(int i = 0; i < min_bits; i += bits_in_pixel) {
        auto colors = pixels[i]->getColor();
        for(int j = 0; j < components; j++) {
            for(int k = 0; k < used_bits; k++) {
                colors[j] |= (1u << stream[i + j * used_bits + k]);
            }
        }
    }
}

std::string Triad::encrypt() {
    Bits bits(min_bits);
    for(int i = 0; i < min_bits; i += bits_in_pixel) {
        auto colors = pixels[i]->getColor();
        for(int j = 0; j < components; j++) {
            for(int k = 0; k < used_bits; k++) {
                bits[i + j * used_bits + k] = (colors[j] >> k) && 1;
            }
        }
    }
    return StrStream(bits).getStr();
}