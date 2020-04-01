[Anterior](./01-structures.md "Estruturas")

---

# Vetores e Matrizes (_Arrays_) em C

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/array_data_structure.htm "Site tutorialspoint")

## Definição de _array_

Em estrutura de dados, _array_ é uma estrutura capaz de armazenar uma quantidade fixa de itens do mesmo tipo (homogêneos). A maioria das estruturas de dados utilizam _arrays_ para implementação de seus algoritmos. Para compreender _arrays_, também é preciso compreender outros dois conceitos relacionados:

- **Element** (Elemento): cada item armazenado em um _array_ é chamado de elemento;

- **Index** (índice): a localização de cada elemento em um _array_ está associado a um índice numérico.

## _Array_ em C

_Array_ em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15"> é um tipo derivado, ou seja, é criado a partir de outros tipos já existentes, como uma estrutura capaz de conter vários dados do tipo que é derivado.

```C
// Declarando array de int
int vetor[10]; // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```

O _array_ possui 10 posições, e comumente, seus elementos são armazenados a partir da posição 0, ou seja, para o vetor de 10 posições, seus elementos estão localizados nos índices 0 até 9.

> **Obs**: acessar posições de fora do intervalo do vetor pode levar a problemas e comportamentos inesperados, portanto, é bom evitar.

## Matrizes em C

Para se entender uma matriz em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">, pode-se entender que uma matriz é um vetor, onde cada elemento é um vetor.

```C
// Matriz de int
int matriz[5][5];
/*
{
    {00, 01, 02, 03, 04},
    {05, 06, 07, 08, 09},
    {10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19},
    {20, 21, 22, 23, 24}
}
ou
{00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}
*/
```

## Acessando _arrays_ multidimensionais em C

Na prática, todos os _arrays_ em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15"> são lineares, ou seja, seus elementos estão em posições consecutivas de memória.

```C
// arr possui K * J * I posições
int arr[K][J][I];
```

Pelo exemplo acima, o elemento `arr[Z][Y][X]` está na posição `(K * Z) + (J * Y) + (I * X) = R` em relação ao início de `arr`, então, uma posição equivalente é `arr[0][0][R]`

> [Explicação no Stack Oveflow](https://stackoverflow.com/questions/20023568/accessing-multidimensional-array-in-c "Site Stack Overflow")

---

[Próximo](./03-pointers.md "Ponteiros")
