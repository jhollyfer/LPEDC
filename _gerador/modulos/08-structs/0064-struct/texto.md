## 0064 · Struct

Você pede açaí pelo app: copo M, 2 unidades, R$ 18,50 cada. Para o sistema,
esse pedido não é um número só. É um pacote com três informações de tipos
diferentes: um caractere, um inteiro e um preço. E elas andam sempre juntas.

Até aqui, você teria três variáveis soltas: `char tamanho`, `int quantidade`,
`double preco`. Com dez pedidos, seriam trinta variáveis, e nada no código diz
que `tamanho3` e `preco3` são do mesmo pedido. O C resolve isso
com uma **struct**.

Uma struct **agrupa variáveis de tipos diferentes sob um nome só**. Cada
variável de dentro é um **campo** (ou membro). Você primeiro descreve o molde:

```c
struct pedido {
    char tamanho;
    int quantidade;
    double preco;
};   // <- esse ; é obrigatório
```

Isso cria um **tipo novo**, chamado `struct pedido` (as duas palavras). O molde
não ocupa memória nenhuma: é como a planta de uma casa. A memória aparece
quando você declara uma variável desse tipo: `struct pedido p1;`.

Para inicializar, use chaves com os valores **na ordem dos campos**:
`{'M', 2, 18.50}`. Ou, mais seguro, com o nome de cada campo (C99):
`{.tamanho = 'M', .quantidade = 2, .preco = 18.50}`. Campo que você não citar
começa com zero. E, para criar uma struct "na hora", sem variável, existe o
**literal composto**: `(struct pedido){'G', 1, 22.00}`, útil para passar
direto a uma função.

Para ler ou mudar um campo, use o **ponto**: `p1.quantidade`,
`p1.preco = 20.0`. Cada campo é uma variável comum, do seu tipo: `p1.tamanho`
é um `char`, `&p1.quantidade` é um `int *`, e assim por diante.

Vamos ver na prática. A variável `p1` é um bloco de memória com os três campos
em sequência. O programa multiplica dois deles, chega a R$ 37,00 e decide o
frete. Repare no buraco cinza entre `tamanho` e `quantidade`: ele é explicado
no "Por dentro do C" logo abaixo:

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

Uma struct pode ter vetores e até outras structs dentro (`cliente.end.cidade`,
com o ponto encadeado). E a atribuição `b = a` funciona entre structs do
**mesmo tipo**: ela copia todos os bytes, inclusive os vetores de dentro. Isso
é curioso, porque vetor sozinho não se copia com `=`. Dentro de uma struct,
copia.

Repara no fluxograma: a struct não muda o jeito de pensar o programa. Os
passos são os de sempre; a diferença é que os dados viajam num pacote só:

{{fluxograma}}

> [!WARNING]
> Atribuir uma struct não faz as duas variáveis **apontarem** para o mesmo
> lugar: `struct pedido p2 = p1;` cria uma **cópia independente**. Mudar
> `p2.quantidade` não mexe em `p1`. Duas outras coisas também não funcionam:
> `p1 == p2` nem compila (compare campo a campo), e um campo vetor não recebe
> texto com `=`: `cliente.nome = "Ana";` é erro; use `strcpy(cliente.nome, "Ana")`.
> E não esqueça o `;` depois da `}` do molde: o erro aparece numa linha
> seguinte e confunde.

> [!TIP]
> **Por dentro do C:** os campos ficam na ordem em que você declarou, mas não
> necessariamente colados. `char` (1) + `int` (4) + `double` (8) somam 13
> bytes, e o `sizeof` diz 16. O processador lê um `int` mais rápido quando o
> endereço é múltiplo de 4, e um `double` quando é múltiplo de 8. Então o
> compilador coloca `tamanho` no byte 0, pula 3 bytes de **preenchimento**
> (*padding*), põe `quantidade` no byte 4 e `preco` no byte 8. A macro
> `offsetof(struct pedido, preco)`, de `<stddef.h>`, confirma: 8. É também por
> causa desses bytes de lixo que o C não deixa comparar structs com `==`.

> [!NOTE]
> **Pergunta para você:** se você trocar a ordem dos campos para `double
> preco; int quantidade; char tamanho;`, o `sizeof` muda? E com `char
> tamanho; double preco; int quantidade;`? Desenhe os bytes antes de rodar.

{{pratique}}
