#pragma once
#include <string>
#include "../image/image.hpp"
#include "../triad/triad.hpp"

typedef std::vector<std::shared_ptr<Triad>> Triads;

class Loader {
private:
    Pixels pixels;
    Image *image;
public:
    Pixels& load_pixels();
    Loader(Image *image, std::string password);
};

class Crypter {
private:
    Image *image;
    Triads triads;
    Loader loader;
    size_t capacity;
public:
    size_t Capacity() { return capacity; }
    Crypter(Image *image, std::string password);
    virtual ~Crypter() {}
};

class Decrypter {
private:
    Image *image;
    Triads triads;
    Loader loader;
    size_t capacity;
    size_t used;
public:
    Decrypter(Image *image, std::string password);
    ~Decrypter();
    void decrypt(std::string str);
    size_t Capacity() { return capacity; }
    size_t Used() { return used; }
};

class Encrypter {
private:
    Image *image;
    Triads triads;
    Loader loader;
public:
    Encrypter(Image *image, std::string password);
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