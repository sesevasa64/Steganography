#include <cmath>
#include "crypters.hpp"

Pixels Loader::load_pixels(Image *image) {
    Pixels pixels(pixel_size);
    for(auto& pixel : pixels) {
        pixel = (*image)[index++];
    }
    return pixels;
}

Decrypter::Decrypter(Image *image) : image(image), loader(image) {}

void Decrypter::decrypt(std::string str) {
    str += std::string(str.size() / chars_in_triad, '\0');
    int start = triads.size();
    int nsize = calc_size(str.size());
    triads.resize(start + nsize);
    int end = triads.size();
    Str_It cur_str(str.begin());
    for(int i = start; i < end; i++) {
        auto&& pixels = loader.load_pixels(image);
        BitStream stream(cur_str, cur_str + chars_in_triad);
        triads[i] = std::make_shared<Triad>(pixels);
        triads[i]->decrypt(std::move(stream));
        cur_str += chars_in_triad;
    }
}

Decrypter::~Decrypter() {
    auto pixels = loader.load_pixels(image);
    Triad triad(pixels);
    triad.decrypt(BitStream(end));
    image->update();
}

int Decrypter::calc_size(int str_size) {
    return ceil(double(str_size) / pixel_size);
}

Encrypter::Encrypter(Image *image) : image(image), loader(image) {}

std::string Encrypter::encrypt() {
    std::string res, temp;
    while(temp != end) {
        auto&& pixels = loader.load_pixels(image);
        triads.push_back(std::make_shared<Triad>(pixels));
        temp = triads.back()->encrypt();
        res += temp;
    }
    return res;
}