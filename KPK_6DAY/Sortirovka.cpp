#include "TXLib.h"


//{----------------------------------------------------------------------------
struct rezult
    {
    int         posx1, posy1;
    COLORREF    ColorPOINT;
    };
//}----------------------------------------------------------------------------


//{----------------------------------------------------------------------------
struct Button
    {
    int         posx, posy;
    int         sizex, sizey;
    COLORREF    corolBody;
    COLORREF    corolFrame;
    bool        CLick;
    rezult      (*func) (int* data,int sizeARR);

    void        Draw    () const;
    void        OnCLick (int numb);
    void        DrawSort ();
    };
//}----------------------------------------------------------------------------


//{----------------------------------------------------------------------------
rezult  BubbleSort   (int* data, int sizeARR);
rezult  InsertSort   (int* data, int sizeARR);
rezult  StupidSort   (int* data, int sizeARR);
rezult  GnomeSort    (int* data, int sizeARR);

rezult  clerscr      (int* data, int sizeARR);
rezult  myexit       (int* data, int sizeARR);
//}----------------------------------------------------------------------------


//{----------------------------------------------------------------------------
void  SelectWay      ();
int*  CreateArray    (int sizeARR);
//}----------------------------------------------------------------------------


int main()
    {

    Button Buttons [7] = {
                          { 10,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  InsertSort},
                          {120,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  BubbleSort},
                          {230,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  StupidSort},
                          {340,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  GnomeSort},
                          {450,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  BubbleSort},
                          {560,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  clerscr},
                          {670,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  myexit}};


    txCreateWindow (800, 600);
    txTextCursor   (false);
    txBegin        ();

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txTextOut   (100, 100, "�������� ������ ���������� �� 1 �� 5");

        for (int ix= 20; ix < 340; ix+=50)
            {
            txSetFillColor  (TX_WHITE);
            txSetColor  (TX_WHITE);
            txLine (ix, 550, ix, 130);
            txLine (ix+450, 550, ix+450, 130);
            for (int iy= 550; iy > 130; iy-=50)
                {
                txLine (20, iy, 340, iy);
                txLine (470, iy, 790, iy);
                }
            }

        for (int i = 0; i<7; i ++)
            {
            Buttons[i].Draw     ();
            Buttons[i].OnCLick  (i);
            if (Buttons[i].func == myexit && Buttons[i].CLick)
                {
                 return EXIT_SUCCESS;
                }
            }
        SelectWay ();

        txSleep (0);
        }

   // return 0;
    }


//{----------------------------------------------------------------------------
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
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void Button::Draw () const
    {

    txSetFillColor  (corolBody);
    txSetColor      (corolFrame);
    txRectangle     (posx, posy, posx+sizex, posy+sizey);

    if (func == BubbleSort)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "BubbleSort");
        }

   if (func == InsertSort)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "InsertSort");
        }

    if (func == StupidSort)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "StupidSort");
        }
if (func == GnomeSort)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "GnomeSort");
        }

    if (func == clerscr)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "cleerscrin");
        }

    if (func == myexit)
        {
        txSetColor      (TX_BLACK);
        txSetFillColor  (TX_BLACK);
        txTextOut       (posx, posy, "exit");
        }
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void Button::OnCLick (int numb)
    {
    if (txMouseX()>posx && txMouseX()<posx+sizex && txMouseY()>posy && txMouseY()<posy+sizey)
        {
        //printf ("���� �������� �� ������ %d\n", numb);
        if (txMouseButtons() & 1)
            {
            CLick=true;
            //printf ("������ ������ %d\n", numb);
            DrawSort ();

            }
        }
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
rezult  clerscr(int* data, int sizeARR)
    {
    txSetFillColor  (TX_BLACK);
    txClear         ();
    rezult POINT = {0,0,TX_BLACK};

    return POINT;
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
rezult  myexit (int* data, int sizeARR)
    {
    exit;
    close;
    rezult POINT = {0,0,TX_BLACK};
    return POINT;
    };
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
int* CreateArray    (int sizeARR)
    {
    int* data = new int [sizeARR];
    for (int vertstep = 0; vertstep < sizeARR; vertstep++)
            {
                assert (0<= vertstep && vertstep < sizeARR);
                data[vertstep] = rand();
            }
    return data;
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
void   Button::DrawSort     ()
    {
     int y = 0;
     ;
     for (int x = 1; x < 500; x++)
        {
        //printf ("DrawSort");
        int* data = CreateArray(x);
        rezult POINT = func (data, x);
        txSetColor      (POINT.ColorPOINT);
        txSetFillColor  (POINT.ColorPOINT);
        txCircle ( 20+x*0.9, 550-POINT.posx1*0.4, 2);
        txCircle (470+x*0.9, 550-POINT.posy1*0.4, 2);
        }
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
rezult BubbleSort  (int* data, int sizeARR)
    {

    int numbcompar = 0, numbexch = 0;
    //printf ("BubbleSort") ;
    for (int vertstep = 0; vertstep < sizeARR; vertstep++)
        {
        for (int horstep = 0; horstep < sizeARR-1; horstep++)
            {
             numbcompar++;
            if (data[horstep] > data[horstep + 1])
                {
                int pool = data[horstep];            // ������� �������������� ����������
                data[horstep]  = data[horstep + 1];  // ������ �������
                data[horstep + 1] = pool;            // �������� ���������
                numbexch++;
                }
            }
        }
    rezult POINT = {numbexch,numbcompar,TX_LIGHTRED};

    return POINT;
    }
//}----------------------------------------------------------------------------

//{----------------------------------------------------------------------------
rezult  InsertSort   (int* data, int sizeARR)
    {

    int numbcompar = 0, numbexch = 0;
    for (int vertstep = 1; vertstep < sizeARR; vertstep++)
        {
        int pool = data[vertstep];
        numbcompar++;
        if (data[vertstep-1] > data[vertstep])
            {
            int horstep2 = vertstep;
            for (horstep2 = vertstep; data[horstep2] > data[horstep2-1]; horstep2--)
                {

                data[horstep2]  = data[horstep2 - 1];

                }
            data[horstep2]  = pool;
            numbexch++;
            }
        }

    rezult POINT = {numbexch,numbcompar,TX_LIGHTGREEN};

    return POINT;
    }
//}----------------------------------------------------------------------------

//�������� ���������
//{----------------------------------------------------------------------------
rezult StupidSort (int* data, int sizeARR)
    {
	int i = 1, numbcompar = 0, numbexch = 0;
	while (i < sizeARR)
		{
		//printf ("����") ;
		numbcompar++;
		if (data[i - 1] > data[i])
            {
			int pool = data[i - 1];            // ������� �������������� ����������
            data[i-1]  = data[i];              // ������ �������
            data[i] = pool;                    // �������� ���������
            numbexch++;
			i = 1;
			}
		else
            {
                i ++;
            }
        }
	rezult POINT = {numbexch,numbcompar,TX_YELLOW};
    return POINT;
    }
//}----------------------------------------------------------------------------
rezult GnomeSort (int* data, int sizeARR)
    {
	int i = 1, numbcompar = 0, numbexch = 0;
	while (i < sizeARR)
		{
		//printf ("����") ;
		numbcompar++;
		if (data[i - 1] > data[i])
            {
			int pool = data[i - 1];            // ������� �������������� ����������
            data[i-1]  = data[i];              // ������ �������
            data[i] = pool;                    // �������� ���������
            numbexch++;
			i--;
			}
		else
            {
                i ++;
            }
        }
	rezult POINT = {numbexch,numbcompar,TX_PINK};
    return POINT;
    }
//}
