#include "MicroBit.h"

MicroBit uBit;
int grav_to_pix(int g)
{
    int v = 2;
    if (g < -200)
        v--;
    if (g < -500)
        v--;
    if (g > 200)
        v++;
    if (g > 500)
        v++;

    return v;
}
int main()
{
    // uBit.init();

    // while(1)
    //     uBit.display.scroll("HELLO WORLD!");

    // Program 1
    // uBit.init();
    // uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
    // bool r_end = false;
    // int x = 2;
    // int y = 2;
    // while (1)
    // {
    //     if (x == 4 || y == 4)
    //     {
    //         r_end = true;
    //     }
    //     else if (x == 0 || y == 4)
    //     {
    //         r_end = false;
    //     }
    //     uBit.display.image.setPixelValue(x, y, 255);
    //     uBit.sleep(100);
    //     uBit.display.image.setPixelValue(x, y, 0);
    //     uBit.sleep(100);
    //     x = (r_end) ? x -= 1 : x += 1;
    //     y = (r_end) ? y -= 1 : y += 1;
    // }

    // Program 2
    // uBit.init();
    // uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    // while (1)
    // {
    //     int px = grav_to_pix(uBit.accelerometer.getX());
    //     int py = grav_to_pix(uBit.accelerometer.getY());

    //     uBit.display.image.clear(); // Without this, we'd be painting the screen!
    //     uBit.display.image.setPixelValue(px, py, 255);

    //     uBit.sleep(100);
    // }

    // Program 3
    uBit.init();
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    while (1)
    {
        int px = grav_to_pix(uBit.accelerometer.getX());
        int py = grav_to_pix(uBit.accelerometer.getY());

        uBit.display.image.clear(); // Without this, we'd be painting the screen!
        uBit.display.image.setPixelValue(px, py, 255);

        uBit.sleep(100);
    }
}
