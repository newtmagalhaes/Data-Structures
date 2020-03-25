[Anterior](./05-simpleLL.md)

---

# Listas de Encadeamento Duplo (_Double Linked List_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm)

É uma estrutura de dados genérica formada por uma sequência de elos que contém três itens, os dados a serem armazenados e dois ponteiros, um para o seguinte elo da sequência e outro para o anterior.

Alguns conceitos importantes para se entender listas de encadeamento duplo:

- **Início** (_Head_): o início de uma lista de encadeamento contém um ponteiro para o primeiro item da lista;

- **Elo** (_Node_): cada elo pode armazenar um elemento, um seguinte e um anterior;

- **Elemento** (_Element_): é como é chamado o dado (_Data Item_) armazenado no elo;

- **seguinte** (_Next_): é um ponteiro para o elo seguinte da lista de encadeamento.

- **anterior** (_Prev_): é um ponteiro para o elo anterior da lista de encadeamento.

> Obs: o **anterior do primeiro elo** e o **seguinte do ultimo elo** da lista apontam para _nulo_, e caso a lista esteja vazia, o início apontará para _nulo_.

![Lista de Encadeamento Duplo](https://www.tutorialspoint.com/data_structures_algorithms/images/doubly_linked_list.jpg "Exemplo Lista de Encadeamento Duplo")

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/02-doubleLL.c)

## Operações

Uma lista de encadeamento duplo deve suportar as seguintes operações:

- **Inserir** (_Insert_): a inserção pode ser em qualquer ponto da lista;

- **Deletar** (_delete_): a deleção pode ser em qualquer ponto da lista;

- **Buscar** (_Search_): a busca pode ser por dado ou pelo enésimo elo;

- **Mostrar** (_Display_): mostrar de alguma visível para o usuário (como no console);

- **Reverter** (_Revert_): inverter a ordem da lista.

---

[Próxima](./07-circularLL.md)
