#pragma once
#include <numeric>

// user setting
const int used_bits  = 2;

const int byte_size  = 8;
const int components = 3;

const int bits_in_pixel = used_bits * components;
const int min_bits = std::lcm(bits_in_pixel, byte_size);

const int pixel_size = min_bits / bits_in_pixel;
const int chars_in_triad = min_bits / byte_size;

const double char_per_pixel = double(chars_in_triad) / pixel_size;

const std::string end(chars_in_triad, '\0');
