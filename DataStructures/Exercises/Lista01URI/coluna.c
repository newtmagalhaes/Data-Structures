/**
 * URL - https://www.urionlinejudge.com.br/judge/pt/problems/view/1182
 * 
 * Enunciado -  Neste problema você deve ler um número que indica uma coluna de uma matriz na qual
 *              uma operação deve ser realizada, um caractere maiúsculo, indicando a operação que
 *              será realizada, e todos os elementos de uma matriz M[12][12]. Em seguida, calcule
 *              e mostre a soma ou a média dos elementos que estão na área verde da matriz, conforme
 *              for o caso. A imagem abaixo ilustra o caso da entrada do valor 5 para a coluna da matriz,
 *              demonstrando os elementos que deverão ser considerados na operação.
 * 
 * Entrada -    A primeira linha de entrada contem um número C (0 ≤ C ≤ 11) indicando a coluna
 *              que será considerada para operação. A segunda linha de entrada contém um único
 *              caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média) que
 *              deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto
 *              flutuante que compõem a matriz.
 * 
 * Saída -      Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
*/
#include <stdio.h>

// Versão de teste para VScode
int main()
{
    int C = 4;
    char T = 'M';
    double matriz[12][12], somaDaColuna = 0;

    // Preenche a matriz
    for (int i = 0; i < 144; i++)
    {
        matriz[0][i] = i;
    }

    printf("Matriz:\n");
    for (int linha = 0; linha < 12; linha++)
    {
        for (int coluna = 0; coluna < 12; coluna++)
        {
            printf("\t%.2lf", matriz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nColuna %d\n[ ", C);
    for (int j = 0; j < 12; j++)
    {
        printf("%.2lf ", matriz[j][C]);
        somaDaColuna += matriz[j][C];
    }
    printf("]\n");

    if (T == 'S')
    {
        printf("\nSoma da coluna: %.1lf\n", somaDaColuna);
    }
    else
    {
        printf("\nMedia da coluna: %.1lf\n", somaDaColuna / 12);
    }
    return 0;
}

// Versão submetida ao URI
int mainURI()
{
    int C;
    char T;
    double matriz[12][12], somaDaColuna = 0;

    scanf("%d\n", &C);
    scanf("%c", &T);

    for (int i = 0; i < 144; i++)
    {
        scanf("%lf\n", &matriz[0][i]);
    }

    for (int i = 0; i < 12; i++)
    {
        somaDaColuna += matriz[i][C];
    }

    if (T == 'S')
    {
        printf("%.1lf\n", somaDaColuna);
    }
    else
    {
        printf("%.1lf\n", somaDaColuna / 12);
    }
    return 0;
}