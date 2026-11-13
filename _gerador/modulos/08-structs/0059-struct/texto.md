## 0059 · Struct

- **Struct**: agrupa variáveis de tipos diferentes sob um nome só. Cada
  variável de dentro é um **campo** (ou membro); livros e provas também dizem
  **registro** (BACKES, 2013, cap. 8).
- **Simples e compostos**: `int`, `char` e `double` guardam um valor só. O
  vetor junta valores do mesmo tipo (homogêneo); a struct, de tipos diferentes
  (heterogêneo) (CELES; CERQUEIRA; RANGEL, 2016).
- **Molde**: a declaração cria o tipo `struct pedido` (as duas palavras) e não
  reserva memória. A memória aparece ao declarar uma variável:
  `struct pedido p1;` (DEITEL; DEITEL, 2011, cap. 10).

```c
struct pedido {
    char tamanho;
    int quantidade;
    double preco;
};   // <- esse ; é obrigatório
```

- **Inicialização**: chaves com os valores na ordem dos campos,
  `{'M', 2, 18.50}`, ou com o nome de cada um (C99),
  `{.tamanho = 'M', .quantidade = 2, .preco = 18.50}`. Campo não citado começa
  com zero (BACKES, 2013, cap. 8).
- **Literal composto**: `(struct pedido){'G', 1, 22.00}` cria uma struct na
  hora, sem variável, útil para passar a uma função (BACKES, 2013).
- **Ponto**: `p1.quantidade` lê ou muda um campo. Cada campo é uma variável
  comum do seu tipo: `&p1.quantidade` é `int *` (FEOFILOFF, 2009, ap. E).
- **Atribuição**: `b = a` copia todos os bytes entre structs do **mesmo tipo**,
  inclusive vetores de dentro. Struct pode ter outras structs dentro
  (`cliente.end.cidade`) (BACKES, 2013, cap. 8).
- **Preenchimento** (*padding*): o compilador alinha os campos. `char` + `int`
  + `double` somam 13 bytes e o `sizeof` dá 16. Por esses bytes de lixo o C não
  compara structs com `==` (DEITEL; DEITEL, 2011, cap. 10).

> [!WARNING]
> `struct pedido p2 = p1;` cria uma **cópia independente**. Não funcionam
> `p1 == p2` (compare campo a campo) nem `cliente.nome = "Ana";` (use `strcpy`).
> E o `;` depois da `}` do molde é obrigatório.

{{exemplo}}

O pedido de açaí: copo M, 2 unidades, R$ 18,50 cada. O programa multiplica dois
campos, chega a R$ 37,00 e decide o frete. O buraco cinza entre `tamanho` e
`quantidade` é o preenchimento:

{{ideia}}

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

A struct não muda os passos do programa; só leva os dados num pacote:

{{fluxograma}}
