#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "../image/image.hpp"
#include "../triad/triad.hpp"
#include "../config.hpp"

typedef std::vector<std::shared_ptr<Triad>> Triads;

class Decrypter {
public:
    void decrypt(Image *image, std::string str) {
        int i = 0;
        Str_It it(str.begin());
        Triads triads(str.size() * ratio);
        for(auto& triad : triads) {
            Pixels pixels(pixel_size);
            for(auto& pixel : pixels) {
                pixel = (*image)[i++];
            }
            BitStream stream(it, it + chars_in_triad);
            triad = std::make_shared<Triad>(pixels);
            triad->decrypt(stream);
            it += chars_in_triad;
        }
    }
};

/*
Point pos(0, 0);
for(auto& triad : triads) {
    Pixels pixels(pixel_size);
    for(int j = 0; j < pixel_size; j++) {
        pixels[j] = std::make_shared<Pixel>(image->get(), pos);
        if(++pos.x == width) {
            pos.x = 0;
            pos.y++;
        }
    }
    BitStream stream(it, it + chars_in_triad);
    triad = std::make_shared<Triad>(pixels);
    triad->decrypt(stream);
    it += chars_in_triad;
}
*/