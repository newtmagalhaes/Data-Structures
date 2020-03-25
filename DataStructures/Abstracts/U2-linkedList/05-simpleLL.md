[Anterior](./04-linkedList.md)

---

# Listas de Encadeamento Simples (_Simple Linked List_)

> [Fonte](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)

É uma estrutura de dados genérica formada por uma sequência de elos que contém dois itens, os dados a serem armazenados e um ponteiro para o seguinte elo da sequência.

Alguns conceitos importantes para se entender listas de encadeamento simples:

- **Início** (_Head_): o início de uma lista de encadeamento contém um ponteiro para o primeiro item da lista;

- **Elo** (_Node_): cada elo pode armazenar um elemento, e um seguinte;

- **Elemento** (_Element_): é como é chamado o dado (_Data Item_) armazenado no elo;

- **seguinte** (_Next_): é um ponteiro para o seguinte elo da lista de encadeamento.

> Obs: o **seguinte do ultimo elo** da lista aponta para _nulo_, e caso a lista esteja vazia, o início apontará para _nulo_.

![Exemplo de Lista de Encadeamento Simples](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list.jpg "Exemplo de Lista de Encadeamento Simples")

> [Implementação em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">](../../ImplementationInC/01-simpleLL.c)

## Operações

### Inserir

Para inserir um novo nó, devem ser seguidos alguns passos:

1. Primeiramente, cria-se o novo nó e determina a posição em que será inserido (alguns passos podem não ser necessários dependendo da posição);

   ![Exemplo de inserção de nó passo 0](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_insertion_0.jpg "Exemplo de inserção de nó passo 0")

2. Segundamente, faremos com que o novo nó aponte para o nó seguinte (caso não haja, aponta-se para _nulo_);

   ![Exemplo de inserção de nó passo 1](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_insertion_1.jpg "Exemplo de inserção de nó passo 1")

3. Terceiramente, faremos com que o nó anterior ao novo nó aponte para o novo.

   ![Exemplo de inserção de nó passo 2](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_insertion_2.jpg "Exemplo de inserção de nó passo 2")

   Feito isso, o resultado final é:

   ![Exemplo de inserção de nó passo 3](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_insertion_3.jpg "Exemplo de inserção de nó passo 3")

> Obs: é importante que o segundo passo ocorra antes do terceiro para que não haja a perda do nó seguinte (e consequentemente do restante da lista).

### Deletar

Para deletar um nó da lista, devem ser seguidos alguns passos:

1. Primeiramente, identificar qual nó será deletado;

   ![Exemplo de deleção de nó passo 0](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_deletion_0.jpg "Exemplo de deleção de nó passo 0")

2. Segundamente, (em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">, salva-se o endereço do nó alvo e) muda-se o nó anterior ao alvo para apontar para o nó seguinte ao alvo;

   ![Exemplo de deleção de nó passo 1](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_deletion_1.jpg "Exemplo de deleção de nó passo 1")

3. Terceiramente, apaga-se o endereço no seguinte do nó alvo (e em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15">, desaloca a memória reservada para aquele nó);

   ![Exemplo de deleção de nó passo 2](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_deletion_2.jpg "Exemplo de deleção de nó passo 2")

   Feito isso, o resultado final é:

   ![Exemplo de deleção de nó passo 3](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_deletion_3.jpg "Exemplo de deleção de nó passo 3")

### Buscar e Mostrar

Como inicialmente só temos acesso ao início da lista, a forma de percorrer a lista é linear, sempre acessando o nó seguinte, e o que a busca retornará dependerá do que será buscado, se é um endereço ou dado e se deve percorrer toda a lista ou parar ao encontrar uma quantidade _x_ de casos favoráveis.

Para mostrar, depende de onde a lista será exibida, se será a lista toda, apenas casos favoráveis a alguma condição, ou apenas algum intervalo, mas para isso será também preciso percorrer a lista linearmente.

### Reverter

Para reverter a lista, devem ser seguidos alguns passos:

1. Primeiramente, localizar o ultimo nó (e em , salvar seu endereço separadamente);

   ![Exemplo de reversão de lista passo 0](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_reverse_0.jpg "Exemplo de reversão de lista passo 0")

2. Segundamente, é feito que o ultimo nó aponte para o anterior e assim se repete até o primeiro (que apontará para _nulo_);

   ![Exemplo de reversão de lista passo 1](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_reverse_1.jpg "Exemplo de reversão de lista passo 1")

   ![Exemplo de reversão de lista passo 2](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_reverse_2.jpg "Exemplo de reversão de lista passo 2")

3. Terceiramente, faz-se com que o início da lista aponte para quem antes era o ultimo da lista;

   ![Exemplo de reversão de lista passo 3](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_reverse_3.jpg "Exemplo de reversão de lista passo 3")

   Feito isso, o resultado final é:

   ![Exemplo de reversão de lista passo 2](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list_reverse_4.jpg "Exemplo de reversão de lista passo 2")

---

[Próxima](./06-doubleLL.md)
