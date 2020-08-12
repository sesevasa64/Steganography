#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "../image/image.hpp"
#include "../triad/triad.hpp"
#include "../config.hpp"

typedef std::vector<std::shared_ptr<Triad>> Triads;
typedef Triads::iterator Triads_It;

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

class Decrypter {
private:
    Image *image;
    Triads triads;
    int index;
    int calc_size(int str_size);
public:
    Decrypter(Image *image);
    void decrypt(std::string str);
};

class Encrypter {
private:
    Image *image;
    Triads triads;
public:
    Encrypter(Image *image);
    std::string encrypt();
};