#include "crypters.hpp"

Decrypter::Decrypter(Image *image) 
: image(image), 
  triads(0), 
  index(0) {}

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
        (*cur_triad)->decrypt(std::move(stream));
        cur_str += chars_in_triad;
    }
}

int Decrypter::calc_size(int str_size) {
    return ceil(double(str_size) / pixel_size);
}

Encrypter::Encrypter(Image *image) 
: image(image), 
  triads(image->Height() * image->Width()) {}

std::string Encrypter::encrypt() {
    std::string res;
    res.reserve(triads.size() * chars_in_triad);
    for(auto& triad : triads) {
        res += triad->encrypt();
    }
    return res;
}