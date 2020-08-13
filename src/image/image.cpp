#include <iostream>
#include "image.hpp"

Image::Image(std::string name) {
    image  = loadBMP(name.c_str());
    if(!image) {
        std::cout << "Cant load image!" << std::endl;
        throw std::bad_exception();
    }
    height = imageheight(image);
    width  = imagewidth(image);
    std::cout << "Height: " << height << std::endl;
    std::cout << "Width: " << width << std::endl;
    pixels = Pixels(height * width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Point pos(i, j);
            int color = imagegetpixel(image, i, j);
            pixels[i * height + j] = std::make_shared<Pixel>(pos, color);
        }
    }
}

Image::~Image() {
    freeimage(image);
}

SPixel& Image::operator()(int i, int j) {
    return (*this)[i * height + j];
}

SPixel& Image::operator[](int index) {
    return pixels[index];
}

void Image::update() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int old_color = imagegetpixel(image, i, j);
            int cur_color = pixels[i * height + j]->getColor();
            if(old_color != cur_color) {
                imageputpixel(image, i, j, cur_color);
            }
        }
    }
}
