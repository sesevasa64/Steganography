#include "pixel.hpp"

Pixel::Pixel(Point pos) : pos(pos) {}

int Pixel::getColor() {
    return getpixel(pos.x, pos.y);
}

void Pixel::setColor(int color) {
    putpixel(pos.x, pos.y, color);
}