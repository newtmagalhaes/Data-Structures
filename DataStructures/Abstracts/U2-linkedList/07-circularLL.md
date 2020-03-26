[Anterior](06-doubleLL.md)

---

# Listas de Encadeamento Circular (_Circular Linked List_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/circular_linked_list_algorithm.htm)

É uma estrutura de dados genérica que se divide em dois tipos, a circular simples e a circular dupla.

## Circular Simples

Possui apenas uma diferença em relação à [lista de encadeamento simples](05-simpleLL.md), é que o **seguinte do ultimo elo** aponta para o **primeiro elo**.

![Lista de Encadeamento Circular Simples](https://www.tutorialspoint.com/data_structures_algorithms/images/singly_circular_linked_list.jpg "Exemplo Lista de Encadeamento Circular Simples")

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/03-doubleCLL.c)

## Circular Dupla

Possui apenas uma diferença em relação à [lista de encadeamento duplo](06-doubleLL.md), é que o **anterior do primeiro elo** aponta para o **ultimo elo** e **seguinte do ultimo elo** aponta para o **primeiro elo**.

![Lista de Encadeamento Duplo](https://www.tutorialspoint.com/data_structures_algorithms/images/doubly_circular_linked_list.jpg "Exemplo Lista de Encadeamento Duplo")

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/03-simpleCLL.c)

## Operações

E como nas outras listas, as listas de encadeamento circular devem suportar operações de:

- **Inserir** (_Insert_): a inserção pode ser em qualquer ponto da lista;

- **Deletar** (_delete_): a deleção pode ser em qualquer ponto da lista;

- **Buscar** (_Search_): a busca pode ser por dado ou pelo enésimo elo;

- **Mostrar** (_Display_): mostrar de alguma visível para o usuário (como no console);

---

[Próxima](../U3-stack&queue/08-stack.md)
