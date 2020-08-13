#include "pixel.hpp"

Pixel::Pixel() {}

Pixel::Pixel(Pixel&& another) 
: pos(another.pos), 
  color(another.color) {}

Pixel::Pixel(Point pos, int color) : pos(pos), color(color) {}

int& Pixel::getColor() {
    return color;
}

Pixel& Pixel::operator=(Pixel&& another) {
    std::swap(pos, another.pos);
    std::swap(color, another.color);
    return *this;
}