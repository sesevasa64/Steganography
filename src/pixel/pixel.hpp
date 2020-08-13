#pragma once
#include <array>
#include "../point/point.hpp"
#include "../config.hpp"
#include "../../lib/winbgim.hpp"

class Pixel {
private:
    Point pos;
    int color;
public:
    Pixel();
    Pixel(Point pos, int color);
    Pixel(Pixel&& another);
    Pixel& operator=(Pixel&& another);
    int& getColor();
    int getX() { return pos.x; }
    int getY() { return pos.y; }
};