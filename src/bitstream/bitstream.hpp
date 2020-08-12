#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "../config.hpp"

typedef std::vector<bool> Bits;
typedef std::string::const_iterator Str_It;

class BitStream {
private:
    Bits bits;
    int calc_size(int str_size);
    void str_to_bitset(const std::string& str);
    void str_to_bitset(Str_It start, Str_It end);
public:
    BitStream();
    BitStream(const char *str);
    BitStream(const std::string& str);
    BitStream(const std::string&& str);
    BitStream(BitStream&& another);
    BitStream(Str_It start, Str_It end);
    BitStream& operator=(const std::string& str);
    BitStream& operator=(const std::string&& str);
    BitStream& operator=(const char* str);
    BitStream& operator=(BitStream&& another);
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