/*
 * Ler duas matrizes A e B, de duas dimensões,
 * sendo a matriz A de 5X4 (5 linhas e 4 colunas) e a matriz B de 4X3 (quatro linhas e três colunas).
 * Apresentar a matriz C como resultado da multiplicação das matrizes A e B.
 * Condição para multiplicação: o número de colunas de A tem que ser igual ao número de linhas de B.
 */
#include <stdio.h>

int main()
{
    int A[5][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
        B[4][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
        C[5][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                C[i][j] = (A[i][k] * B[k][j]);
            }
            printf("C: %d; i: %d; j: %d;\n", C[i][j], i, j);
        }
    }
    return 0;
}