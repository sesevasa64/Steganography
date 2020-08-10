#pragma once
#include <cmath>
#include <numeric>

const int width  = 800;
const int height = 600;

const int byte_size = 8;
const int used_bits = 2;
const int components = 3;

const int bits_in_pixel = used_bits * components;
const int minimum_bits = std::lcm(bits_in_pixel, byte_size);

const int pixel_size = minimum_bits / bits_in_pixel;
const int chars_in_triad = minimum_bits / byte_size;

const int ratio = ceil(double(byte_size) / minimum_bits);

enum RGB {
    _RED   = 0,
    _GREEN = 1,
    _BLUE  = 2,
};

const RGB rgb[] = {_RED, _GREEN, _BLUE};