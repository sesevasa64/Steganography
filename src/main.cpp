#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <bitset>
#include <ctime>
#include "config.hpp"
#include "bitstream/bitstream.hpp"
#include "triad/triad.hpp"
#include "crypters/crypters.hpp"
#include "image/image.hpp"
#include "point/point.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

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

void test();

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
            cout << "Wrong password!" << endl;
            return -1;
        }
        cout << "Encrypted message: ";
        cout << message << endl;
    }
    else {
        Decrypter dc(image, password);
        cout << "Decrypted message: ";
        string message;
        input(message);
        dc.decrypt(message);
        cout << "Message decrypted succesfully!";
    }
    delete image;
    closegraph();
    return 0;
}

int get_random(std::list<int>& ls) {
    std::list<int>::iterator it = ls.begin();
    std::advance(it, rand() % ls.size());
    int result = *it;
    ls.erase(it);
    return result;
}   

void test() {
    //srand(time(0));
    std::list<int> ls(12);
    std::list<int>::iterator it = ls.begin();
    int height = 3, width = 4;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            *(it++) = y * width + x; 
        }
    }
    for(auto it = ls.begin(); it != ls.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    for(int i = 0; i < 12; i++) {
        cout << get_random(ls) << ' ';
    }
    cout << endl;
}