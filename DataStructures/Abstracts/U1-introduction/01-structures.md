[Anterior](./00-introduction.md)

----------

# Estruturas (_struct_) em C

> [Fonte](https://www.tutorialspoint.com/cprogramming/c_structures.htm)

## Definição de _struct_

_Structs_ em <img alt="C" src="https://raw.github.com/newtmagalhaes/Aprendendo-Linguagens/master/images/logos/c.svg?sanitize=true" width="15"> são um tipo definido pelo usuário, como um registro capaz de aninhar dados heterogêneos que possuem alguma relação.

```C
// Exemplo de declaração de struct
struct Pessoa
{
    double carteira;
    unsigned int idade;
    char[30] nome;
};
```

Cada variável desse novo tipo `struct Pessoa` possuirá três variáveis associadas, `carteira`, `idade` e `nome` (normalmente chamados de atributos), que poderão ser acessadas individualmente através do operador ponto, de acordo com o exemplo abaixo:

```C
// Declarando variável
struct Pessoa cara;

// Acessando e atribuindo dado
cara.nome = "Carinha que mora logo ali";
cara.idade = 15;
cara.carteira = 1;
```

> **Obs**: devido às configurações de _padding_ para organizar a alocação de memória, o tamanho de uma _struct_ varia em multiplos do maior tipo que há dentro dela e conforme os atributos da _struct_ foram declarados.

----------

[Próximo](./02-arrays.md)
