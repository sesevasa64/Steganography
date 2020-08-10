#pragma once
#include <array>
#include "../config.hpp"
#include "../../lib/winbgim.hpp"

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point(Point& another) : x(another.x), y(another.y) {}
    Point(Point&& another) : x(another.x), y(another.y) {}
    Point& operator=(Point&& another) {
        std::swap(x, another.x);
        std::swap(y, another.y);
        return *this;
    }
};

typedef std::array<int, components> Colors;

class Pixel {
private:
    const Point pos;
    Colors colors;
public:
    Pixel(Point pos);
    Colors& getColor();
    void draw();
    Pixel& operator=(Pixel&& another);
};