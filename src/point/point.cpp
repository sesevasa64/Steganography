#include "point.hpp"

Point::Point() : Point(-1, -1) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(Point& another) : x(another.x), y(another.y) {}

Point::Point(Point&& another) : x(another.x), y(another.y) {}

Point& Point::operator=(Point&& another) {
    std::swap(x, another.x);
    std::swap(y, another.y);
    return *this;
}