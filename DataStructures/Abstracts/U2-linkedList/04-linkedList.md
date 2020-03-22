[Anterior](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/03-pointers.md)

---

# Listas de Encadeamento (_Linked List_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)

Uma lista de encadeadamento é uma estrutura de dados teoricamente genérica formada por uma sequência de elos que contém itens, sendo estes os dados a serem armazenados e um ponteiro para o seguinte elo da sequência.

Alguns conceitos importantes para se entender listas de encadeamento:

- **Elo** (_Node_): cada elo pode armazenar um elemento, e um seguinte;

- **Elemento** (_Element_): é como é chamado o dado (_Data Item_) armazenado no elo;

- **seguinte** (_Next_): é um ponteiro que aponta para o seguinte elo da lista de encadeamento (o ultimo elo aponta para _nulo_);

- **Início** (_Head_): o início de uma lista de encadeamento contém um ponteiro que aponta para o primeiro item da lista (caso a lista esteja vazia, ela aponta para o _nulo_).

## Representação

Uma lista de encadeamento pode ser vista como uma corrente de elos, onde cada elo aponta para o seguinte.

![Representação de Lista de Encadeamento Simples](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list.jpg)

## Tipos de Listas de Encadeamento

1. [Listas de Encadeamento Simples](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/06-simpleLL.md) - Só é possível navegar, a partir de qualquer elo da lista, para o elo seguinte;

2. [Listas de Encadeamento Duplo](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/07-doubleLL.md): é possivel navegar, a partir de qualquer elo da lista, para o elo seguinte ou anterior;

3. [Listas de Encadeamento Circular](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/08-circularLL.md): a variavel seguinte do ultimo elo aponta para o primeiro elo, e a variavel anterior do primeiro elo aponta para o ultimo.

---

[Próxima](https://github.com/newtmagalhaes/Data-Structures/blob/master/DataStructures/Abstracts/U1-introduction/05-operations.md)
