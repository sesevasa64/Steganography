#include "decrypter.hpp"

Decrypter::Decrypter(Image *image) : image(image), triads(0), index(0) {}

void Decrypter::decrypt(std::string str) {
    Str_It cur_str(str.begin());
    Triads_It start(triads.end());
    int nsize = calc_size(str.size());
    triads.resize(triads.size() + nsize);
    Triads_It end(triads.end());
    for(auto cur_triad = start; cur_triad != end; cur_triad++) {
        Pixels pixels(pixel_size);
        for(auto& pixel : pixels) {
            pixel = (*image)[index++];
        }
        BitStream stream(cur_str, cur_str + chars_in_triad);
        *cur_triad = std::make_shared<Triad>(pixels);
        (*cur_triad)->decrypt(stream);
        cur_str += chars_in_triad;
    }
}

std::string Decrypter::encrypt() {
    auto size = std::distance(triads.begin(), triads.end());
    std::string res(size * chars_in_triad, '\0');
    for(auto& triad : triads) {
        res += triad->encrypt();
    }
}

int Decrypter::calc_size(int str_size) {
    return ceil(double(str_size) / pixel_size);
}