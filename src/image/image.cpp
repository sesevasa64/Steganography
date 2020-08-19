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
    //std::cout << "Image Height: " << height << std::endl;
    //std::cout << "Image Width: "  << width  << std::endl;
    pixels = Pixels(height * width);
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            Point pos(x, y);
            int color = imagegetpixel(image, x, y);
            pixels[y * width + x] = std::make_shared<Pixel>(pos, color);
        }
    }
    //std::cout << "Image loaded succesfully" << std::endl;
}

Image::~Image() {
    saveBMP(name.c_str(), image);
    freeimage(image);
}

SPixel& Image::operator()(int x, int y) {
    return (*this)[y * width + x];
}

SPixel& Image::operator[](int index) {
    return pixels[index];
}

SPixel& Image::operator[](Point pos) {
    return this->operator()(pos.x, pos.y);
}

void Image::update() {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int old_color = imagegetpixel(image, x, y);
            int cur_color = pixels[y * width + x]->getColor();
            if(old_color != cur_color) {
                imageputpixel(image, x, y, cur_color);
                //std::cout << "Position: " << j << ", " << i << std::endl;
            }
        }
    }
}
