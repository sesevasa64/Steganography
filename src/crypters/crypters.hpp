#pragma once
#include <string>
#include "../image/image.hpp"
#include "../triad/triad.hpp"

typedef std::vector<std::shared_ptr<Triad>> Triads;

class Loader {
private:
    Image *image;
    int index;
public:
    Pixels load_pixels(Image *image);
    Loader(Image *image) : image(image), index(0) {}
};

class Decrypter {
private:
    Image *image;
    Triads triads;
    Loader loader;
    int calc_size(int str_size);
public:
    Decrypter(Image *image);
    ~Decrypter();
    void decrypt(std::string str);
};

class Encrypter {
private:
    Image *image;
    Triads triads;
    Loader loader;
public:
    Encrypter(Image *image);
    std::string encrypt();
};

/*
Image image("image.bmp");

Decrypter dc;
string message("hello world");
dc.decrypt(image, message)

или

Decrypter dc(image);
string m1, m2;
dc.decrypt(m1);
dc.dectypt(m2);
*/