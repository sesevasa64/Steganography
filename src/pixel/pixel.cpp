#include "pixel.hpp"

Pixel::Pixel() {}

Pixel::Pixel(Pixel&& another) 
: pos(another.pos), 
  colors(another.colors) {}

Pixel::Pixel(Point pos, int color) : pos(pos) {
    for(auto i : rgb) {
        colors[i] = color << (i * byte_size);
    }
}

Colors& Pixel::getColor() {
    return colors;
}

int Pixel::getIntColor() {
    int color = 0;
    for(auto i : rgb) {
        color |= (colors[i] & 0x0ff) << (i * byte_size);
    }
    return color;
}

Pixel& Pixel::operator=(Pixel&& another) {
    std::swap(pos, another.pos);
    std::swap(colors, another.colors);
}