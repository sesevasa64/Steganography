#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../config.hpp"

class BitStream {
private:
    std::vector<bool> bits;
    void str_to_bitset(std::string str) {
        bits.resize(str.size() * byte_size);
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                bits[i * byte_size + k] = (str[i] >> k) & 1;
            }
        }
    }
public:
    BitStream() : BitStream(std::string()) {}
    BitStream(const char *str) : BitStream(std::string(str)) {}
    BitStream(std::string str) {
        str_to_bitset(std::move(str));
    }
    BitStream& operator=(std::string str) {
        str_to_bitset(std::move(str));
        return *this;
    }
    BitStream& operator=(const char* str) {
        str_to_bitset(std::string(str));
        return *this;
    }
    std::vector<bool> getBits() {
        return bits;
    }
};

class StrStream {
private:
    std::string str;
    void bitset_to_str(std::vector<bool>& bits) {
        str.resize(bits.size() / 8);
        for(int i = 0; i < str.size(); i++) {
            for(int k = 0; k < byte_size; k++) {
                str[i] = str[i] | (bits[i * byte_size + k] << k);
            }
        }
    }
public:
    StrStream() : StrStream(std::vector<bool>()) {}
    StrStream(std::vector<bool> bits) {
        bitset_to_str(bits);
    }
    StrStream& operator=(std::vector<bool> bits) {
        bitset_to_str(bits);
        return *this;
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