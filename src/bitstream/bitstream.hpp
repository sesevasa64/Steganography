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
    int calc_size(int str_size);
    void str_to_bitset(std::string& str);
    void str_to_bitset(Str_It start, Str_It end);
public:
    BitStream();
    BitStream(const char *str);
    BitStream(std::string& str);
    BitStream(std::string&& str);
    BitStream(BitStream&& another);
    BitStream(Str_It start, Str_It end);
    BitStream& operator=(std::string& str);
    BitStream& operator=(std::string&& str);
    BitStream& operator=(const char* str);
    BitStream& operator=(const BitStream& another);
    bool operator[](int index);
    Bits getBits();
};

class StrStream {
private:
    std::string str;
    void bitset_to_str(Bits& bits);
public:
    StrStream();
    StrStream(Bits bits);
    StrStream& operator=(Bits bits);
    char operator[](int index);
    std::string getStr();
};