#pragma once
#include <list>
#include <string>
#include "../image/image.hpp"
#include "../triad/triad.hpp"

typedef std::vector<std::shared_ptr<Triad>> Triads;

class Loader {
private:
    Pixels pixels;
    Image *image;
    std::vector<int> indexes;
    std::vector<int>::iterator start;
public:
    Pixels& load_pixels();
    Loader(Image *image, std::string password);
};

class Crypter {
protected:
    Image *image;
    Triads triads;
    Loader loader;
    size_t capacity;
public:
    size_t Capacity() { return capacity; }
    Crypter(Image *image, std::string password);
    virtual ~Crypter() {}
};

class Decrypter : public Crypter {
private:
    size_t used;
public:
    Decrypter(Image *image, std::string password);
    ~Decrypter();
    void decrypt(std::string str);
    size_t Used() { return used; }
};

class Encrypter : public Crypter {
public:
    Encrypter(Image *image, std::string password);
    std::string encrypt();
};
