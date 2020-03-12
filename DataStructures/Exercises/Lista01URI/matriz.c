/**
 * URL - https://www.urionlinejudge.com.br/judge/pt/problems/view/1435
 * 
 * Enunciado -  Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100),
 *              correspondente a ordem de uma matriz M de inteiros, e construa
 *              a matriz de acordo com o exemplo abaixo.
 * 
 * Entrada -    A entrada consiste de vários inteiros, um valor por linha,
 *              correspondentes as ordens das matrizes a serem construídas.
 *              O final da entrada é marcado por um valor de ordem igual a zero (0).
 * 
 * Saída -      Para cada inteiro da entrada imprima a matriz correspondente,
 *              de acordo com o exemplo. Os valores das matrizes devem ser
 *              formatados em um campo de tamanho 3 justificados à direita e
 *              separados por espaço. Após o último caractere de cada linha da
 *              matriz não deve haver espaços em branco. Após a impressão de cada
 *              matriz deve ser deixada uma linha em branco.
*/
#include <stdio.h>

// Gera uma matriz quadrada no console
void Squariz(int N)
{
    // Declara a matriz
    int mat[N][N], p = 1, c = 0, f = N, i, j, k;

    // Preenche a matriz
    for (k = 0; k < N; k++)
    {
        for (i = c; i < f; i++)
        {
            for (j = c; j < f; j++)
            {
                mat[i][j] = p;
            }
        }
        p++;
        c++;
        f--;
    }

    // Exibe a matriz
    for (i = 0; i < N; i++) // Linhas
    {
        for (j = 0; j < N; j++) // Colunas
        {
            printf("%3d", mat[i][j]);
            if (j < (N - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Versão de teste para VScode
int main()
{
    Squariz(11);
    return 0;
}

// Versão submetida ao URI
int mainURI()
{
    int a, i, j;
    while (scanf("%d", &a), a != 0)
    {
        int mat[a][a], p = 1, c = 0, k, f = a;

        for (k = 0; k < a; k++)
        {
            for (i = c; i < f; i++)
            {
                for (j = c; j < f; j++)
                {
                    mat[i][j] = p;
                }
            }
            p++;
            c++;
            f--;
        }
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < a; j++)
            {
                printf("%3d", mat[i][j]);
                if (j < (a - 1))
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}