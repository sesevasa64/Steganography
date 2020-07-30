#include <iostream>
#include "../lib/winbgim.hpp"

using namespace std;

int main() {
    initwindow(800, 600, "Test");
    int r = 255, b = 0, g = 0;
    int rgb = ((b & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (r & 0x0ff);
    setbkcolor(rgb);
    cleardevice();
    getch();
    return 0;
}