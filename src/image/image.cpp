#include <iostream>
#include "image.hpp"

Image::Image(std::string name) : name(name) {
    image = loadBMP(name.c_str());
    if(!image) {
        std::cout << "Cant load image!" << std::endl;
        throw std::bad_exception();
    }
    height = imageheight(image);
    width  = imagewidth(image);
    std::cout << "Image Height: " << height << std::endl;
    std::cout << "Image Width: "  << width  << std::endl;
    pixels = Pixels(height * width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Point pos(j, i);
            int color = imagegetpixel(image, j, i);
            pixels[j * height + i] = std::make_shared<Pixel>(pos, color);
        }
    }
    std::cout << "Image loaded succesfully" << std::endl;
}

Image::~Image() {
    saveBMP(name.c_str(), image);
    freeimage(image);
}

SPixel& Image::operator()(int i, int j) {
    return (*this)[i * height + j];
}

SPixel& Image::operator[](int index) {
    return pixels[index];
}

SPixel& Image::operator[](Point pos) {
    return this->operator()(pos.x, pos.y);
}

void Image::update() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int old_color = imagegetpixel(image, j, i);
            int cur_color = pixels[j * height + i]->getColor();
            if(old_color != cur_color) {
                imageputpixel(image, j, i, cur_color);
                std::cout << "Position: " << j << ", " << i << std::endl;
            }
        }
    }
}
