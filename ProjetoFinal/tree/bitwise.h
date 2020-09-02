#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _PASSWORD_LIMIT 101

/// Tamanho base para todas as operações incluidas da chave.
/// Tamanho da nova Senha.
int baseSize;

/// Faz a operação bitwise XOR.
/// @returns char* novaSenha
char *xorOperation(char char1[], char char2[], int tam)
{
    char *arr = (char *)malloc(_PASSWORD_LIMIT * sizeof(char));
    // Faz a conta XOR dos dois valores
    // e adiciona 33 para serem itens visíveis na tabela ASCII
    for (int i = 0; i < tam; i++)
    {
        arr[i] = (char)((char1[i] ^ char2[i]));
        if (arr[i] <= 32)
        {
            arr[i] += 33;
        }
        if (arr[i] >= 255) // 255 == vazio
        {
            arr[i] = (arr[i] % 255) + 33;
        }
    }
    return arr;
}

// Operação Bitwise:
// @param char[] Senha
// @param char[] Chave
// @returns char[] bitwiseChar
char *operation(char senha[], char chave[])
{
    int passSize = strlen(senha);

    int keySize = strlen(chave);

    // Nova chave para se adequar à senha.
    char newKey[passSize];
    // Nova senha encriptografada XOR
    char *newPass;

    // Essas iterações a seguir forçam a newKey ser do tamanho da senha
    if (keySize < passSize)
    {
        // Adiciona a chave à nova chave
        strcpy(newKey, chave);

        int diff = passSize - keySize;
        int rounds = diff / keySize;
        int rest = diff % keySize;

        for (int i = 0; i < rounds; i++)
        {
            strcat(newKey, chave);
        }

        int tempKeySize = keySize + (keySize * rounds);
        for (int i = 0; i < rest; i++)
        {
            newKey[tempKeySize] = chave[i];
            tempKeySize++;
        }
    }
    else if (keySize > passSize)
    {
        for (int i = 0; i < passSize; i++)
        {
            newKey[i] = chave[i];
        }
    }
    else if (keySize == passSize)
    {
        strcpy(newKey, chave);
    }

    /// Nova senha com o valor da operação
    newPass = xorOperation(newKey, senha, strlen(senha));

    // Adiciona o valor da nova senha à size, para se ter o tamanho em opções futuras.
    baseSize = strlen(newPass);

    return newPass;
}