[Anterior](../U2-linkedList/07-circularLL.md "Lista de Encadeamento circular")

---

# Pilha (_Stack_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm "Site tutorialspoint")

Uma pilha é uma estrutura de dados genérica que possui esse nome devido ao seu comportamento semelhante a uma pilha real (de cartas ou pratos, por exemplo), em que, de maneira mais abstrata, só é possível acessar elementos que estão "no topo da pilha".

## Representação

Este comportamento representa uma estrutura de dados _LIFO_, abreviação para _Last-In-First-Out_, ou seja, o **ultimo elemento adicionado** à pilha é o **primeiro elemento retirado**.

![Representação de LIFO](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_representation.jpg "Representação teórica de pilha")

Uma pilha pode ser implementada através de vetores, estruturas, ponteiros ou listas de encadeamento, podendo ter tamanho fixo ou não, por isso, a forma como cada elemento se relaciona com a pilha depende muito da forma de implementar.

Além das operações, outro termo também está relacionado à pilha, o **Topo** (_Top_), o elemento no topo da pilha.

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/04-stack.c "Implementação em C")

## Operações Básicas

Uma pilha deve suportas as seguintes operações:

- **Inserir** (_Push_): inserir um elemento no topo da pilha;

  ![Push](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_push_operation.jpg "Representação de operação Push")

- **Retirar** (_Pop_): retirar um elemento do topo da pilha;

  ![Pop](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_pop_operation.jpg "Representação de operação Pop")

- **Observar** (_Peek_): observar qual elemento está no topo da pilha;

- **estaCheia** (_isFull_): checar se a pilha está cheia (caso tenha um tamanho limite);

  > Caso uma pilha esteja e caso seja tentado inserir um novo elemento, ocorrerá o chamado [_Stack OverFlow_](https://stackoverflow.com/ "Transbordo da Pilha")

- **estaVazia** (_isEmpty_): checar se a pilha está vazia.

  > Caso uma pilha esteja e caso seja tentado inserir um novo elemento, ocorrerá o chamado _Stack UnderFlow_

---

[Próximo](./09-queue.md "Fila")
