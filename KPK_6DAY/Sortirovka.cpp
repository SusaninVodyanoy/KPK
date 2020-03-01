#include "TXLib.h"

struct Button
{
int posx, posy;
int sizex, sizey;
COLORREF corolBody;
COLORREF corolFrame;
bool CLick;
void Draw    () const;
void OnCLick (int numb);
};

void SelectWay ();

int main()
    {

    Button Buttons [7] = {{ 10,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {120,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {230,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {340,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {450,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {560,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false},
                          {670,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false}};


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
        printf ("���� �������� �� ������ %d\n", numb);
        if (txMouseButtons() & 1)
            {
            CLick=true;
            printf ("������ ������ %d\n", numb);
            }
        }
    }

