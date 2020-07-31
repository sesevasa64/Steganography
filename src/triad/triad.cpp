#include "triad.hpp"
#include "../config.hpp"

Triad::Triad(pixel_array array, std::string text) 
: array(array), text(text) {}

void Triad::decrypt() {
    for(int i = 0, j = 0; i < minimum_bits; i += bits_in_pixel, j++) {
        auto color = array[i].getColor();
    }
}