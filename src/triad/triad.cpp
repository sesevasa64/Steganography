#include <bitset>
#include "triad.hpp"
#include "../config.hpp"

Triad::Triad() : pixels() {}

Triad::Triad(Pixels& pixels) : pixels(pixels) {}

void Triad::decrypt(BitStream stream) { 
    std::cout << "Stream size: " << stream.size() << std::endl;
    int idx = 0;
    for(int i = 0; i < pixel_size; i++) {
        int& color = pixels[i]->getColor();
        for(int j = 0; j < min_bits; j += byte_size) {
            for(int k = 0; k < used_bits; k++) {
                color &= ~(1u << (j + k));
                color |= (stream[idx++] << (j + k));
            }
        }
    }   
}

std::string Triad::encrypt() {
    int idx = 0;
    Bits bits(min_bits);
    for(int i = 0; i < pixel_size; i++) {
        int& color = pixels[i]->getColor();
        for(int j = 0; j < min_bits; j += byte_size) {
            for(int k = 0; k < used_bits; k++) {
                bits[idx++] = (color >> (j + k)) & 1;
            }
        }
    }   
    return StrStream(bits).getStr();
}
/*
    std::cout << "Bits: ";
    for(int i = 0; i < stream.size(); i++) {
        std::cout << stream[i];
        if((i + 1) % byte_size == 0) {
            //std::cout << " ";
        }
    }
    std::cout << std::endl;
*/
/*
    std::cout << "Bits: ";
    for(int i = 0; i < bits.size(); i++) {
        std::cout << bits[i];
        if((i + 1) % byte_size == 0) {
            //std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Pizdec" << std::endl;
*/