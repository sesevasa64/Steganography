#include <iostream>
#include <fstream>
#include <algorithm>
#include "program/program.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

int main(int argc, char **argv) {
    InputParser parser(argc, argv);
    try {
        Program program(parser);
        program.run();
    }
    catch(std::exception& exp) {
        cout << exp.what() << endl;
    }
    return 0;
}

/*
template<typename T>
void input(T& value) {
    while(true) {
        cin >> value;
        if(cin.fail()) {
            cout << "Input Error!" << endl;
            cin.clear();
            continue;
        }
        cin.ignore(100, '\n');
        break;
    }
}

template<>
void input(string& value) {
    getline(cin, value);
}

string decrypt_from_file();
void encrypt_to_file(string& message);

int main() {
    initwindow(800, 600);
    std::cout << "Choose mode (0 - Decrypting, 1 - Encrypting)" << endl;
    std::cout << "Mode: ";
    bool mode;
    input(mode);
    std::cout << "File name: ";
    string filename;
    input(filename);
    Image *image;
    try {
        image = new Image(filename);
    } catch(std::exception& exp) {
        cout << exp.what() << endl;
        return -1;
    }
    std::cout << "Password: ";
    string password;
    input(password);
    if(mode) {
        Encrypter ec(image, password);
        string message;
        try {
            message = ec.encrypt();
        } catch(std::exception& exp) {
            cout << exp.what() << endl;
            return -1;
        }
        cout << "Do you want save message to file? (0 - No, 1 - Yes)" << endl;
        bool stream;
        input(stream);
        if(stream) {
            encrypt_to_file(message);
            cout << "Message encrypted succesfully!" << endl;
        }
        else {
            cout << "Encrypted message: ";
            cout << message << endl;
        }
    }
    else {
        Decrypter dc(image, password);
        cout << "Image capacity: " << dc.Capacity() << " characters" << endl;
        cout << "Do you want load message from file? (0 - No, 1 - Yes)" << endl;
        cout << "Answer: ";
        string message;
        bool stream;
        input(stream);
        if(stream) {
            message = decrypt_from_file();
        }
        else {
            cout << "Decrypted message: ";
            string message;
            input(message);
            dc.decrypt(message);
        }
        cout << "Message decrypted succesfully!";
    }
    delete image;
    closegraph();
    return 0;
}

string decrypt_from_file() {
    string name;
    cout << "Input file name: ";
    input(name);
    ostringstream buf;
    ifstream file(name);
    buf << file.rdbuf();
    file.close();
    return buf.str();
}

void encrypt_to_file(string& message) {
    string name;
    cout << "Input file name: ";
    input(name);
    ofstream file(name);
    file << message;
    file.close();
}
*/