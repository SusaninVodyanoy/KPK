#include "TXLib.h"


//-----------------------------------------------------------------------------

void DrawBIRD     (double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing);
void RightturnBIRD(double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing);
void LeftturnBIRD (double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing);
void BIRDWingsUP  (double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing);
void BIRDWingsDOWN(double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing);
void txMyTriangle (double x1, double y1, double    x2, double    y2,
                    double x3, double y3, COLORREF color);

//-----------------------------------------------------------------------------

int main()
    {
        txCreateWindow (800, 600);
        txBegin();
        int pos = 700;
        while  (pos >= 300)
           {
            txSetFillColor (TX_BLACK);
            txClear     ();
            BIRDWingsUP (400, pos+5,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep     (30);
            txSetFillColor (TX_BLACK);
            txClear     ();
            DrawBIRD    (400, pos,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep     (30);
            pos -= 10;
           }

        pos = 400;
        while  (pos < 700)
           {
            txSetFillColor  (TX_BLACK);
            txClear         ();
            RightturnBIRD   (pos, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep         (50);
            pos += 10;
           }

            DrawBIRD    (700, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep     (50);

        pos = 700;
        while  (pos >= 100)
           {
            txSetFillColor (TX_BLACK);
            txClear      ();
            LeftturnBIRD (pos, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep      (50);
            pos -= 10;
           }
            DrawBIRD    (100, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep     (50);

        pos = 100;
        while  (pos < 400)
           {
            txSetFillColor (TX_BLACK);
            txClear       ();
            RightturnBIRD (pos, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep       (50);
            pos += 10;
           }
            DrawBIRD    (400, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep     (50);

        int i = 0;
        while  (i <= 10)
           {
            txSetFillColor (TX_BLACK);
            txClear     ();
            DrawBIRD    (400, 300,  1+i,  1+i, TX_YELLOW, TX_GREEN);
            txSleep     (50);
            i++;
           }

        i = 11;
        while  (i >0)
           {
            txSetFillColor (TX_BLACK);
            txClear     ();
            DrawBIRD    (400, 300,  i,  i, TX_YELLOW, TX_GREEN);
            txSleep     (50);
            i--;
           }
            DrawBIRD      (400, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep       (50);
            RightturnBIRD (400, 300,  1,  1, TX_YELLOW, TX_GREEN);
            LeftturnBIRD  (400, 300,  1,  1, TX_YELLOW, TX_GREEN);
            txSleep       (50);
            txSetColor (TX_YELLOW);
            txSelectFont("Comic Sans MS", 40);
            txTextOut   (300, 400, "NE VZLETELO");

    }

//{----------------------------------------------------------------------------
void txMyTriangle (double x1, double y1, double x2, double y2, double x3, double y3, COLORREF color)
    {
        txSetColor (color);
        txSetFillColor (color);
        POINT MyTriangle[5] = {{x1, y1}, {x2, y2}, {x3, y3}};
        txPolygon (MyTriangle, 3);
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void    DrawBIRD(double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing)
    {
        txSetFillColor (color_body);
        txEllipse       (X0 - 10*zoomX, Y0 - 30*zoomY, X0 + 10*zoomX, Y0 + 30*zoomY);
        txCircle        (X0 -  1      , Y0 - 35*zoomY,       5*zoomX               );
        txMyTriangle    (X0 -  5*zoomX, Y0 - 40*zoomY-5*zoomY/2, X0 +  5*zoomX/2, Y0 - 40*zoomY-5*zoomY/2,  X0           , Y0 - 50*zoomY-5*zoomY, color_wing);//Клюв
        txMyTriangle    (X0 - 60*zoomX, Y0 -  5*zoomY, X0 - 10*zoomX, Y0 - 25*zoomY,  X0 - 10*zoomX, Y0 + 15*zoomY, color_wing);//Левое крыло
        txMyTriangle    (X0 + 60*zoomX, Y0 -  5*zoomY, X0 + 10*zoomX, Y0 - 25*zoomY,  X0 + 10*zoomX, Y0 + 15*zoomY, color_wing);//Правое крыло
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 - 15*zoomX, Y0 + 50*zoomY,  X0 - 10*zoomX, Y0 + 60*zoomY, color_wing);//Левая секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 -  5*zoomX, Y0 + 60*zoomY,  X0 +  5*zoomX, Y0 + 60*zoomY, color_wing);//Средняя секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 + 10*zoomX, Y0 + 60*zoomY,  X0 + 15*zoomX, Y0 + 50*zoomY, color_wing);//Правая секция хвоста
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void    RightturnBIRD(double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing)
    {
        txSetFillColor (color_body);
        txEllipse       (X0 - 10*zoomX, Y0 - 30*zoomY, X0 + 10*zoomX, Y0 + 30*zoomY);
        txCircle        (X0 -  1      , Y0 - 35*zoomY,       5*zoomX               );
        txMyTriangle    (X0 -  5*zoomX, Y0 - 40*zoomY-5*zoomY/2, X0 +  5*zoomX/2, Y0 - 40*zoomY-5*zoomY/2,  X0 + 5        , Y0 - 50*zoomY-5*zoomY, color_wing);//Клюв
        txMyTriangle    (X0 - 60*zoomX, Y0 - 25*zoomY, X0 - 10*zoomX, Y0 - 25*zoomY,  X0 - 10*zoomX, Y0 + 15*zoomY, color_wing);//Левое крыло
        txMyTriangle    (X0 + 40*zoomX, Y0 -  5*zoomY, X0 + 10*zoomX, Y0 - 25*zoomY,  X0 + 10*zoomX, Y0 + 15*zoomY, color_wing);//Правое крыло
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 -  5*zoomX, Y0 + 60*zoomY,  X0 +  5*zoomX, Y0 + 60*zoomY, color_wing);//Левая секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 + 10*zoomX, Y0 + 60*zoomY,  X0 + 15*zoomX, Y0 + 50*zoomY, color_wing);//Средняя секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 + 20*zoomX, Y0 + 50*zoomY,  X0 + 25*zoomX, Y0 + 40*zoomY, color_wing);//Правая секция хвоста
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void LeftturnBIRD(double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing)
    {
        txSetFillColor (color_body);
        txEllipse       (X0 - 10*zoomX, Y0 - 30*zoomY, X0 + 10*zoomX, Y0 + 30*zoomY);
        txCircle        (X0 -  1      , Y0 - 35*zoomY,       5*zoomX               );
        txMyTriangle    (X0 -  5*zoomX, Y0 - 40*zoomY-5*zoomY/2, X0 +  5*zoomX/2, Y0 - 40*zoomY-5*zoomY/2,  X0 -5          , Y0 - 50*zoomY-5*zoomY, color_wing);//Клюв
        txMyTriangle    (X0 - 40*zoomX, Y0 -  5*zoomY, X0 - 10*zoomX, Y0 - 25*zoomY,  X0 - 10*zoomX, Y0 + 15*zoomY, color_wing);//Левое крыло
        txMyTriangle    (X0 + 60*zoomX, Y0 - 25*zoomY, X0 + 10*zoomX, Y0 - 25*zoomY,  X0 + 10*zoomX, Y0 + 15*zoomY, color_wing);//Правое крыло
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 - 15*zoomX, Y0 + 50*zoomY,  X0 - 10*zoomX, Y0 + 60*zoomY, color_wing);//Левая секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 -  5*zoomX, Y0 + 60*zoomY,  X0 +  5*zoomX, Y0 + 60*zoomY, color_wing);//Средняя секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 - 20*zoomX, Y0 + 50*zoomY,  X0 - 25*zoomX, Y0 + 40*zoomY, color_wing);//Правая секция хвоста
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void BIRDWingsUP  (double X0, double Y0, double zoomX, double zoomY, COLORREF color_body, COLORREF color_wing)
    {
        txSetFillColor (color_body);
        txEllipse       (X0 - 10*zoomX, Y0 - 30*zoomY, X0 + 10*zoomX, Y0 + 30*zoomY);
        txCircle        (X0 -  1      , Y0 - 35*zoomY,       5*zoomX               );
        txMyTriangle    (X0 -  5*zoomX, Y0 - 40*zoomY-5*zoomY/2, X0 +  5*zoomX/2, Y0 - 40*zoomY-5*zoomY/2,  X0           , Y0 - 50*zoomY-5*zoomY, color_wing);//Клюв
        txMyTriangle    (X0 - 60*zoomX, Y0 - 25*zoomY, X0 - 10*zoomX, Y0 - 25*zoomY,  X0 - 10*zoomX, Y0 + 15*zoomY, color_wing);//Левое крыло
        txMyTriangle    (X0 + 60*zoomX, Y0 - 25*zoomY, X0 + 10*zoomX, Y0 - 25*zoomY,  X0 + 10*zoomX, Y0 + 15*zoomY, color_wing);//Правое крыло
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 - 15*zoomX, Y0 + 50*zoomY,  X0 - 10*zoomX, Y0 + 60*zoomY, color_wing);//Левая секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 -  5*zoomX, Y0 + 60*zoomY,  X0 +  5*zoomX, Y0 + 60*zoomY, color_wing);//Средняя секция хвоста
        txMyTriangle    (X0           , Y0 + 30*zoomY, X0 + 10*zoomX, Y0 + 60*zoomY,  X0 + 15*zoomX, Y0 + 50*zoomY, color_wing);//Правая секция хвоста
    }
//}----------------------------------------------------------------------------


