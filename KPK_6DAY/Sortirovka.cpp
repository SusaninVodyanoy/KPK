#include "TXLib.h"

struct Button
{
int         posx, posy;
int         sizex, sizey;
COLORREF    corolBody;
COLORREF    corolFrame;
bool        CLick;
double      (*func) (double x);
void        Draw    () const;
void        DrawGraphic ();
void        OnCLick (int numb);
};

//void DrawGraphic    (double (*func) (double x), COLORREF color,
//                    double k = 1, double l = 1,
//                    double a = 0, double b = 0);

double Sqr          (double x);
double sin2   (double x);
double Sqr3   (double x);
double clerscr(double x);
double myexit (double x);

void SelectWay      ();

int main()
    {

    Button Buttons [7] = {{ 10,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  sin},
                          {120,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  cos},
                          {230,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  Sqr},
                          {340,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  Sqr3},
                          {450,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  sin2},
                          {560,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  clerscr},
                          {670,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  myexit}};


    txCreateWindow (800, 600);
    txTextCursor (false);
    txBegin ();

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txTextOut   (100, 100, "�������� ������ ���������� �� 1 �� 5");
        for (int i = 0; i<7; i ++)
            {
            Buttons[i].Draw     ();
            Buttons[i].OnCLick  (i);
            }
        SelectWay ();

        txSleep (0);

        }


    return 0;
    }


void SelectWay ()
    {
    if (txGetAsyncKeyState (0x31))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "������ 1 ������ ����������");
        }

    if (txGetAsyncKeyState (0x32))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "������ 2 ������ ����������");
        }

    if (txGetAsyncKeyState (0x33))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "������ 3 ������ ����������");
        }

    if (txGetAsyncKeyState (0x34))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "������ 4 ������ ����������");
        }
    if (txGetAsyncKeyState (0x35))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "������ 5 ������ ����������");
        }
    if (txGetAsyncKeyState (VK_SPACE))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        }
    }

void Button::Draw () const
    {

    txSetFillColor  (corolBody);
    txSetColor      (corolFrame);
    txRectangle     (posx, posy, posx+sizex, posy+sizey);

    }

void Button::OnCLick (int numb)
    {
    if (txMouseX()>posx && txMouseX()<posx+sizex && txMouseY()>posy && txMouseY()<posy+sizey)
        {
        //printf ("���� �������� �� ������ %d\n", numb);
        if (txMouseButtons() & 1)
            {
            CLick=true;
            DrawGraphic ();
            //printf ("������ ������ %d\n", numb);
            }
        }
    }

//typedef double (*func) (double x);

void Button::DrawGraphic ()/*, COLORREF color,
                    double k, double l,
                    double a, double b) */
    {
    txSetColor      (TX_LIGHTRED);
    txSetFillColor  (TX_LIGHTRED);

    if (!(func==clerscr || func==myexit))
        {
        double k = 1, l = 1, a = 0, b = 0;

        double x = -10;
        while (x<= +10)
            {
            double y = k*func(l*x+a)+b;

            txCircle (400+50*x, 300 - 50*y, 2);

            x += 0.01 ;
            }
        }
    }
//void Button::CHeckOnCLick
 //   {
 //
 //           DrawGraphic(func,   TX_LIGHTGREEN   ,t   , 1        );
    //}
    //}

double Sqr    (double x) {return x*x;}
double Sqr3   (double x) {return x*x*x;}
double sin2   (double x) {return sin(x*2);}
double cos2   (double x) {return cos(2*x);}
double clerscr(double x) {txSetFillColor (TX_BLACK);
                          txClear     ();}
double myexit(double x) { };

