#include "image.hpp"

Image::Image(std::string name) {
    image  = loadBMP(name.c_str());
    height = imageheight(image);
    width  = imagewidth(image);
    pixels = Pixels(height * width);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Point pos(i, j);
            pixels[i * height + j] = std::make_shared<Pixel>(pos);
        }
    }
}
Image::~Image() {
    freeimage(image);
}

SPixel& Image::operator()(int i, int j) {
    check.push(pixels[i * height + j]);
    return pixels[i * height + j];
}

void Image::draw() {
    while(!check.empty()) {
        auto& pixel = check.top();
        int x = pixel->getX(), y = pixel->getY();
        if(pixel == pixels[y * height + x]) {
            imageputpixel(image, x, y, pixel->getColorAsInt());
        }
        check.pop();
    }
}
