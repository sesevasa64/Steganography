#pragma once
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
public:
    Image(std::string name);
    ~Image();
    void update();
    int Height() { return height; }
    int Width()  { return width;  }
    int Size()   { return height * width; }
    SPixel& operator()(int i, int j);
    SPixel& operator[](int index);
};