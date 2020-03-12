#include <stdio.h>

unsigned long long int Fatorial(unsigned short int integer)
{
    if (integer > 20)
    {
        printf("%d is an invalid integer!\n", integer);
        return 0;
    }
    else
    {
        unsigned long long int result = 1;
        for (int i = 2; i <= integer; i++)
        {
            result *= i;
        }
        printf("%d!\t= %llu;\n", integer, result);
        return result;
    }
}

int main()
{
    for (int i = 0; i <= 21; i++)
    {
        Fatorial(i);
    }
    return 0;
}
