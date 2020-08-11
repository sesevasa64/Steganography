#pragma once
#include <array>
#include "../point/point.hpp"
#include "../config.hpp"
#include "../../lib/winbgim.hpp"

class Image;
typedef std::array<int, components> Colors;

class Pixel {
private:
    Point pos;
    Colors colors;
    IMAGE *image;
public:
    Pixel();
    Pixel(IMAGE *image, Point pos);
    Pixel(Pixel&& another);
    Pixel& operator=(Pixel&& another);
    Colors& getColor();
    int getIntColor();
    int getX() { return pos.x; }
    int getY() { return pos.y; }
    void draw();
};