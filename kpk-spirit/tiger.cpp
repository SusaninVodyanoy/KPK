#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);
    txSetFillColor     (TX_WHITE);
    //HDC catImage = txLoadImage ("cat-drawing-film.bmp");
    //int framesx = 3;
    //int framesy = 4;
    //HDC catImage = txLoadImage ("cat-run-cycle.bmp");
    //int framesx = 6;
    //int framesy = 2;
    //HDC catImage = txLoadImage ("leopad.bmp");
    //int framesx = 5;
    //int framesy = 4;
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
        if (txGetAsyncKeyState ('4')) anim = 3;
        txSleep (80);
        }

    txDeleteDC (catImage);
    return 0;
    }
