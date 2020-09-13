[Anterior](./10-tree.md "Árvore")

---

# Grafo (_Graph_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/graph_data_structure.htm "Site tutorialspoint")

Uma Grafo é uma estrutura de dados genérica que contém um conjunto de objetos, chamados **vértices**, que podem estar conectados com outros através de _links_, chamadas de **arestas**.

## Representação

Formalmente, é um par de conjuntos **(V, A)**, onde **V** é o conjunto de vértices e **A** é o conjunto de arestas que conectam esses vértices

![Representação de Grafo](https://www.tutorialspoint.com/data_structures_algorithms/images/graph_basics.jpg "Representação teórica de Grafo")

No exemplo de Grafo:

- **V = {a, b, c, d, e}**
- **A = {ab, ac, bd, cd, de}**

![Exemplo de Grafo Binária](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_search_tree.jpg "Exemplo de Grafo Binária")

> [Implementação em C](../../../ProjetoFinal/graph/graph.h "Implementação em C")

## Termos importantes

- **Vértice** (_Vertex_): se refere a cada nó do grafo;
- **Aresta** (_Edge_): se refere à ligação entre um nó e outro;
- **Adjacência** (_Adjacency_): dois nós são adjacentes se houver uma aresta que os conecta diretamente;
- **Caminho** (_Path_): representa a sequência de arestas que conecta dois vértices.

## Operações Básicas de Grafo binária

Uma Grafo deve suportar as seguintes operações:

- **Adicionar Vértice** (_Add Vertex_): adiciona um vértice no Grafo;

- **Adicionar Aresta** (_Add Edge_): adiciona uma aresta entre dois vértices no Grafo;

- **Mostrar Arestas** (_Display Edges_): Exibe uma matriz binária informando com quais vértices cada vértice possui uma aresta.

---
