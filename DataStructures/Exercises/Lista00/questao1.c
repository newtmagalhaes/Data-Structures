/*
 * Suponha que existam 02 vetores A e B do tipo inteiro
 * com 05 elementos inteiros cada. Elabore um algoritmo
 * que construa um vetor C a partir da junção de A e B.
 */
#include <stdio.h>

int main()
{
    int A[5] = {0, 1, 2, 3, 4},
        B[5] = {5, 6, 7, 8, 9},
        C[10];
    for (int i = 0; i < 10; i++)
    {
        if (i >= 5) {C[i] = B[i - 5];}
        else {C[i] = A[i];}
        printf("%d\n", C[i]);
    }
    return 0;
}