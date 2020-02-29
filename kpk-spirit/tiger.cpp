#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);
    HDC catImage = txLoadImage ("tiger-game-sprites.bmp");
    int framesx = 6;
    int framesy = 1;

    int frameSizex = txGetExtentX (catImage) /framesx;
    int frameSizey = txGetExtentY (catImage) /framesy;

    int anim = 0;

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++)
        {
        txBitBlt (txDC(), 100, 100, frameSizex, frameSizey,
                  catImage,
                  (t % framesx) * frameSizex, anim * frameSizey);
        if (txGetAsyncKeyState ('1')) anim = 0;
        if (txGetAsyncKeyState ('2')) anim = 1;
        if (txGetAsyncKeyState ('3')) anim = 2;
        txSleep ();
        }

    txDeleteDC (catImage);
    return 0;
    }
