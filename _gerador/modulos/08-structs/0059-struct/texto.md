## 0059 · Struct

Você pede açaí pelo app: copo M, 2 unidades, R$ 18,50 cada. Para o sistema,
esse pedido junta três informações de tipos diferentes (um caractere, um
inteiro e um preço) que andam sempre juntas. Com variáveis soltas, dez
pedidos virariam trinta variáveis (`tamanho3`, `quantidade3`, `preco3`...), e
nada no código diria que as três do final 3 pertencem ao mesmo pedido.

Pense na ficha de cadastro de um consultório: uma folha só, com espaço para
nome, idade e telefone. Quem pega a ficha leva tudo de uma vez. A **struct** é
essa ficha: ela **agrupa variáveis de tipos diferentes sob um nome só**, e
cada variável de dentro se chama **campo** (ou membro). Livros e provas
também chamam a struct de **registro** ou estrutura (BACKES, 2013, cap. 8).

Até aqui você usou dois tipos de dado. Os **simples**, como `int`, `char` e
`double`, guardam um valor só. Os **compostos** guardam vários: o vetor junta
valores do mesmo tipo, por isso se diz **homogêneo**; a struct junta valores
de tipos diferentes, e é **heterogênea** (CELES; CERQUEIRA; RANGEL, 2016).

O primeiro passo é descrever o molde, dizendo quais campos a ficha tem:

```c
struct pedido {
    char tamanho;
    int quantidade;
    double preco;
};   // <- esse ; é obrigatório
```

Essa declaração cria um **tipo novo**, chamado `struct pedido` (as duas
palavras juntas formam o nome). O molde não ocupa memória nenhuma: ele é a
planta da casa, não a casa. A memória só aparece quando você declara uma
variável desse tipo, como `struct pedido p1;`, e aí `p1` ganha espaço para os
três campos (DEITEL; DEITEL, 2011, cap. 10).

Para dar valores na declaração, use chaves com os valores **na ordem dos
campos**: `struct pedido p1 = {'M', 2, 18.50};`. Desde o C99 você também pode
nomear cada campo, `{.tamanho = 'M', .quantidade = 2, .preco = 18.50}`, o que
protege contra trocar a ordem sem perceber. Campo que você não citar começa
com zero (BACKES, 2013, cap. 8). Se precisar de uma struct só por um
instante, por exemplo para passar a uma função, o **literal composto** cria
uma sem variável: `(struct pedido){'G', 1, 22.00}` (BACKES, 2013).

Para ler ou mudar um campo, use o **ponto**: `p1.quantidade` vale 2, e
`p1.preco = 20.0;` troca o preço. Cada campo se comporta como uma variável
comum do seu tipo. `p1.tamanho` é um `char`, e `&p1.quantidade` é o endereço
de um `int`, do tipo `int *`, que você pode passar ao `scanf` (FEOFILOFF,
2009, ap. E).

A struct pode ter vetores e outras structs dentro. Se o cliente tem um campo
`end` que é uma struct de endereço, você chega à cidade com dois pontos:
`cliente.end.cidade`. E a atribuição `b = a` funciona entre structs do
**mesmo tipo**: ela copia todos os bytes de uma vez, inclusive os vetores que
estão dentro. Isso chama a atenção porque vetor sozinho não se copia com `=`;
dentro de uma struct, copia (BACKES, 2013, cap. 8).

Falta entender o tamanho. Os campos ficam na memória na ordem em que você os
declarou, mas não necessariamente colados. O processador lê mais rápido um
`int` que começa num endereço múltiplo de 4 e um `double` que começa num
múltiplo de 8, então o compilador **alinha** os campos e pula bytes quando
precisa. Esses bytes vazios se chamam **preenchimento** (*padding*). No
`struct pedido`, `char` (1) + `int` (4) + `double` (8) somam 13 bytes, mas o
`sizeof` dá 16: o compilador deixa 3 bytes livres depois de `tamanho`, e o
`preco` começa no byte 8 (DEITEL; DEITEL, 2011, cap. 10). A macro
`offsetof(struct pedido, preco)`, de `<stddef.h>`, confirma: devolve 8. A
ordem dos campos muda a conta. Com `char`, `double` e `int`, nessa ordem, o
`sizeof` sobe para 24.

Esse preenchimento explica uma proibição do C: você não pode comparar duas
structs com `==`. Os bytes de enchimento guardam lixo, e duas structs com os
mesmos campos poderiam diferir nesses bytes. Para saber se dois pedidos são
iguais, compare campo a campo (DEITEL; DEITEL, 2011, cap. 10).

> [!WARNING]
> `struct pedido p2 = p1;` cria uma **cópia independente**: mudar
> `p2.quantidade` não mexe em `p1`. Também não funcionam `p1 == p2` (não
> compila; compare campo a campo) nem `cliente.nome = "Ana";` (use
> `strcpy(cliente.nome, "Ana")`). E o `;` depois da `}` do molde é
> obrigatório: sem ele, o erro aparece numa linha seguinte.

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
