#pragma once
#include <string>
#include "../triad/triad.hpp"
#include "../../lib/winbgim.hpp"

class Image {
private:
    std::string name;
    IMAGE *image;
    uint32_t height;
    uint32_t width;
    Pixels pixels;
public:
    Image(std::string name);
    ~Image();
    void update();
    uint32_t Height() { return height; }
    uint32_t Width()  { return width;  }
    uint32_t Size()   { return height * width; }
    SPixel& operator()(int x, int y);
    SPixel& operator[](int index);
    SPixel& operator[](Point point);
    IMAGE *get() { return image; }
};