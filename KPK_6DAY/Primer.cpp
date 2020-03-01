#include "TXLib.h"
void DrawGraphic (int func, COLORREF color);
double Sqr (double x);


int main()
    {
    txCreateWindow (800, 600);
    DrawGraphic(1, TX_LIGHTGREEN);
    DrawGraphic(2, TX_LIGHTRED);
    //DrawGraphic(3);
    // DrawGraphic(4);
    }

void DrawGraphic (int func, COLORREF color)
    {
    txSetColor      (color);
    txSetFillColor  (color);

    double x = -10;
    while (x<= +10)
        {
        int y = Sqr(x);
        if (func == 1) y = sin (x);
        if (func == 2) y = Sqr (x);
        txCircle (400+10*x, 300 - 10*y, 3);
        x += 0.01 ;
        }
    }

double Sqr (double x) {return x*x;}
