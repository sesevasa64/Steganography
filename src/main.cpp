#include <iostream>
#include <string>
#include <vector>
#include "config.hpp"
#include "bitstream/bitsteam.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

int main() {
    //initwindow(800, 600, "Test");
    //int r = 255, b = 0, g = 0;
    //int rgb = ((b & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (r & 0x0ff);
    //setbkcolor(rgb);
    //cleardevice();
    //getch();
    string str = "what";
    cout << str << endl;
    BitStream bs = str;
    auto bits = bs.getBits();
    StrStream ss = bits;
    cout << ss.getStr() << endl;
    return 0;
}