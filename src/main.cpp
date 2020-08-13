#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "config.hpp"
#include "bitstream/bitstream.hpp"
#include "triad/triad.hpp"
#include "crypters/crypters.hpp"
#include "image/image.hpp"
#include "point/point.hpp"
#include "../lib/winbgim.hpp"

using namespace std;

int main() {
    {
        int r = 255, b = 0, g = 0;
        int rgb = ((b & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (r & 0x0ff);
        cout << (rgb & 0x0ff) << endl;
        int mask = 0xff;
        int test = 0b0000010100000011;
        int res = test & mask;
        res = res & ~(1u << 0);
        res |= 0 << 0;
        cout << res << endl;
        int ans = 0, k = 0;
        BitStream stream("?");
        cout << "Before: " << bitset<32>(ans) << endl;
        for(int i = 0; i < 24; i += 8) {
            for(int j = 0; j < 2; j++) {
                ans &= ~(1u << (i + j));
                ans |= stream[k++] << (i + j);
            }
        }
        cout << "After:  " << bitset<32>(ans) << endl;
        Bits bits(6 + 2);
        k = 0;
        for(int i = 0; i < 24; i += 8) {
            for(int j = 0; j < 2; j++) {
                bits[k++] = (ans >> (i + j)) & 1;
            }
        }
        cout << "Aga: " << StrStream(bits).getStr() << endl;
    }
    cout << endl;
    {
        string str = "what";
        cout << str << endl;
        BitStream bs = str;
        auto bits = bs.getBits();
        StrStream ss = bits;
        cout << ss.getStr() << endl;
        string mes = "hello";
    }
    cout << endl;
    {
        initwindow(800, 600);
        Image image("tiger.bmp");
        putimage(0, 0, image.get(), 0);
        Pixels pixels(pixel_size);
        for(int i = 0; i < pixel_size; i++) {
            pixels[i] = image[i];
        }
        string mes = "no";
        BitStream bs = mes;
        Triad triad(pixels);
        triad.decrypt(std::move(bs));
        string res = triad.encrypt();
        cout << "Decoding: " << mes << endl;
        cout << "Encoding: " << res << endl;
        getch();
    }
    return 0;
}