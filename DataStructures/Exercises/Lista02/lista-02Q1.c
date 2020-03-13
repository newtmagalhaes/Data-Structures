// Lista 02 Questão 01
#include <stdio.h>
#include <stdlib.h>

/** EXERCICIO: - 01:
 * A seção de controle de produção de uma fábrica mantém um arquivo de registros
 * de produção por funcionários. Cada registro contém o nome do funcionário
 * (como uma cadeia de 35 caracteres), o sexo do funcionário (M- masculino ou F- feminino)
 * e o número de peças produzidas pelo funcionário
 * 
 * - Escrever um programa que calcule de escreva:
 *      - A quantidade de peças produzidas pelos funcionários do sexo masculino e feminino;
 *      - O nome do(a) funcionário(a) com a maior produção registrada (obs. não haverá empates).
*/

enum Sexo
{
    masculino = 'M',
    feminino = 'F'
} typedef TSexo;

struct Funcionario
{
    char nome[35];
    TSexo sexo;
    int pecasProduzidas;
} typedef TFuncionario;

void FuncionarioDoMes(TFuncionario *recursosHumanos, int tamanho)
{
    int i = 0,
        somaFemininah = 0,
        somaMasculinah = 0,
        funcionarioDoMes = 0;
    for (i = 0; i < tamanho; i++)
    {
        switch (recursosHumanos[i].sexo)
        {
        case masculino:
            somaMasculinah += recursosHumanos[i].pecasProduzidas;
            break;
        case feminino:
            somaFemininah += recursosHumanos[i].pecasProduzidas;
            break;
        }
        if (recursosHumanos[i].pecasProduzidas > recursosHumanos[funcionarioDoMes].pecasProduzidas)
        {
            funcionarioDoMes = i;
        }
    }
    printf("\n- Peças produzidas por funionários do sexo masculino: %d", somaMasculinah);
    printf("\n- Peças produzidas por funionários do sexo feminino: %d", somaFemininah);

    printf("\nO funcionário do mês é: %s", recursosHumanos[funcionarioDoMes].nome);
    printf("\nQue produziu %d peças\n", recursosHumanos[funcionarioDoMes].pecasProduzidas);
}

int main()
{
    printf("\n\tQuestão 01\n");
    TFuncionario listaDeFuncionarios[4] = {
        {"Jeremy Bearemy", masculino, 42},
        {"Michael Realman", masculino, 24},
        {"Fulana de tal", feminino, 64},
        {"Ubireuda da Silva", feminino, 21}};

    FuncionarioDoMes(listaDeFuncionarios, sizeof(listaDeFuncionarios) / sizeof(listaDeFuncionarios[0]));

    return 0;
}