#include "TXLib.h"

struct AttributeImg
{
int posx, posy;
int kadrx, kadry;
HDC catImage;
};

void animic (AttributeImg ig, int step, int anim);


// POINT sz = txGetExtent();
int main()
    {
    AttributeImg s1 = {100, 100, 3, 4, txLoadImage ("cat-drawing-film.bmp")};
    AttributeImg s2 = {600, 100, 6, 2, txLoadImage ("cat-run-cycle.bmp")};
    AttributeImg s3 = {100, 400, 5, 4, txLoadImage ("leopad.bmp")};
    AttributeImg s4 = {600, 400, 6, 1, txLoadImage ("tiger-game-sprites.bmp")};



    txCreateWindow (800, 600);
    txSetColor     (TX_WHITE);
    txClear;
    //HDC catImage = txLoadImage ("cat-drawing-film.bmp");
    //int framesx = 3;
    //int framesy = 4;
    //HDC catImage = txLoadImage ("cat-run-cycle.bmp");
    //int framesx = 6;
    //int framesy = 2;
    //HDC catImage = txLoadImage ("leopad.bmp");
    //int framesx = 5;
    //int framesy = 4;
    //HDC catImage = txLoadImage ("tiger-game-sprites.bmp");
    //int framesx = 6;
    //int framesy = 1;




    int anim = 0;
    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++, anim)
        {
        animic (s1,t,anim);
        animic (s2,t,anim);
        animic (s3,t,anim);
        animic (s4,t,anim);
        if (txGetAsyncKeyState (VK_LEFT))  anim--;
        if (txGetAsyncKeyState (VK_RIGHT)) anim++;
        txSleep (80);
        }

    txDeleteDC (s1.catImage);
    txDeleteDC (s2.catImage);
    txDeleteDC (s3.catImage);
    txDeleteDC (s4.catImage);
    return 0;
    }

void animic (AttributeImg ig, int step, int anim)
    {

    int frameSizex = txGetExtentX (ig.catImage) /ig.kadrx;
    int frameSizey = txGetExtentY (ig.catImage) /ig.kadry;
    txBitBlt (txDC(), ig.posx, ig.posy, frameSizex, frameSizey,
              ig.catImage,
              (step % ig.kadrx) * frameSizex, anim * frameSizey);


    }
