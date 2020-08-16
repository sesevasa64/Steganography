#include <iostream>
#include <cmath>
#include "crypters.hpp"

Loader::Loader(Image *image, std::string password) 
: image(image),
  pixels(pixel_size) {
    std::hash<std::string> hash;
    srand(hash(password));
}

Pixels& Loader::load_pixels() {
    for(auto& pixel : pixels) {
        int i = rand() % image->Width();
        int j = rand() % image->Height();
        //std::cout << "At: " << i << ", " << j << std::endl;
        pixel = (*image)(i, j);
    }
    return pixels;
}

Crypter::Crypter(Image *image, std::string password)
: image(image),
  capacity(image->Height() * image->Width() * char_per_pixel - chars_in_triad), 
  loader(image, std::move(password)) {
      std::cout << "Image capacity: " << capacity << std::endl;
  }

Decrypter::Decrypter(Image *image, std::string password) 
: used(0u),
  image(image),
  capacity(image->Height() * image->Width() * char_per_pixel - chars_in_triad),
  loader(image, std::move(password)) {}

void Decrypter::decrypt(std::string str) {
    // Работает и без этого..., видимо после str.end() идут нулевые байты?
    str += std::string(chars_in_triad - str.size() % chars_in_triad, '\0');
    if(used + str.size() >= capacity) {
        std::cout << "Image capacity overflow!";
        throw std::bad_exception();
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
: image(image), 
  loader(image, std::move(password)) {}

std::string Encrypter::encrypt() {
    std::string res, temp;
    while(temp != end) {
        auto& pixels = loader.load_pixels();
        triads.push_back(std::make_shared<Triad>(pixels));
        temp = triads.back()->encrypt();
        res += temp;
    }
    return res;
}