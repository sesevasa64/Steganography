#include "crypters.hpp"

Pixels load_pixels(Image *image) {
    static int index = 0;
    Pixels pixels(pixel_size);
    for(auto& pixel : pixels) {
        pixel = (*image)[index++];
    }
    return pixels;
}

Decrypter::Decrypter(Image *image) : image(image) {}

void Decrypter::decrypt(std::string str) {
    Str_It cur_str(str.begin());
    Triads_It start(triads.end());
    int nsize = calc_size(str.size());
    triads.resize(triads.size() + nsize);
    Triads_It end(triads.end());
    for(auto cur_triad = start; cur_triad != end; cur_triad++) {
        auto pixels = load_pixels(image);
        BitStream stream(cur_str, cur_str + chars_in_triad);
        *cur_triad = std::make_shared<Triad>(pixels);
        (*cur_triad)->decrypt(std::move(stream));
        cur_str += chars_in_triad;
    }
}

Decrypter::~Decrypter() {
    auto pixels = load_pixels(image);
    Triad triad(pixels);
    triad.decrypt(BitStream(end));
}

int Decrypter::calc_size(int str_size) {
    return ceil(double(str_size) / pixel_size);
}

Encrypter::Encrypter(Image *image) : image(image) {}

std::string Encrypter::encrypt() {
    std::string res, temp;
    while(temp != end) {
        auto pixels = load_pixels(image);
        triads.push_back(std::make_shared<Triad>(pixels));
        temp = triads.back()->encrypt();
        res += temp;
    }
    return res;
}
/*
std::string Encrypter::encrypt() {
    std::string res, temp;
    std::shared_ptr<Triad> triad;
    while(temp != end) {
        auto pixels = load_pixels(image);
        triad = std::make_shared<Triad>(pixels);
        temp = triad->encrypt();
        res += temp;
    }
    return res;
}
*/
/*
std::string res;
for(auto& triad : triads) {
    res += triad->encrypt();
}
return res;
*/