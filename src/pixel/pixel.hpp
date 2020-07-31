#pragma once
#include "../../lib/winbgim.hpp"

struct Point {
    int x, y;
};

class Pixel {
private:
    const Point pos;
public:
    Pixel(Point pos);
    int getColor();
    void setColor(int color);
};