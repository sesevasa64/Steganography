#include "image.hpp"

Image::Image(std::string name) {
    image  = loadBMP(name.c_str());
    height = imageheight(image);
    width  = imagewidth(image);
    pixels = Pixels(height * width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Point pos(i, j);
            pixels[i * height + j] = std::make_shared<Pixel>(image, pos);
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
            int cur_color = pixels[i * height + j]->getIntColor();
            if(old_color != cur_color) {
                imageputpixel(image, i, j, cur_color);
            }
        }
    }
}
