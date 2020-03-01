#include "TXLib.h"
//const int SIN = 1,
//          SQR = 2;

void DrawGraphic    (double (*func) (double x), COLORREF color,
                    double k = 1, double l = 1,
                    double a = 0, double b = 0);

double Sqr          (double x);

int main()
    {
    txCreateWindow (800, 600);

    txLine (400, 600, 400, 0);
    txLine (000, 300, 800, 300);

    for (int t = -10; t<=10; t++)
        {
        DrawGraphic(&sin,   TX_LIGHTGREEN   ,t   , 1        );
        DrawGraphic(&Sqr,   TX_LIGHTRED     ,t   , 1        );
        //DrawGraphic(&Sqr,   TX_LIGHTRED     ,1   , t ,    10);
        //DrawGraphic(&Sqr,   TX_LIGHTRED     ,1   , t ,   -10);
        txSleep (50);
        }

    //DrawGraphic(3);
    // DrawGraphic(4);
    }

typedef unsigned long long superlong_t; // ассоциац€ выбраного имени с существующим типом

typedef double (*func_t) (double x);

void DrawGraphic (func_t func, COLORREF color,
                    double k, double l,
                    double a, double b)
    {
    txSetColor      (color);
    txSetFillColor  (color);

    double x = -10;
    while (x<= +10)
        {
        double y = k*(*func) (l*x+a)+b;
        /*switch (func)
            {
            case SIN: y = sin (x);break;
            case SQR: y = Sqr (x);break;

            default: printf ("ERROR: DrawGraphic(): Invalid func %d\n", func);
            }*/

        txCircle (400+50*x, 300 - 50*y, 2);

        x += 0.01 ;
        }
    }

double Sqr   (double x) {return x*x;}
