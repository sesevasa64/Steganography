#pragma once
#include <string>
#include "../triad/triad.hpp"
#include "../../lib/winbgim.hpp"

class Image {
private:
    std::string name;
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
    SPixel& operator()(int x, int y);
    SPixel& operator[](int index);
    SPixel& operator[](Point point);
    IMAGE *get() { return image; }
};