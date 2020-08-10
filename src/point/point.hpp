#pragma once
#include <iostream>

struct Point {
    int x, y;
    Point();
    Point(int x, int y);
    Point(Point& another);
    Point(Point&& another);
    Point& operator=(Point&& another);
};