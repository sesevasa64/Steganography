#include <iostream>
#include <string>
#include <vector>
#include "config.hpp"
#include "bitstream/bitstream.hpp"
#include "triad/triad.hpp"
#include "crypters/crypters.hpp"
#include "image/image.hpp"
#include "point/point.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

int main() {
    //initwindow(800, 600, "Test");
    int r = 255, b = 0, g = 0;
    int rgb = ((b & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (r & 0x0ff);
    cout << (rgb & 0x0ff) << endl;
    //setbkcolor(rgb);
    //cleardevice();
    //getch();
    string str = "what";
    cout << str << endl;
    BitStream bs = str;
    auto bits = bs.getBits();
    StrStream ss = bits;
    cout << ss.getStr() << endl;
    //Point p1(1, 2), p2(3, 4);
    //swap(p1, p2);
    cout << ceil(double(byte_size) / min_bits) << endl;
    //cout << ceil(7. * byte_size / minimum_bits) * minimum_bits << endl;
    string mes = "hello";
    mes.reserve(25);
    mes += "what";
    cout << mes << endl;
    return 0;
}