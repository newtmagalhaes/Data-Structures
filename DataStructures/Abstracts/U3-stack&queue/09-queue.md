[Anterior](./08-stack.md "Pilha")

---

# Fila (_Queue_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm "Site tutorialspoint")

Uma fila é uma estrutura de dados genérica que possui esse nome devido ao seu comportamento semelhante a uma fila real (de pessoas, por exemplo), em que, de maneira mais abstrata, só é possível acessar elementos que estão "no início ou no final da fila".

## Representação

Este comportamento representa uma estrutura de dados _FIFO_, abreviação para _First-In-First-Out_, ou seja, o **ultimo elemento adicionado** à fila é o **ultimo elemento retirado**.

![Representação de FIFO](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_diagram.jpg "Representação teórica de fila")

Uma fila pode ser implementada através de vetores, estruturas, ponteiros ou listas de encadeamento, podendo ter tamanho fixo ou não, por isso, a forma como cada elemento se relaciona com a fila depende muito da forma de implementar.

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/05-queue.c "Implementação em C")

## Operações Básicas

Uma fila deve suportar as seguintes operações:

- **Enfileirar** (_Enqueue_): adicionar um elemento no final da fila;

  ![Enqueue](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_enqueue_diagram.jpg "Representação de operação Enqueue")

- **Desenfileirar** (_Dequeue_): remover o elemento que está no início da fila;

  ![Enqueue](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_dequeue_diagram.jpg "Representação de operação Enqueue")

- **Observar** (_Peek_): observar qual elemento está no início da fila sem removê-lo;

- **estaCheia** (_isFull_): checa se a fila está cheia;

- **estaVazia** (_isEmpty_): checa se a fila está vazia.

---

[Próximo](../U4-tree/10-tree.md)
