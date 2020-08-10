#pragma once
#include <array>
#include "../config.hpp"
#include "../../lib/winbgim.hpp"

struct Point {
    int x, y;
    Point() : Point(-1, -1) {}
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