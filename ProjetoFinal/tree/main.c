#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./bitwise.h"
#include "./tree.h"

int main()
{
    char senha[_PASSWORD_LIMIT] = "123654879";
    char chave[_PASSWORD_LIMIT] = "654321";
    char *xorPass;
    char *treePass;

    // Inicia o cliente de Terminal para pedir a senha e a chave
    // atualizando seus respectivos valores.

    printf("Encriptação de senhas usando Árvore Binária!\n");
    printf("Favor escrever a chave para encriptação posterior:\n");
    printf("Chave:");
    scanf("%101s", chave);
    fflush(stdin);
    while (1)
    {   
        printf("\nEscreva a Senha:");
        scanf("%101s", senha);
        fflush(stdin);

        // Função que transfere o valor alterado para o [xorPass]
        xorPass = operation(senha, chave);

        /// Printa o Valor da operação XOR
        // printf("\nRetorno do Bitwise: %s\n", xorPass);

        // A operação da árvore
        treePass = treeOperation(xorPass);
        printf("Senha Criptografada:  %s\n", treePass);
    }

    return 0;
}