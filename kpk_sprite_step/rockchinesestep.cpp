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
    AttributeImg s1 = {100, 100, 5, 4, txLoadImage ("rockchinesestep3.bmp")};

    txCreateWindow (800, 600);
    txBegin ();
    HDC backImage = txLoadImage ("karta.bmp");
    HDC mapImage  = txLoadImage ("map_rock.bmp");


    int size_step = 5;
    int anim = 0;

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++, anim)
        {

        txSetFillColor (TX_BLACK);
        txClear;
        if (!GetKeyState (VK_CAPITAL))
        txBitBlt (txDC(),0,0,0,0, mapImage);


        if (!GetKeyState (VK_SCROLL))
        txBitBlt (txDC(),0,0,0,0, backImage);


        int oldx = s1.posx, oldy = s1.posy;


        COLORREF color = txGetPixel (s1.posx,s1.posy, mapImage );
        //$x(color);

        //animic (s1,t,anim);



     if (!txGetAsyncKeyState (VK_LEFT) && !txGetAsyncKeyState (VK_RIGHT) && !txGetAsyncKeyState (VK_UP) && !txGetAsyncKeyState (VK_DOWN)) {  animic (s1,t,anim);};

        if (txGetAsyncKeyState (VK_LEFT))
            {
            anim = 2;
            s1.posx = s1.posx - size_step;
            color = txGetPixel (s1.posx,s1.posy+txGetExtentY (s1.catImage) /(2*s1.kadry), mapImage);
            if  (color != RGB (255, 0, 0)) {s1.posx = oldx, s1.posy = oldy;}
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_RIGHT))
            {
            anim = 3;
            s1.posx = s1.posx + size_step;
            color = txGetPixel (s1.posx+txGetExtentX (s1.catImage) /s1.kadrx,s1.posy+txGetExtentY (s1.catImage) /(2*s1.kadry), mapImage );
            if  (color != RGB (255, 0, 0)) {s1.posx = oldx, s1.posy = oldy;}
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_UP))
            {
            anim = 1;
            s1.posy = s1.posy - size_step;
            color = txGetPixel (s1.posx,s1.posy+txGetExtentY (s1.catImage) /(2*s1.kadry), mapImage );
            if  (color != RGB (255, 0, 0)) {s1.posx = oldx, s1.posy = oldy+1;}
            animic (s1,t,anim);
            }

        if (txGetAsyncKeyState (VK_DOWN))
            {
            anim = 0;
            s1.posy = s1.posy + size_step;
            color = txGetPixel (s1.posx,s1.posy+txGetExtentY (s1.catImage) /s1.kadry, mapImage );
            if  (color != RGB (255, 0, 0)) {s1.posx = oldx, s1.posy = oldy;}
            animic (s1,t,anim);
            }



        txSleep (50);
        }

    txDeleteDC (s1.catImage);
    txDeleteDC (backImage);
    txDeleteDC (mapImage);
    return 0;
    }

void animic (AttributeImg ig, int step, int anim)
    {
    //txTransparentBlt (txDC(), ig.posx, ig.posy, 800, 600, ig.catImage,0,0, TX_WHITE);
    int frameSizex = txGetExtentX (ig.catImage) /ig.kadrx;
    int frameSizey = txGetExtentY (ig.catImage) /ig.kadry;
    txTransparentBlt (txDC(), ig.posx, ig.posy, frameSizex, frameSizey,
              ig.catImage,
              (step % ig.kadrx) * frameSizex, anim * frameSizey, RGB (255, 0, 0));
    //txBitBlt (txDC(), ig.posx, ig.posy, frameSizex, frameSizey,
    //          ig.catImage,
    //          (step % ig.kadrx) * frameSizex, anim * frameSizey);


    }
