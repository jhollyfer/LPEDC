## 0053 · Pilha e heap

Sexta à noite, restaurante cheio. O garçom anota o pedido da mesa 4 num
bloquinho, arranca a folha e prende a comanda no balcão da cozinha. O
bloquinho volta limpo para o bolso; a comanda fica no balcão até alguém
pagar a conta e jogá-la fora. Um programa lida com a memória do mesmo jeito:
há rascunho que só dura enquanto uma função trabalha, e há dado que precisa
sobreviver a ela. Até aqui você só usou o primeiro tipo. Este módulo trata do
segundo.

Para entender a diferença, olhe o mapa. Quando o programa começa, o sistema
operacional lhe entrega uma faixa de endereços dividida em **regiões**, e
cada uma tem um dono e um tempo de vida próprios (CELES; RANGEL, 2002). A
região de **código** guarda as instruções e os literais de string, como
`"bom dia"` (assunto 0048), e é só de leitura. A região de **dados** guarda
as variáveis globais e as `static`. As outras duas, a pilha e o heap, são as
que interessam aqui.

A **pilha** (*stack*) você conhece do assunto 0031. A cada chamada de função,
ela empilha um **frame**, o espaço com as variáveis locais e os parâmetros
daquela chamada; no `return`, o frame é desempilhado. É o bloquinho do
garçom: automática, porque ninguém precisa pedir nem devolver, e rápida. Mas
tem dois limites. O frame some no `return`, então nada que mora nele
sobrevive à função. E a pilha é pequena: no Linux, 8 MiB por padrão; o
comando `ulimit -s` mostra `8192`, em KiB (CELES; RANGEL, 2002). Um vetor
local de 20 MB não cabe nela.

O **heap** é o balcão da cozinha. É um depósito do tamanho da memória livre
da máquina, e nele você pede, com o programa já rodando, um bloco de N
bytes. Em troca, recebe o **endereço** desse bloco, que você guarda num
ponteiro e usa como vetor. O bloco não pertence a função nenhuma: ele fica
vivo até você devolvê-lo com `free` (BACKES, 2013, cap. 11). Por isso dá para
criar um dado numa função e usá-lo em outra, depois que a primeira já
retornou. O assunto 0054 mostra como pedir e devolver.

Os livros dão nomes a esses três jeitos de conseguir memória. A alocação
**estática** acontece na região de dados, com tamanho e endereço fixos desde
a compilação. A **automática** acontece na pilha, a cada chamada. A
**dinâmica** acontece no heap, quando você pede (CELES; RANGEL, 2002). A
tabela resume o mapa:

| Região | O que guarda | Quem cria e quem apaga | Dura |
| --- | --- | --- | --- |
| **código** | as instruções e os literais (`"bom dia"`) | o compilador | o programa todo, só leitura |
| **dados** | globais e `static` | o compilador | o programa todo |
| **heap** | blocos pedidos com `malloc` | **você** pede e **você** devolve | até o `free` |
| **pilha** | locais e parâmetros (os frames) | a chamada e o `return` | enquanto a função roda |

A coluna do meio guarda a responsabilidade nova. O C não tem **coletor de
lixo** (*garbage collector*), o mecanismo que apaga sozinho o que ninguém
mais usa. Tudo o que você tira do heap, você devolve com `free`; o que fica
esquecido continua ocupado até o programa acabar (FEOFILOFF, 2009, ap. F).

> [!WARNING]
> Nunca devolva o endereço de uma variável local: `char senha[8]; ... return
> senha;` aponta para um frame que deixa de existir no `return`. O gcc avisa
> (`function returns address of local variable`) e devolve `NULL` no lugar.
> Saídas: quem chama empresta o vetor, a variável vira `static` ou o bloco
> vem do heap.

{{exemplo}}

A função `abrir_comanda` monta a comanda da mesa 4 com três itens (R$ 18, 25
e 7). A variável `itens` mora na pilha, os valores vão para um bloco no heap e
o contador `pedidos_do_dia` mora nos dados:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

int pedidos_do_dia = 0; // DADOS: existe do começo ao fim do programa

int *abrir_comanda(int mesa) {
    int itens = 3; // PILHA: some quando a função retorna
    int *comanda = malloc(itens * sizeof(int)); // o bloco fica no HEAP
    if (comanda == NULL) {
        return NULL;
    }
    comanda[0] = 18; // suco
    comanda[1] = 25; // prato feito
    comanda[2] = 7;  // pudim
    pedidos_do_dia++;
    printf("Mesa %d: comanda com %d itens\n", mesa, itens);
    return comanda; // o endereço volta; o bloco continua vivo no heap
}

int main(void) {
    int *comanda = abrir_comanda(4); // PILHA: o ponteiro mora no frame de main
    if (comanda == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    int total = comanda[0] + comanda[1] + comanda[2];
    printf("Total: R$ %d\n", total);
    printf("Pedidos do dia: %d\n", pedidos_do_dia);
    free(comanda); // devolve o bloco ao heap
    return 0;
}
// Saída:
// Mesa 4: comanda com 3 itens
// Total: R$ 50
// Pedidos do dia: 1
```

O frame de `abrir_comanda` nasce e morre no meio do caminho; o bloco do heap
atravessa o `return` e só termina no `free`:

{{fluxograma}}
