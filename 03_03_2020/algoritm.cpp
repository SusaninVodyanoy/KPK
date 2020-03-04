#include "TXLib.h"
int StrLen (const char str[]);
int RunTests();

#define MY_CODE_BLOOD_FROM_THE_EYES


int main()
    {



        #ifdef MY_CODE_BLOOD_FROM_THE_EYES
        RunTests();
        #endif

        return 0;
    }

int StrLen (const char str[])
    {
         int len=1;
         while (str[len] != '\0')  len++;
         return len-1;
    }

int RunTests()
    {
     int len = StrLen ("abc");
     if (len != 3)
        printf ("\h [FAILED] StrLen (abc). len = %d. but shold be 3\n", len) ;

    len = StrLen ("");
    if (len != 0)
        printf ("\h [FAILED] StrLen (abc). len = %d. but shold be 0\n", len);
    }
