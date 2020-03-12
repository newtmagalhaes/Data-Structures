/**
 * URL - https://www.urionlinejudge.com.br/judge/pt/problems/view/1180
 * 
 * Enunciado -  Faça um programa que leia um valor N. Este N será o
 *              tamanho de um vetor X[N]. A seguir, leia cada um dos
 *              valores de X, encontre o menor elemento deste vetor
 *              e a sua posição dentro do vetor, mostrando esta informação.
 * 
 * Entrada -    A primeira linha de entrada contem um único inteiro N (1 < N < 1000),
 *              indicando o número de elementos que deverão ser lidos em seguida para
 *              o vetor X[N] de inteiros. A segunda linha contém cada um dos N valores,
 *              separados por um espaço.
 * 
 * Saída -      A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço
 *              e do menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:”
 *              seguido de um espaço e da posição do vetor na qual se encontra o menor valor lido,
 *              lembrando que o vetor inicia na posição zero.
*/
#include <stdio.h>

// Versão de teste para VScode
int main()
{
    int N = 10,
        X[10] = {1, 2, 3, 4, -5, 6, 7, 8, 9, 10},
        menor,
        posicao;
    for (int i = 0; i < N; i++)
    {
        if (X[i] < menor)
        {
            /** 
             * por não ter sido pré-definido,
             * menor é um número aleatório muito grande
            */
            menor = X[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d", menor, posicao);
    return 0;
}

// Versão submetida ao URI
int mainURI()
{
    int N;
    scanf("%d\n", &N);
    int X[N], menor, posicao;
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &X[i]);
        if (X[i] < menor)
        {
            menor = X[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d", menor, posicao);
    return 0;
}