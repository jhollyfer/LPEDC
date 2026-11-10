## 0059 · Struct

Você pede açaí pelo app: copo M, 2 unidades, R$ 18,50 cada. Para o sistema, o
pedido é um pacote de três informações de tipos diferentes (um caractere, um
inteiro e um preço) que andam sempre juntas.

Com variáveis soltas (`char tamanho`, `int quantidade`, `double preco`), dez
pedidos seriam trinta variáveis, e nada diz que `tamanho3` e `preco3` são do
mesmo pedido. O C resolve isso com a **struct**.

Uma struct **agrupa variáveis de tipos diferentes sob um nome só**. Cada
variável de dentro é um **campo** (ou membro). Nos livros e na prova também se
chama **registro** (ou estrutura). `int`, `char` e `double` são **dados
simples**: guardam um valor só. Vetor e struct são **dados compostos**: o
vetor junta valores do mesmo tipo (homogêneo); a struct, de tipos diferentes
(heterogêneo). Primeiro você descreve o molde:

```c
struct pedido {
    char tamanho;
    int quantidade;
    double preco;
};   // <- esse ; é obrigatório
```

Isso cria um **tipo novo**, `struct pedido` (as duas palavras). O molde não
ocupa memória: é a planta da casa. A memória aparece ao declarar uma
variável: `struct pedido p1;`.

Para inicializar, use chaves com os valores **na ordem dos campos**:
`{'M', 2, 18.50}`. Ou, mais seguro, com o nome de cada campo (C99):
`{.tamanho = 'M', .quantidade = 2, .preco = 18.50}`. Campo não citado começa
com zero. O **literal composto** cria uma struct "na hora", sem variável:
`(struct pedido){'G', 1, 22.00}`, útil para passar direto a uma função.

O **ponto** lê ou muda um campo: `p1.quantidade`, `p1.preco = 20.0`. Cada
campo é uma variável comum do seu tipo: `p1.tamanho` é `char`,
`&p1.quantidade` é `int *`.

A variável `p1` é um bloco de memória com os três campos em sequência. O
programa multiplica dois deles, chega a R$ 37,00 e decide o frete. O buraco
cinza entre `tamanho` e `quantidade` é explicado na dica abaixo:

{{ideia}}

O mesmo pedido em C:

```c
#include <stdio.h>

// o molde: diz quais campos um pedido tem (ainda não reserva memória)
struct pedido {
    char tamanho;   // 'P', 'M' ou 'G'
    int quantidade; // quantos copos
    double preco;   // preço de cada copo
};

int main(void) {
    struct pedido p1 = {'M', 2, 18.50}; // os valores vão na ordem dos campos

    double total = p1.quantidade * p1.preco; // o ponto acessa um campo
    printf("Pedido: %d copos %c de R$ %.2f\n", p1.quantidade, p1.tamanho, p1.preco);
    printf("Total: R$ %.2f\n", total);

    if (total >= 30.0) {
        printf("Frete grátis!\n");
    } else {
        printf("Frete: R$ 5.00\n");
    }
    printf("O pedido ocupa %zu bytes\n", sizeof(struct pedido));
    return 0;
}
// Saída:
// Pedido: 2 copos M de R$ 18.50
// Total: R$ 37.00
// Frete grátis!
// O pedido ocupa 16 bytes
```

Uma struct pode ter vetores e outras structs dentro (`cliente.end.cidade`,
ponto encadeado). A atribuição `b = a` funciona entre structs do **mesmo
tipo** e copia todos os bytes, inclusive os vetores de dentro (vetor sozinho
não se copia com `=`).

A struct não muda os passos do programa; só leva os dados num pacote:

{{fluxograma}}

> [!WARNING]
> `struct pedido p2 = p1;` cria uma **cópia independente**: mudar
> `p2.quantidade` não mexe em `p1`. Também não funcionam `p1 == p2` (não
> compila; compare campo a campo) e `cliente.nome = "Ana";` (use
> `strcpy(cliente.nome, "Ana")`). E o `;` depois da `}` do molde é
> obrigatório: sem ele o erro aparece numa linha seguinte.

> [!TIP]
> Os campos seguem a ordem declarada, mas não colados. `char` (1) + `int` (4)
> + `double` (8) somam 13 bytes e o `sizeof` diz 16: o compilador alinha o
> `int` em múltiplo de 4 e o `double` em múltiplo de 8, pulando 3 bytes de
> **preenchimento** (*padding*) depois de `tamanho`. `offsetof(struct pedido,
> preco)`, de `<stddef.h>`, dá 8. Por causa desses bytes de lixo o C não
> compara structs com `==`.

> [!NOTE]
> **Pergunta para você:** se você trocar a ordem dos campos para `double
> preco; int quantidade; char tamanho;`, o `sizeof` muda? E com `char
> tamanho; double preco; int quantidade;`? Desenhe os bytes antes de rodar.

{{pratique}}
