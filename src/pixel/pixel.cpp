#include "pixel.hpp"

Pixel::Pixel(Point pos) : pos(pos) {
    auto color = getpixel(pos.x, pos.y);
    for(auto i : rgb) {
        colors[i] = color << (i * byte_size);
    }
}

Colors& Pixel::getColor() {
    return colors;
}

void Pixel::draw() {
    int color = 0;
    for(auto i : rgb) {
        color |= (colors[i] & 0x0ff) << (i * byte_size);
    }
    putpixel(pos.x, pos.y, color);
}

Pixel& Pixel::operator=(Pixel&& another) {
    std::swap(pos, another.pos);
    std::swap(colors, another.colors);
}