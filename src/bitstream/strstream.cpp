#include "bitstream.hpp"

void StrStream::bitset_to_str(Bits& bits) {
    str.resize(bits.size() / 8);
    for(int i = 0; i < str.size(); i++) {
        for(int k = 0; k < byte_size; k++) {
            str[i] = str[i] | (bits[i * byte_size + k] << k);
        }
    }
}

StrStream::StrStream() : StrStream(Bits()) {}

StrStream::StrStream(Bits bits) {
    bitset_to_str(bits);
}

StrStream& StrStream::operator=(Bits bits) {
    bitset_to_str(bits);
    return *this;
}

char StrStream::operator[](int index) {
    return str[index];
}

std::string StrStream::getStr() {
    return str;
}