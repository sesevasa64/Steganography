#pragma once
#include <stack>
#include <string>
#include "../point/point.hpp"
#include "../pixel/pixel.hpp"
#include "../triad/triad.hpp"
#include "../../lib/winbgim.hpp"

class Image {
private:
    IMAGE *image;
    int height;
    int width;
    Pixels pixels;
    std::stack<SPixel> check;
public:
    Image(std::string name);
    ~Image();
    int Height() { return height; }
    int Width()  { return width;  }
    int Size()   { return height * width; }
    SPixel& operator()(int i, int j);
    void draw();
};