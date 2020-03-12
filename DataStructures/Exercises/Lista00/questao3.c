/*
 * Escreva um programa que leia um determinado número N
 * e informe os dois antecessores de N e os dois sucessores de N.
 */
#include <stdio.h>
void anteSuce(int N)
{
    printf("Antecessores: %d - %d;\n", N - 2,N - 1);
    printf("N: %d", N);
    printf("Sucessores: %d - %d;\n", N + 1, N + 2);
}
int main()
{
    anteSuce(20);
    return 0;
}