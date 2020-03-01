
#include "TXLib.h"
void DrawGraphic ();


int main()
    {
    txCreateWindow (800, 600);
DrawGraphic();

    }

void DrawGraphic ()
    {
    double x = -10;
    while (x<= +10)
        {
        int y = x*x;
        txCircle (400+x, 300 - y, 2);
        x += 0.1 ;
        }
    }
