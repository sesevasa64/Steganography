#pragma once
#include <cmath>
#include <numeric>

const int width  = 800;
const int height = 600;

const int byte_size = 8;
const int used_bits = 2;
const int components = 3;

const int bits_in_pixel = used_bits * components;
const int min_bits = std::lcm(bits_in_pixel, byte_size);

const int pixel_size = min_bits / bits_in_pixel;
const int chars_in_triad = min_bits / byte_size;

//const int ratio = ceil(double(byte_size) / min_bits);

const std::string end(chars_in_triad, '\0');

const int triad_size = width * height / pixel_size;

enum RGB {
    _RED   = 0,
    _GREEN = 1,
    _BLUE  = 2,
};

const RGB rgb[] = {_RED, _GREEN, _BLUE};