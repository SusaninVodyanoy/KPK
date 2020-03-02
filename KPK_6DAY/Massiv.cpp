
#include "TXLib.h"

#include <stdlib.h>
#include <assert.h>

void FillArray (int data[],int Size);

int main()
    {
    CONST int Size = 20;
    int data[Size] = {};

    FillArray (data[],Size);
    $data;


    return 0;
    }
void FillArray (int data[],int Size)
    {
    For (int i = 1; i <= Size*2; i++)
        {
        $i;

        printf ("i = %d\n", n);
        assert (0<= i && i < size);

        data[i-1]=rand()*100+i;
        }
    }
