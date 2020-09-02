#pragma once

#define _TREE_NULL_CHAR ' '

/**
 *    Implementando estrutura de dados de Árvore
 *    onde cada nó armazena um caractere (char)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *leftNode, *rightNode;
    char data;
} Tree;

Tree *_createNode()
{
    Tree *newNode = NULL;
    do
    {
        newNode = (Tree *)malloc(sizeof(Tree));
    } while (newNode == NULL);

    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    newNode->data = '\0';

    return newNode;
}

// Dado um nodeArr retorna um ponteiro para um novo nodeArr com o dobro do tamanho da entrada
Tree **_getNextNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    Tree **nextNodeArr = (Tree **)realloc(NULL, 2 * nodeArrLength * sizeof(Tree));

    for (int i = 0; i < 2 * nodeArrLength; i++)
    {
        if (i % 2 == 0)
        {
            nextNodeArr[i] = nodeArr[i / 2] != NULL ? nodeArr[i / 2]->leftNode : NULL;
        }
        else
        {
            nextNodeArr[i] = nodeArr[i / 2] != NULL ? nodeArr[i / 2]->rightNode : NULL;
        }
    }

    return nextNodeArr;
}

// retorna uma nova str sem o caractere desejado
char *_filterStr(char str[], char reject)
{
    int j = 0;
    char *newStr = NULL;

    do
    {
        newStr = (char *)malloc(strlen(str));
    } while (newStr == NULL);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != reject)
        {
            newStr[j] = str[i];
            j++;
        }
    }
    newStr[j] = '\0';

    return (char *)realloc(newStr, strlen(newStr));
}

// Dado um nodeArr retorna uma string com os caracteres de cada nó
char *_getCharArrFromNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    unsigned charArrLength = (nodeArrLength + 1) * sizeof(char);
    char *charArr = NULL;

    do
    {
        charArr = (char *)malloc(charArrLength);
    } while (charArr == NULL);

    for (int i = 0; i < nodeArrLength; i++)
    {
        charArr[i] = nodeArr[i] != NULL ? nodeArr[i]->data : _TREE_NULL_CHAR;
    }
    charArr[nodeArrLength] = '\0';

    return charArr;
}

// Dado um nodeArr verifica se há pelo menos 1 nó diferente de NULL
int _isNodeArrNotNull(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        if (nodeArr[i] != NULL)
        {
            return 1;
        }
    }
    return 0;
}

// limpa as posições no nodeArr e desfaz a alocação
void _freeNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        nodeArr[i] = NULL;
    }
    free(nodeArr);
}

// Dado um nodeArr exibe os caracteres de cada nó no console
void _printNodeArr(Tree *nodeArr[], unsigned nodeArrLength)
{
    for (int i = 0; i < nodeArrLength; i++)
    {
        printf("\t%c", nodeArr[i] != NULL ? nodeArr[i]->data : _TREE_NULL_CHAR);
    }
    printf("\n");
}

// Desfaz a alocação de um nó e de seus filhos
void freeTree(Tree *node)
{
    if (node == NULL)
    {
        printf("no node to free!\n");
    }
    else
    {
        if (node->leftNode != NULL)
        {
            freeTree(node->leftNode);
            node->leftNode = NULL;
        }

        if (node->rightNode != NULL)
        {
            freeTree(node->rightNode);
            node->rightNode = NULL;
        }

        free(node);
    }
}

// Exibe os caracteres da árvore no console
void printTree(Tree *root)
{
    if (root == NULL)
    {
        printf("There's no Tree to print!");
    }
    else
    {
        unsigned currLength = 1;
        Tree **currNodeArr = (Tree **)realloc(NULL, currLength * sizeof(Tree *));
        currNodeArr[0] = root;

        Tree **nextNodeArr = _getNextNodeArr(currNodeArr, currLength);

        printf("Tree start!\n");
        do
        {
            _printNodeArr(currNodeArr, currLength);
            _freeNodeArr(currNodeArr, currLength);

            currLength *= 2;

            currNodeArr = nextNodeArr;
            nextNodeArr = _getNextNodeArr(currNodeArr, currLength);
        } while (_isNodeArrNotNull(currNodeArr, currLength));
        printf("Tree end!\n");
    }
}

// Faz a inserção binária na árvore
void binaryInsert(Tree *root, char insertData)
{
    if (root->data == '\0')
    {
        root->data = insertData;
    }
    else
    {
        if (insertData < root->data)
        {
            if (root->leftNode == NULL)
            {
                root->leftNode = _createNode();
            }
            binaryInsert(root->leftNode, insertData);
        }
        else
        {
            if (root->rightNode == NULL)
            {
                root->rightNode = _createNode();
            }
            binaryInsert(root->rightNode, insertData);
        }
    }
}

// retorna uma string com os caracteres da árvore
char *treeToStr(Tree *root, int filterNULLchar)
{
    if (root == NULL)
    {
        printf("There's no Tree to get str!");
        return NULL;
    }
    else
    {
        unsigned newStrLength = 1, currLength = 1;
        char *str = (char *)calloc(1, sizeof(char)),
             *currCharArr = (char *)calloc(1, sizeof(char));

        Tree **currNodeArr = (Tree **)realloc(NULL, currLength * sizeof(Tree));
        currNodeArr[0] = root;

        Tree **nextNodeArr = _getNextNodeArr(currNodeArr, currLength);

        do
        {
            currCharArr = _getCharArrFromNodeArr(currNodeArr, currLength);

            newStrLength += currLength;
            str = (char *)realloc(str, newStrLength);
            strcat(str, currCharArr);

            free(currCharArr);
            _freeNodeArr(currNodeArr, currLength);

            currLength *= 2;
            currNodeArr = nextNodeArr;
            nextNodeArr = _getNextNodeArr(currNodeArr, currLength);
        } while (_isNodeArrNotNull(currNodeArr, currLength));

        if (filterNULLchar)
        {
            char *filteredStr = _filterStr(str, _TREE_NULL_CHAR);
            free(str);
            return filteredStr;
        }
        else
        {
            return str;
        }
    }
}

// retorna uma árvore com a string inserida de forma binária
Tree *strToTree(char *str)
{
    Tree *root = _createNode();

    for (int i = 0; str[i] != '\0'; i++)
    {
        binaryInsert(root, str[i]);
    }

    return root;
}

// Arvore:
// @param char[] char
// @returns char[] encriptedChar
char *treeOperation(char *str)
{
    Tree *strNode = strToTree(str);
    char *strFromTree = treeToStr(strNode, 1);
    freeTree(strNode);
    return strFromTree;
}