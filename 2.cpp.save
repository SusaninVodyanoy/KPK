#include "TXLib.h"

//-----------------------------------------------------------------------------

void DrawTree     (int moveX);
void DrawPlane1   (int moveXPlane1, COLORREF color);
void DrawPlane2   (int moveXPlane2, COLORREF color);
void txMyTriangle (double x1, double y1, double x2, double y2, double x3, double y3,
                    COLORREF color);
void FlyPlane1    (int moveX,int PAuse);
void FlyPlane2    (int moveX,int PAuse);
void LandingPlane (int PAuse);
//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow ( 800, 600);
    FlyPlane1      (   0, 100);
    FlyPlane2      (-300, 100);
    LandingPlane   ( 100);

    txSetFillColor (TX_BLACK);
    int pos = 0;
    while  (pos < 300)
       {
           txClear     ();
           txSelectFont("Comic Sans MS", 40);
           txTextOut   (pos, pos, "MI PRILETELI") ;
           pos+=10;
           txSleep     (100);
        }

    return 0;
    }

//{----------------------------------------------------------------------------
void DrawTree       (int moveX)
   {
        txSetColor     (TX_BROWN);
        txSetFillColor (TX_BROWN);
        txRectangle    (100+moveX, 580, 110+moveX, 600);
        txMyTriangle   ( 60+moveX, 580,  80+moveX, 530, 105+moveX, 580, TX_GREEN);
        txMyTriangle   ( 80+moveX, 530, 105+moveX, 580, 130+moveX, 530, TX_GREEN);
        txMyTriangle   (105+moveX, 580, 130+moveX, 530, 150+moveX, 580, TX_GREEN);
        txMyTriangle   ( 70+moveX, 530, 105+moveX, 490, 140+moveX, 530, TX_GREEN);
        txMyTriangle   ( 85+moveX, 490, 105+moveX, 450, 125+moveX, 490, TX_GREEN);
   }

//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void DrawPlane1   (int moveXPlane1, COLORREF color)
    {
        txSetFillColor (color);
        txEllipse (100+moveXPlane1,  80, 120+moveXPlane1, 130);
        txEllipse (100+moveXPlane1, 100, 300+moveXPlane1, 140);
        txEllipse (200+moveXPlane1, 120, 250+moveXPlane1, 130);
        txEllipse (295+moveXPlane1,  90, 305+moveXPlane1, 150);
        txCircle  (300+moveXPlane1, 120,   5                 );
        txEllipse (100+moveXPlane1, 110, 140+moveXPlane1, 130);
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void DrawPlane2   (int moveXPlane2, COLORREF color)
   {
        txSetFillColor (color);
        txEllipse (200+moveXPlane2,  40, 240+moveXPlane2, 200);
        txEllipse (100+moveXPlane2,  80, 120+moveXPlane2, 160);
        txEllipse (100+moveXPlane2, 100, 300+moveXPlane2, 140);
        txEllipse (295+moveXPlane2,  90, 305+moveXPlane2, 150);
        txCircle  (300+moveXPlane2, 120,   5                 );
        txEllipse (100+moveXPlane2, 110, 140+moveXPlane2, 130);
    }
//}----------------------------------------------------------------------------

//{-----------------------------------------------------------------------------

void txMyTriangle (double x1, double y1, double x2, double y2, double x3, double y3,
                   COLORREF color)
   {
        txSetColor (color);
        txSetFillColor (color);
        POINT MyTriangle[3] = {{x1, y1}, {x2, y2}, {x3, y3}};
        txPolygon (MyTriangle, 3);
   }

//}-----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void FlyPlane1     (int moveX,int PAuse)
    {
    while   (moveX < 600)
        {
            txSetFillColor (TX_BLACK);
            txClear();
            txSetColor     (TX_YELLOW,5);
            txSetFillColor (TX_PINK);

            DrawPlane1(moveX,TX_PINK);

            DrawTree      (0-moveX);
            DrawTree      (100-moveX);
            DrawTree      (200-moveX);
            DrawTree      (300-moveX);
            DrawTree      (400-moveX);

            moveX += 10;

            txSleep   (PAuse);
       }
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void FlyPlane2     (int moveX,int PAuse)
    {
     while   (moveX < 200)
       {

            txSetFillColor (TX_BLACK);
            txClear();
            txSetColor     (TX_YELLOW,5);
            txLine    ( 0,  20, 800,  20);
            txLine    ( 0, 320, 800, 320);

            DrawPlane2(moveX,TX_PINK);

            moveX += 10;
            txSleep   (PAuse);
       }
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void LandingPlane (int PAuse)
    {
    int i = 0;
    while   (i < 20)
       {
            txSetFillColor (TX_BLACK);
            txClear();
            txSetColor     (TX_YELLOW,5);
            txLine    (  0,  20, 800,  20);
            txLine    (  0, 320, 800, 320);
            DrawPlane2(200,TX_PINK);
            txCircle  (450, 160+i*10    ,   5     );
            txCircle  (460, 160+(i+1)*10,   5     );
            txCircle  (440, 160+(i+1)*10,   5     );
            txCircle  (445, 160+(i+2)*10,   5     );
            txCircle  (465, 160+(i+2)*10,   5     );
            txCircle  (455, 160+(i+2)*10,   5     );

            i++;
            txSleep   (PAuse);
       }
    }
//}----------------------------------------------------------------------------



