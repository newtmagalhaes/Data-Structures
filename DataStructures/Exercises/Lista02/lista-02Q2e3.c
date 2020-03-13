// Lista 02 Questões 02 e 03

#include <stdio.h>

/** EXERCICIO: - 02:
 * Elabore um registro que contenha os seguintes campos: nome e nota.
 * O campo nota deverá ser um vetor com 03 notas para registrar as
 * notas AP1, AP2 e FINAL.
*/

struct Aluno
{
    double nota[3];
    char nome[20];
} typedef TAluno;

void MostreAlunos(TAluno *turma, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("AP1: %.2lf;\tAP2: %.2lf;\tFINAL: %.2lf;\tAluno: %s;\n", turma[i].nota[0], turma[i].nota[1], turma[i].nota[2], turma[i].nome);
    }
}

/** EXERCICIO: - 03:
 * Considerando o registro da questão anterior, elabore um programa para armazenar o nome e
 * nota de 5 alunos da disciplina Estruturas de Dados. O programa deverá mostrar os registros dos 5 alunos e notas.
*/

void AppAcademico()
{
    // SETUP
    TAluno turma[35] = {
        {7.22, 7.22, 7.22, "Ubireudo"},
        {8.22, 8.22, 8.22, "Notlina"},
        {9.22, 9.22, 9.22, "Newt"}};
    int numeroDeAlunos = 3;
    char option = '1';

    // APLICATION
    do
    {
        Printf("\n\tApp Academico\n");
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
            MostreAlunos(turma, numeroDeAlunos);
            break;
        case '2':
            if (numeroDeAlunos < 35)
            {
                fflush(stdin);
                scanf("\nDigite o nome: %s", &turma[numeroDeAlunos].nome);

                fflush(stdin);
                scanf("\nDigite a nota 1: %lf", &turma[numeroDeAlunos].nota[0]);

                fflush(stdin);
                scanf("\nDigite a nota 2: %lf", &turma[numeroDeAlunos].nota[1]);

                fflush(stdin);
                scanf("\nDigite a nota 3: %lf", &turma[numeroDeAlunos].nota[2]);

                numeroDeAlunos++;
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
    printf("\n\tQuestão 02 e 03\n");
    TAluno classe[3] = {
        {7.22, 7.22, 7.22, "Ubireudo"},
        {8.22, 8.22, 8.22, "Notlina"},
        {9.22, 9.22, 9.22, "Newt"},
    };
    MostreAlunos(classe, sizeof(classe) / sizeof(classe[0]));

    return 0;
}