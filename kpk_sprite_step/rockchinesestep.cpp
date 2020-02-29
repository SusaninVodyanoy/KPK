#include "TXLib.h"

struct AttributeImg
{
int posx, posy;
int kadrx, kadry;
HDC catImage;
};

void animic (AttributeImg ig, int step, int anim);


int main()
    {
    AttributeImg s1 = {100, 100, 5, 4, txLoadImage ("rockchinesestep.bmp")};

    txCreateWindow (800, 600);
    txBegin ();

    int size_step = 5;
    int anim = 0;
    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++, anim)
        {

        animic (s1,t,anim);

        if (txGetAsyncKeyState (VK_LEFT))
            {
            anim = 2;
            s1.posx = s1.posx - size_step;
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_RIGHT))
            {
            anim = 3;
            s1.posx = s1.posx + size_step;
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_UP))
            {
            anim = 1;
            s1.posy = s1.posy - size_step;
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_DOWN))
            {
            anim = 0;
            s1.posy = s1.posy + size_step;
            animic (s1,t,anim);
            }

        txSleep (80);
        }

    txDeleteDC (s1.catImage);
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
