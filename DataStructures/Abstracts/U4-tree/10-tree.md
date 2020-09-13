[Anterior](../U3-stack&queue/09-queue.md "árvore")

---

# Árvore (_Tree_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm 'Site tutorialspoint')

Uma árvore é uma estrutura de dados genérica que possui esse nome devido à sua representação gráfica, em que seus elementos ficam armazenados nos nós da árvore e a partir da raiz é possível acessar os demais que estão conectados através das arestas.

## Representação

Uma árvore binária é uma variação da estrutura de dados de árvore no qual cada nó apenas possui duas arestas para os _nós filhos_.

![Representação de Árvore](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg 'Representação teórica de árvore')

No exemplo de árvore binária, o valor é armazenado conforme é maior ou menor que o valor do nó pai.

![Exemplo de Árvore Binária](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_search_tree.jpg 'Exemplo de Árvore Binária')

> [Implementação em C](../../../ProjetoFinal/tree/tree.h 'Implementação em C')

## Termos importantes

- **Caminho** (_Path_): se refere à sequência de nós ao longo das arestas da árvore;
- **Raiz** (_Root_): se refere ao nó inicial da árvore, há apenas uma raiz por árvore e um caminho da raiz para qualquer nó;
- **nó Pai** (_Parent_): com exceção da raiz, todo nó é apontado por um nó pai;
- **nó Filho** (_Child_): os nós apontados por um nó são considerados seus nós filhos;
- **Folha** (_Leaf_): São nós que não possuem nós filhos;
- **Subárvore** (_Subtree_): se refere aos nós que descendem de um nó;
- **Visitando** (_Visiting_): se refere a checar o conteúdo armazenado no nó;
- **Atravessando** (_Traversing_): significa passar pelo nó em uma ordem específica (como ir do nó pai para o filho);
- **Nível** (_Level_): representa a geração de um nó. se a raiz se encontra no nível 0, então seus filhos estão no nível 1 e os filhos deles no nível 2 e assim por diante;
- **Chave** (_Key_): Representa o conteúdo armazenado no nó.

## Operações Básicas de árvore binária

Uma árvore deve suportar as seguintes operações:

- **Inserir** (_Insert_): adicionar um elemento na árvore;

- **Buscar** (_Search_): verifica se o elemento está na árvore;

- **Remover** (_Remove_): remove um nó da árvore.

---

[Próximo](./11-graph.md "Grafo")
