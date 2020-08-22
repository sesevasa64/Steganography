#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include "crypters.hpp"

Loader::Loader(Image *image, std::string password)
: image(image),
  pixels(pixel_size),
  indexes(image->Size()),
  start(indexes.begin()) {
    int height = image->Height();
    int width = image->Width();
    auto it = indexes.begin();
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            (*it++) = y * width + x;
        }
    }
    std::hash<std::string> hash;
    std::mt19937 gen(hash(password));
    std::shuffle(indexes.begin(), indexes.end(), gen);
}

Pixels& Loader::load_pixels() {
    for(auto& pixel : pixels) {
        pixel = (*image)[*(start++)];
    }
    return pixels;
}

Crypter::Crypter(Image *image, std::string password)
: image(image),
  capacity(image->Size() * char_per_pixel - chars_in_triad), 
  loader(image, std::move(password)) {}

Decrypter::Decrypter(Image *image, std::string password)
: Crypter(image, std::move(password)),
  used(0u) {}

void Decrypter::decrypt(std::string str) {
    // Работает и без этого..., видимо после str.end() идут нулевые байты?
    str += std::string(chars_in_triad - str.size() % chars_in_triad, '\0');
    if(used + str.size() >= capacity) {
        throw std::length_error("Image capacity overflow!");
    }
    used += str.size();
    for(auto it = str.begin(); it != str.end(); it += chars_in_triad) {
        auto& pixels = loader.load_pixels();
        BitStream stream(it, it + chars_in_triad);
        triads.push_back(std::make_shared<Triad>(pixels));
        triads.back()->decrypt(std::move(stream));
    }
}

Decrypter::~Decrypter() {
    auto& pixels = loader.load_pixels();
    Triad triad(pixels);
    triad.decrypt(BitStream(end));
    image->update();
}

Encrypter::Encrypter(Image *image, std::string password) 
: Crypter(image, std::move(password)) {}

std::string Encrypter::encrypt() {
    std::string res, temp;
    while(true) {
        auto& pixels = loader.load_pixels();
        triads.push_back(std::make_shared<Triad>(pixels));
        temp = triads.back()->encrypt();
        if(temp == end) {
            break;
        }
        res += temp;
        if(res.size() > capacity) { // Костыль.... или нет?
            throw std::invalid_argument("Password is incorrect!");
        }
    }
    return res;
}