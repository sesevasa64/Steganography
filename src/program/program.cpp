#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "../crypters/crypters.hpp"
#include "program.hpp"

InputParser::InputParser(int &argc, char **argv){
    for(int i = 1; i < argc; i++) {
        tokens.push_back(std::string(argv[i]));
    }
}

const std::string& InputParser::getCmdOption(const std::string& option) const {
    auto itr = std::find(tokens.begin(), tokens.end(), option);
    auto res = itr + 1;
    if (itr != tokens.end() && res != tokens.end() && (*res)[0] != '-'){
        return *res;
    }
    return empty;
}

bool InputParser::cmdOptionExists(const std::string &option) const {
    return std::find(tokens.begin(), tokens.end(), option) != tokens.end();
}

Program::Program(InputParser& parser) : parser(parser) {}

const std::string& Program::loadOption(std::string name, std::string prefix) {
    const auto& option = parser.getCmdOption(prefix);
    if(option.empty()) {
        char buffer[256];
        sprintf(buffer, "Error: %s is not selected!", name.c_str());
        throw std::invalid_argument(buffer);
    }
    return option;
}

Crypter_Mode Program::setCrypterMode() {
    auto& option = loadOption("Mode", "-mode");
    if(option == "decrypt") {
        filename = "input.txt";
        return DECRYPT;
    }
    else if(option == "encrypt") {
        filename = "output.txt";
        return ENCRYPT;
    }
    throw std::invalid_argument("Error: Unknown mode!");
}

Input_Mode Program::setInputMode() {
    bool input_option = parser.cmdOptionExists("-f");
    if(input_option) {
        auto& res = parser.getCmdOption("-f");
        if(!res.empty()) {
            filename = res;
        }
        return File;
    }
    return CMD;
}

void Program::run() {
    initwindow(800, 600, "Testing");
    crypter_mode = setCrypterMode();
    input_mode   = setInputMode();
    image        = new Image(loadOption("Image", "-i"));
    password     = loadOption("Password", "-p");
    if(crypter_mode == DECRYPT && input_mode == CMD) {
        message  = loadOption("Message", "-m");
    }
    std::invoke(crypto_modes[crypter_mode], this);
}

void Program::decrypt() {
    Decrypter dc(image, password);
    std::cout << "Image capacity: " << dc.Capacity();
    std::cout << " characters" << std::endl;
    dc.decrypt(std::invoke(read_modes[input_mode], this));
    std::cout << "Message decrypted succesfully!" << std::endl;
}

std::string Program::fromFile() {
    std::ostringstream buffer;
    std::ifstream file(filename);
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

std::string Program::fromConsole() {
    return message;
}

void Program::encrypt() {
    Encrypter ec(image, password);
    std::string encrypted = ec.encrypt();
    std::invoke(write_modes[input_mode], this, encrypted);
    std::cout << "Message encrypted succesfully!" << std::endl;
}

void Program::toFile(std::string encrypted) {
    std::ofstream file(filename);
    file << encrypted;
    file.close();
}

void Program::toConsole(std::string encrypted) {
    std::cout << "Encrypted message: ";
    std::cout << encrypted << std::endl;
}

Program::~Program() {
    delete image;
    closegraph();
}