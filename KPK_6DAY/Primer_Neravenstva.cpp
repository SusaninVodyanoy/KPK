
#include "TXLib.h"


void DrawCircle (double x0, double y0, COLORREF color, double xx, double yy, double radius);
void Drawears   (double x0, double y0, COLORREF color, double xx, double yy, double radius);
void DrawRomb ();
void DrawParabola ();
void DrawPupils (double x0, double y0, COLORREF color, double xx, double yy);
void Drawmoustache ();

int main()
    {
    txCreateWindow (800, 600);

    DrawParabola    (                                   );
    DrawCircle      (0, 0, TX_ORANGE,         1,  1,   5);
    DrawCircle      (0, 0, TX_LIGHTBLUE,    -50, 30, 0.2);
    DrawCircle      (0, 0, TX_LIGHTBLUE,     50, 30, 0.2);
    DrawRomb        (                                   );
    Drawears        (0, 0, TX_BROWN,          1,  1,   5);
    Drawmoustache   (                                   );
    DrawPupils      (0, 0, TX_YELLOW,       -45, 30     );
    DrawPupils      (0, 0, TX_YELLOW,        55, 30     );
    return 0;
    }

void DrawParabola ()
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (y>2*x*x && y<x*x+0.3)
            txSetPixel (400+50*x, 380 - 50*y,TX_LIGHTRED);
        }
    }

void DrawCircle (double x0, double y0, COLORREF color, double xx, double yy, double radius)
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if ((x+x0)*(x+x0)+(y+y0)*(y+y0)<=radius)
            txSetPixel (401 + xx + 50*x, 300 - yy - 50*y,color);

        }
    }

void DrawRomb ()
    {
    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (fabs (x)+fabs (y)<=2 && y>1.4)
            txSetPixel (400+50*x, 301 +90 - 50*y,TX_BROWN);

        }
    }

void Drawears   (double x0, double y0, COLORREF color, double xx, double yy, double radius)
    {
    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (y < fabs (1.5*(x+x0)+0.3) && (x+x0)*(x+x0)+(y+y0)*(y+y0)>=radius+0.5 && y>0.5 && x<2.2 && x>-2.2)
            txSetPixel (400+xx+50*x, 301 +yy- 50*y,color);

        }
    }


void Drawmoustache ()
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (((y>-0.1*x+0.01 && y<-0.1*x+0.05) || (y>0.1*x+0.01 && y<0.1*x+0.05 ))&& x<2.5 && x>-2.5 && !(x<1 && x>-1))
            txSetPixel (400+50*x, 350 - 50*y,TX_LIGHTRED);
        }
    }
void DrawPupils (double x0, double y0, COLORREF color, double xx, double yy)
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (y*y<-x*1.4 && y*y<x*1.4+0.5)
            txSetPixel (401 + xx + 50*x, 300 - yy - 50*y,TX_LIGHTRED);
        }
   }
