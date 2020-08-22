#include <iostream>
#include <fstream>
#include <algorithm>
#include "program/program.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

int main(int argc, char **argv) {
    InputParser parser(argc, argv);
    Program program(parser);
    try {
        program.run();
    }
    catch(std::exception& exp) {
        cout << exp.what() << endl;
    }
    return 0;
}