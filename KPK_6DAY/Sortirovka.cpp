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
double InsertSort   (double x);
double clerscr(double x);
double myexit (double x);

void SelectWay      ();

void CreateArray    ();
double BubbleSort   (double x);


int main()
    {

    Button Buttons [7] = {{ 10,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  sin},
                          {120,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  cos},
                          {230,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  Sqr},
                          {340,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  InsertSort},
                          {450,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  BubbleSort},
                          {560,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  clerscr},
                          {670,10, 100, 50, TX_YELLOW, TX_LIGHTGREEN, false,  myexit}};


    txCreateWindow (800, 600);
    txTextCursor (false);
    txBegin ();

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txTextOut   (100, 100, "Выберите способ сортировки от 1 до 5");
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
        txTextOut   (300, 400, "Выбран 1 способ сортировки");
        }

    if (txGetAsyncKeyState (0x32))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "Выбран 2 способ сортировки");
        }

    if (txGetAsyncKeyState (0x33))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "Выбран 3 способ сортировки");
        }

    if (txGetAsyncKeyState (0x34))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "Выбран 4 способ сортировки");
        }
    if (txGetAsyncKeyState (0x35))
        {
        txSetFillColor (TX_BLACK);
        txClear     ();
        txTextOut   (300, 400, "Выбран 5 способ сортировки");
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
        //printf ("Мышь наведена на кнопку %d\n", numb);
        if (txMouseButtons() & 1)
            {
            CLick=true;
            DrawGraphic ();
            //printf ("Нажата кнопка %d\n", numb);
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

    if (!(func==clerscr || func==myexit || func==BubbleSort))
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
    if (func==BubbleSort)
        {
        double x = 0;
        BubbleSort(x);
        }
    if (func==clerscr)
        {
        double x = 0;
        clerscr (x);
        }
    if (func==myexit)
        {
        double x = 0;
        myexit (x);
        }
    }
//void Button::CHeckOnCLick
 //   {
 //
 //           DrawGraphic(func,   TX_LIGHTGREEN   ,t   , 1        );
    //}
    //}

double Sqr    (double x) {return x*x;}
double cos2   (double x) {return cos(2*x);}
double clerscr(double x) {txSetFillColor (TX_BLACK);
                          txClear     ();}
double myexit (double x) { };

/*void   CreateArray     (int (*data)[],int Size)
    {
    //CONST int Size = 1000;
    // объявили массив на 1000 ячеек
    for (int i = 0; i < Size; i++)
        {
            assert (0<= i && i < Size);
            (*data)[i] = rand; // "записываем" элементы в массив
        }
    }
*/

double   BubbleSort     (double x)
    {
    CONST int Size = 1000;
    int data[Size] = {};
    for (int vertstep = 0; vertstep < Size; vertstep++)
        {
            assert (0<= vertstep && vertstep < Size);
            data[vertstep] = random(Size*2); // "записываем" элементы в массив
        }
    for (int vertstep = 0; vertstep < Size; vertstep++)
        {
        for (int horstep = 0; horstep < Size-1; horstep++)
            {
            txSetColor      (TX_LIGHTGREEN);
            txSetFillColor  (TX_LIGHTGREEN);
            txCircle (100+0.5*vertstep, 500-0.3*horstep, 2);
            if (data[horstep] > data[horstep + 1])
                {
                int pool = data[horstep];            // создали дополнительную переменную
                data[horstep]  = data[horstep + 1];        // меняем местами
                data[horstep + 1] = pool;            // значения элементов
                txSetColor      (TX_LIGHTRED);
                txSetFillColor  (TX_LIGHTRED);
                txCircle (100+0.5*vertstep, 500-0.3*horstep, 2);

                }

            }
        txSleep(0);
        }

    }

double      InsertSort     (double x)
    {
    CONST int Size = 1000;
    int data[Size] = {};
    for (int vertstep = 0; vertstep < Size; vertstep++)
        {
            assert (0<= vertstep && vertstep < Size);
            data[vertstep] = random(Size*2); // "записываем" элементы в массив
        }
    for (int vertstep = 1; vertstep < Size; vertstep++)
        {
        txSetColor      (TX_LIGHTGREEN);
        txSetFillColor  (TX_LIGHTGREEN);
        txCircle (100+0.5*vertstep, 500-0.3*vertstep, 2);
        int pool = data[vertstep];
        if (data[vertstep-1] > data[vertstep])
            {
            int horstep2 = vertstep;
            for (horstep2 = vertstep; data[horstep2] > data[horstep2-1]; horstep2--)
                {

                data[horstep2]  = data[horstep2 - 1];

                }
            data[horstep2]  = pool;
            txSetColor      (TX_LIGHTRED);
            txSetFillColor  (TX_LIGHTRED);
            txCircle (100+0.5*horstep2, 500-0.3*horstep2, 2);
            }
            txSleep(0);
        }

    }

