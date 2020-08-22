#pragma once
#include <string>
#include <vector>
#include <functional>
#include "../image/image.hpp"

class InputParser {
public:
    InputParser(int &argc, char **argv);
    const std::string& getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
private:
    std::vector <std::string> tokens;
    std::string empty{};
};

enum Crypter_Mode {
    DECRYPT = 0,
    ENCRYPT = 1,
};

enum Input_Mode {
    File    = 0,
    CMD     = 1,
};

class Program {
public:
    Program(InputParser& parser);
    ~Program();
    void run();
private:
    void decrypt();
    void encrypt();
    using CryptoMode = void (Program::*)();
    CryptoMode crypto_modes[2] = {decrypt, encrypt};

    std::string fromFile();
    std::string fromConsole();
    using ReadMode = std::string (Program::*)();
    ReadMode read_modes[2] = {fromFile, fromConsole};

    void toFile(std::string encrypted);
    void toConsole(std::string encrypted);
    using WriteMode = void (Program::*)(std::string);
    WriteMode write_modes[2] = {toFile, toConsole};

    const std::string& loadOption(std::string name, std::string prefix);
    Crypter_Mode setCrypterMode();
    Input_Mode setInputMode();

    Crypter_Mode crypter_mode;
    Input_Mode   input_mode;

    std::string filename;
    std::string password;
    std::string message;

    InputParser& parser;
    Image *image;
};