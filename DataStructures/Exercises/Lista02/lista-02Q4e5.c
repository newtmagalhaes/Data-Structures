// Lista 02 Questões 04 e 05

#include <stdio.h>

/** EXERCICIO: - 04:
 * Considerando a necessidade de desenvolver uma agenda que contenha
 * os campos: nome, endereço, telefone e um campo situação (L –Livre; X –Ocupadoe * -Apagado);
 * defina a estrutura de registro apropriado em C.
*/

enum Situacao
{
    livre = 'L',
    ocupado = 'X',
    apagado = '*'
} typedef TSituacao;

struct Contato
{
    char nome[35],
        endereco[35],
        telefone[10];
    TSituacao situacao;
} typedef TContato;

void MostreContato(TContato *contato)
{
    printf("situa%c%co: %c;\tnome: %s;\n", 135, 198, contato->situacao, contato->nome);
    printf("\tEndereco: %s; telefone: %s\n", contato->endereco, contato->telefone);
}

/** EXERCICIO: - 05:
 * Considerando o registro definido na questão anterior, crie uma agenda com 5pessoas.
 * O programa deverá usar um menu de opções (sub-rotinas), com as seguintes opções:
 *      Inserir os 5 registros.
 *      Pesquisar um dos 5 registros de cada vez pelo campo nome.
 *      Alterar campos de um registro.
 *      Sair do programa de cadastro.
*/

void AppAcademico()
{
    // SETUP
    TContato agenda[5] = {};
    int agendaPreenchida = 0;
    char option = '1';

    // APLICATION
    do
    {
        Printf("\n\tApp Agenda\n");
        printf("- op%c%co:\n", 135, 198);
        printf("  1 - Mostrar lista de Alunos\n");
        printf("  2 - Inserir novo Aluno\n");
        printf("  ----------------------\n");
        printf("  0 - Sair do Aplicativo\n");
        printf("\n  Escolha uma op%c%co: ", 135, 198);
        fflush(stdin);
        option = getchar();

        if (option == '0')
        {
            printf("\n  ** Fim do aplicativo **");
            break;
        }

        switch (option)
        {
        case '1':
            MostreAlunos(agenda, agendaPreenchida);
            break;
        case '2':
            if (agendaPreenchida < 5)
            {
                fflush(stdin);
                scanf("\nDigite o nome: %s", &agenda[agendaPreenchida].nome);

                fflush(stdin);
                scanf("\nDigite a nota 1: %lf", &agenda[agendaPreenchida].nota[0]);

                fflush(stdin);
                scanf("\nDigite a nota 2: %lf", &agenda[agendaPreenchida].nota[1]);

                fflush(stdin);
                scanf("\nDigite a nota 3: %lf", &agenda[agendaPreenchida].nota[2]);

                agendaPreenchida++;
                printf("\nAluno incluido");
            }
            else
            {
                printf("\nLista de Alunos completa!!");
            }
            break;
        default:
            Printf("op%c%co invalida!\n", 135, 198);
            break;
        }
    } while (option != '0');
    printf("\nAplicativo encerrado");
}

int main(int argc, char const *argv[])
{

    return 0;
}