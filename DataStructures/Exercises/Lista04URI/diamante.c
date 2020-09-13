/**
 * URL - https://www.urionlinejudge.com.br/judge/pt/problems/view/1069
 *
 * Entrada -    Deve ser lido um valor inteiro N que representa a quantidade de casos de teste.
 *              Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."
 *
 * Saída -      Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
*/

#include <stdio.h>

int main()
{
  char casoDeTeste[1001] = {0};
  int N = 0, pilha = 0, diamantesFormados = 0;

  scanf("%d", &N);

  for (int caso = 0; caso < N; caso++)
  {
    scanf("%1000s", &casoDeTeste);
    for (int position = 0; (casoDeTeste[position] != '\0') && position < 1000; position++)
    {
      if (casoDeTeste[position] == '<')
      {
        // push
        pilha++;
      }
      else if ((casoDeTeste[position] == '>') && (pilha > 0))
      {
        // pop
        pilha--;
        diamantesFormados++;
      }
    }
    printf("%d\n", diamantesFormados);
    diamantesFormados = 0;
    pilha = 0;
  }

  return 0;
}
