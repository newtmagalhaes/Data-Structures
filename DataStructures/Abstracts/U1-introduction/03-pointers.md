[Anterior](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/02-arrays.md)

---

# Ponteiros (_pointer_) em C

> [Fonte](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)

Em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15"> existe apenas a atribuição por copia de valor, ou seja, uma variável apenas recebe a cópia de um valor que foi atribuido a ela.

```C
// Exemplo 1
int a, b;
a = 42;
b = a;
```

No exemplo acima, tanto `a` quanto `b` possuem o valor `42` armazenado, porém, cada um possui sua cópia, então, se uma for alterada, a outra permanecerá `42`.

Com o desenvolvimento de algoritmos cada vez mais complexos, surge a necessidade de não apenas realizar uma tarefa em função da variável passada como parâmetro, como também conseguir alterar a mesma, o que seria impossível sem acessar a variável diretamente, e com isso, se tem a necessidade de ponteiros e referências para automatizar esse processo.

## Definição de _pointer_

Um ponteiro é uma variável que armazena o endereço de memória de outra variável.
Ponteiros são um tipo derivado, onde, para cada tipo `T`, existe um respectivo tipo de ponteiro `T *`.

## Operadores

Ao trabalhar com _pointers_, há três operadores que são usados:

- **Reference** (&): operador unário de referência, utilizado para retornar o endereço de uma variável;

- **Dereference** (*): operador unário de desreferência, utilizado para acessar o dado contido no endereço de memória de uma variável;

- **Arrow** (->): usado como forma de simplificar sintaxe ao lidar com ponteiros de _structs_.

```C
// Exemplo 2
int variable;
int *pointer;

variable = 42;
pointer = &variable; // pointer armazena o endereço de variable

// Alterando o valor de variable através de pointer
*pointer = 24;

// *pointer também retorna o valor contido variable
```

> **Obs**: atenção ao operador *, sua função muda conforme o contexto

Ponteiros também são utilizados junto da biblioteca ``stdlib.h`` com funções de alocação dinâmica de memória, úteis na implementação de Tipos de Dados Abstratos que serão vistos a seguir.

---

[Próxima](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U2-linkedList/04-linkedList.md)
