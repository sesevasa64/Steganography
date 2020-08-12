#include "bitstream.hpp"

int BitStream::calc_size(int str_size) {
    return ceil(double(str_size * byte_size) / min_bits) * min_bits; 
}

void BitStream::str_to_bitset(const std::string& str) {
    str_to_bitset(str.begin(), str.end());
}

void BitStream::str_to_bitset(Str_It start, Str_It end) {
    auto size = std::distance(start, end);
    bits.resize(calc_size(size), false); // заменить на bits.resize(min_bits)?
    for(int i = 0; i < size; i++) {
        for(int k = 0; k < byte_size; k++) {
            bits[i * byte_size + k] = (*start >> k) & 1;
        }
        start++;
    }
}

BitStream& BitStream::operator=(const std::string& str) {
    str_to_bitset(str);
    return *this;
}

BitStream& BitStream::operator=(const std::string&& str) {
    str_to_bitset(str);
    return *this;
}

BitStream& BitStream::operator=(const char* str) {
    std::string temp(str);
    str_to_bitset(temp);
    return *this;
}

BitStream& BitStream::operator=(BitStream&& another) {
    bits = another.bits;
    return *this;
}

bool BitStream::operator[](int index) {
    return bits[index];
}

Bits BitStream::getBits() {
    return bits;
}

BitStream::BitStream() : BitStream(std::string()) {}

BitStream::BitStream(BitStream&& another) {
    std::swap(bits, another.bits);
}

BitStream::BitStream(const char *str) : BitStream(std::string(str)) {}

BitStream::BitStream(const std::string& str) : BitStream(str.begin(), str.end()) {}

BitStream::BitStream(const std::string&& str) : BitStream(str.begin(), str.end()) {}

BitStream::BitStream(Str_It start, Str_It end) {
    str_to_bitset(start, end);
}