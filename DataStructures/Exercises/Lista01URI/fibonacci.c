/** 
 * URL - https://www.urionlinejudge.com.br/judge/pt/problems/view/1176
 * 
 * Enunciado -  Faça um programa que leia um valor e apresente o número de Fibonacci
 *              correspondente a este valor lido. Lembre que os 2 primeiros elementos
 *              da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2
 *              anteriores a ele. Todos os valores de Fibonacci calculados neste problema
 *              devem caber em um inteiro de 64 bits sem sinal.
 * 
 * Entrada -    A primeira linha da entrada contém um inteiro T, indicando
 *              o número de casos de teste. Cada caso de teste contém um único
 *              inteiro N (0 ≤ N ≤ 60), correspondente ao N-esimo termo da série de Fibonacci.
 * 
 * Saída -      Para cada caso de teste da entrada, imprima a mensagem
 *              "Fib(N) = X", onde X é o N-ésimo termo da série de Fibonacci.
*/
#include <stdio.h>

// Forma recursiva
unsigned long long int FibRec(int N)
{
    // Retorna o N-ésimo termo da sequência de fibonacci
    switch (N)
    {
    case 0:
        return N;
    case 1:
        return N;
    default:
        return FibRec(N - 1) + FibRec(N - 2);
    }
}

// Forma iterativa
unsigned long long int FibIte(int N)
{
    // Retorna o N-ésimo termo da sequência de fibonacci
    unsigned long long int primeiro = 0,
                           segundo = 1,
                           resultado = 0;
    int i = -1;
    do
    {
        resultado += primeiro;
        primeiro = segundo;
        segundo = resultado;
        i++;
    } while (i < N);
    return resultado;
}

// Versão de teste para VScode
int main()
{
    // Mostrará os 60 primeiros números da sequência de fibonacci
    int T = 60, N = 0;
    for (int i = 0; i < T; i++)
    {
        printf("Fib(%d) = %llu\n", N, FibIte(N));
        N++;
    }
    return 0;
}

// Versão submetida ao URI
unsigned long long int Fib(int N)
{
    unsigned long long int primeiro = 0,
                           segundo = 1,
                           resultado = 0;
    int i = -1;
    do
    {
        resultado += primeiro;
        primeiro = segundo;
        segundo = resultado;
        i++;
    } while (i < N);
    return resultado;
}

int mainURI()
{
    int T = 0, N = 0;
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d\n", &N);
        printf("Fib(%d) = %llu\n", N, Fib(N));
    }
    return 0;
}