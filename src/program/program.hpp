#pragma once
#include <string>
#include <vector>
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
    typedef void (Program::*CryptoMode)(void);
    CryptoMode crypto_modes[2] = {decrypt, encrypt};

    std::string fromFile();
    std::string fromConsole();
    typedef std::string (Program::*ReadMode)(void);
    ReadMode read_modes[2] = {fromFile, fromConsole};

    void toFile(std::string encrypted);
    void toConsole(std::string encrypted);
    typedef void (Program::*WriteMode)(std::string);
    WriteMode write_modes[2] = {toFile, toConsole};

    const std::string& loadOption(std::string name, std::string prefix);
    Crypter_Mode setCrypterMode();
    Input_Mode setInputMode();

    InputParser& parser;
    Crypter_Mode crypter_mode;
    Input_Mode   input_mode = CMD;

    std::string filename;
    std::string password;
    std::string message;
    Image *image;
};