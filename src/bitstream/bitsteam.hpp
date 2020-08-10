#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "../config.hpp"

typedef std::vector<bool> Bits;
typedef std::string::iterator Str_It;

class BitStream {
private:
    Bits bits;
    void str_to_bitset(std::string& str) {
        bits.resize(str.size() * byte_size);
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                bits[i * byte_size + k] = (str[i] >> k) & 1;
            }
        }
    }
    void str_to_bitset(Str_It start, Str_It end) {
        auto size = std::distance(start, end);
        bits.resize(size * byte_size);
        for(int i = 0; i < size; i++) {
            for(int k = 0; k < byte_size; k++) {
                bits[i * byte_size + k] = (*(start++) >> k) & 1;
            }
        }
    }
public:
    BitStream() : BitStream(std::string()) {}
    BitStream(const char *str) : BitStream(std::string(str)) {}
    BitStream(std::string str) {
        str_to_bitset(str);
    }
    BitStream(Str_It start, Str_It end) {}
    BitStream& operator=(std::string str) {
        str_to_bitset(str);
        return *this;
    }
    BitStream& operator=(const char* str) {
        std::string temp(str);
        str_to_bitset(temp);
        return *this;
    }
    bool operator[](int index) {
        return bits[index];
    }
    Bits getBits() {
        return bits;
    }
};

class StrStream {
private:
    std::string str;
    void bitset_to_str(Bits& bits) {
        str.resize(bits.size() / 8);
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                str[i] = str[i] | (bits[i * byte_size + k] << k);
            }
        }
    }
public:
    StrStream() : StrStream(Bits()) {}
    StrStream(Bits bits) {
        bitset_to_str(bits);
    }
    StrStream& operator=(Bits bits) {
        bitset_to_str(bits);
        return *this;
    }
    char operator[](int index) {
        return str[index];
    }
    std::string getStr() {
        return str;
    }
};

/*
class BitStream {
public:
    std::vector<bool> str_to_bitset(std::string str) {
        std::vector<bool> bitset(str.size() * byte_size);
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                bitset[i * byte_size + k] = (str[i] >> k) & 1;
            }
        }
        return bitset;
    }
    std::string bitset_to_str(std::vector<bool> bitset) {
        std::string str(bitset.size() / 8, '\0');
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                str[i] = str[i] | (bitset[i * byte_size + k] << k);
            }
        }
        return str;
    }
    void print_bitset(std::vector<bool>& bitset) {
        for(int i = 0; i < bitset.size(); i++) {
            std::cout << bitset[i];
            if((i + 1) % 8 == 0) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};
*/