#include "TXLib.h"
const int SIN = 1,
          SQR = 2;

void DrawGraphic (int func, COLORREF color);
double Sqr (double x);


int main()
    {
    txCreateWindow (800, 600);
    DrawGraphic(SIN, TX_LIGHTGREEN);
    DrawGraphic(SQR, TX_LIGHTRED);
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
        double y = 0;
        switch (func)
            {
            case SIN: y = sin (x);break;
            case SQR: y = Sqr (x);break;

            default: printf ("ERROR: DrawGraphic(): Invalid func %d\n", func);
            }

        txCircle (400+50*x, 300 - 50*y, 3);

        x += 0.01 ;
        }
    }

double Sqr (double x) {return x*x;}
