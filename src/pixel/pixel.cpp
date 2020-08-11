#include "pixel.hpp"

Pixel::Pixel() {}

Pixel::Pixel(Pixel&& another) 
: pos(another.pos), 
  colors(another.colors) {}

Pixel::Pixel(Point pos) : pos(pos) {
    auto color = getpixel(pos.x, pos.y);
    for(auto i : rgb) {
        colors[i] = color << (i * byte_size);
    }
}

Colors& Pixel::getColor() {
    return colors;
}

int Pixel::getColorAsInt() {
    int color = 0;
    for(auto i : rgb) {
        color |= (colors[i] & 0x0ff) << (i * byte_size);
    }
    return color;
}

void Pixel::draw() {
    int color = getColorAsInt();
    putpixel(pos.x, pos.y, color);
}

Pixel& Pixel::operator=(Pixel&& another) {
    std::swap(pos, another.pos);
    std::swap(colors, another.colors);
}