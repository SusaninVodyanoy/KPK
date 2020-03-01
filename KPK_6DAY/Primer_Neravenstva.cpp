
#include "TXLib.h"

void DrawParabola ();
void DrawCircle ();
void DrawRomb ();

int main()
    {
    txCreateWindow (800, 600);

    DrawParabola ();
    DrawCircle ();
    DrawRomb ();

    return 0;
    }

void DrawParabola ()
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (y>x*x)
            txSetPixel (400+50*x, 300 - 50*y,TX_LIGHTRED);
        }
    }

void DrawCircle ()
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (x*x+y*y<=4)
            txSetPixel (401+50*x, 300 - 50*y,TX_LIGHTGREEN);

        }
    }

void DrawRomb ()
    {

    for (double y = -10; y<=10; y += 0.04)
    for (double x = -10; x<=10; x += 0.04)
        {
         if (fabs (x)+fabs (y)<=4)
            txSetPixel (400+50*x, 301 - 50*y,TX_LIGHTBLUE);

        }
    }
