#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "../triad/triad.hpp"
#include "../config.hpp"

typedef std::vector<Triad> Triads;

class Decrypter {
public:
    void decrypt(std::string str) {
        Point pos(0, 0);
        Str_It it(str.begin());
        Triads triads(str.size() * ratio);
        for(auto& triad : triads) {
            Pixels pixels(pixel_size);
            for(int j = 0; j < pixel_size; j++) {
                pixels[j] = Pixel(pos);
                if(++pos.x == width) {
                    pos.x = 0;
                    pos.y++;
                }
            }
            BitStream stream(it, it + chars_in_triad);
            triad = Triad(pixels);
            triad.decrypt(stream);
            it += chars_in_triad;
        }
    }
};