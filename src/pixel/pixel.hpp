#pragma once
#include <array>
#include "../point/point.hpp"
#include "../config.hpp"
#include "../../lib/winbgim.hpp"

typedef std::array<int, components> Colors;

class Pixel {
private:
    Point pos;
    Colors colors;
public:
    Pixel();
    Pixel(Point pos);
    Pixel(Pixel&& another);
    Pixel& operator=(Pixel&& another);
    Colors& getColor();
    void draw();
};