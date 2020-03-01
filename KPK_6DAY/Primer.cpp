#include "TXLib.h"
//const int SIN = 1,
//          SQR = 2;

void DrawGraphic (double (*func) (double x), COLORREF color);
double Sqr (double x);
double sin2x (double x) ;


int main()
    {
    txCreateWindow (800, 600);
    DrawGraphic(&sin, TX_LIGHTGREEN);
    DrawGraphic(&sin2x, TX_LIGHTGREEN);
    DrawGraphic(&Sqr, TX_LIGHTRED);
    //DrawGraphic(3);
    // DrawGraphic(4);
    }

typedef unsigned long long superlong_t; // ассоциац€ выбраного имени с существующим типом

typedef double (*func_t) (double x);

void DrawGraphic (func_t func, COLORREF color)
    {
    txSetColor      (color);
    txSetFillColor  (color);

    double x = -10;
    while (x<= +10)
        {
        double y = (*func) (x);
        /*switch (func)
            {
            case SIN: y = sin (x);break;
            case SQR: y = Sqr (x);break;

            default: printf ("ERROR: DrawGraphic(): Invalid func %d\n", func);
            }*/

        txCircle (400+50*x, 300 - 50*y, 3);

        x += 0.01 ;
        }
    }

double Sqr (double x) {return x*x;}
double sin2x (double x) {return sin (2*x);}
