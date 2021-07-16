#include "TXLib.h"

const int step = 1;

int main()
    {
    txCreateWindow (800, 600);
    txBegin();

    HDC planImage = txLoadImage ("plan.bmp");
    HDC backImage = txLoadImage ("plan_back.bmp");
    HDC carImage = txLoadImage ("car.bmp");
    HDC car1Image = txLoadImage ("car_right.bmp");

    int x = 20, y = 162, r = 10;
    int old_x = x, old_y = y;

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++)
        {
        txBitBlt (txDC (), 0, 0, 0, 0, backImage);

        COLORREF color = txGetPixel (x, y);

        if (color == RGB (255, 255, 0))
            {
            x = old_x;
            y = old_y;
            }

        txBitBlt (txDC (), 0, 0, 0, 0, planImage);

        old_x = x;
        old_y = y;
        int v = 1;

        if (txGetAsyncKeyState (VK_RIGHT))
            {
            x += step;
            v = 1;
            }

        if (txGetAsyncKeyState (VK_LEFT))
            {
            x -= step;
            v = 2;
            }

        if (txGetAsyncKeyState (VK_UP)) y -= step*2;
        if (txGetAsyncKeyState (VK_DOWN)) y += step*5;

        if (v == 1) txTransparentBlt (txDC (), x, y, 0, 0, car1Image, 0, 0, RGB (255, 255, 255));
        if (v == 2) txTransparentBlt (txDC (), x, y, 0, 0, carImage, 0, 0, RGB (255, 255, 255));

        txSleep();
        }

    txDeleteDC (planImage);
    txDeleteDC (backImage);
    txDeleteDC (carImage);
    txDeleteDC (car1Image);

    return 0;
    }
