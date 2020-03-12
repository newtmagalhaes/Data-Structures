/*
 * Considere duas matrizes A e B com dimensões 5X3.
 * Elabore um algoritmo que construa uma matriz C
 * de dimensão 2X15, de modo que a primeira linha de C
 * seja preenchida com os elementos de A e a segunda
 * linha de C seja preenchida com os elementos de B.
 */
#include <stdio.h>

int main() {
    int A[5][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12, 13, 14}},
        B[5][3] = {{15, 16, 17}, {18, 19, 20}, {21, 22, 23}, {24, 25, 26}, {27, 28, 29}},
        C[2][15], j = 0, k = 0;

    for (int i = 0; i < 30; i++)
    {
        if (i < 15) {C[0][i] = A[j][k]; k++;}
        else {C[1][i % 15] = B[j][k]; k++;}

        if (k > 3){k = 0; j++;}
        if (j > 4) {j = 0;}
        printf("%d\n", C[i/15][i]);
    }
    return 0;
}