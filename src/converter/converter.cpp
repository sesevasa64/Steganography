#include <cmath>
#include "../triad/triad.hpp"
#include "converter.hpp"
#include "../config.hpp"

Converter::Converter(std::string str) 
: str(str), triads(ceil(str.size() * byte_size / double(minimum_bits))) {
    Point pos(0, 0);
    for(int i = 0; i < triads.size(); i++) {
        Pixels pixels(pixel_size);
        for(int j = 0; j < pixel_size; j++) {
            pixels[i] = Pixel(pos);
            if(++pos.x == width) {
                pos.x = 0;
                pos.y++;
            }
        }
    }
}