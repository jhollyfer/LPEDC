## 0045 · Ponteiros

Pelo app de comida, o entregador não leva a sua casa no celular: leva o
**endereço**. Com ele, chega à porta e entrega o pedido.

Um **ponteiro** é uma variável que guarda um **endereço** em vez de um valor
comum. Ele também mora numa gaveta (tem endereço próprio), mas o que guarda é o
número de **outra** gaveta. Alguns livros (Ziviani, a tradução do K&R) dizem
**apontador**: é a mesma coisa.

A declaração leva um `*` antes do nome: `int *cartao;` lê-se "cartao é um
ponteiro para int". O tipo diz **o que** mora no endereço apontado, e portanto
quantos bytes ler (4 para `int`, 8 para `double`).

Dois operadores fazem todo o serviço:

- **`&x`** dá o endereço de `x` (assunto 0044), que você guarda no ponteiro:
  `cartao = &pontos;`;
- **`*cartao`** vai ao endereço guardado e mexe no que está lá: é
  **desreferenciar**. Ler `*cartao` dá o valor de `pontos`; escrever
  `*cartao = 150;` muda `pontos`.

O `*` tem três papéis, separados só pelo contexto: multiplicação (`a * b`),
declaração (`int *p`) e desreferência (`*p = 5`).

Ponteiro que ainda não aponta para nada recebe **`NULL`**, endereço especial
que significa "lugar nenhum". Teste com `if (cartao != NULL)` antes de usar.

No caixa da farmácia, o cliente tem 120 pontos no cartão fidelidade. O ponteiro
`cartao` começa em `NULL`. Quando o cliente passa o cartão, `cartao` recebe
`&pontos`. A compra de R$ 30 soma 30 pontos **por meio do ponteiro**, e
`pontos` vira 150:

{{ideia}}

A linha que muda `pontos` nem cita o nome `pontos`:

```c
#include <stdio.h>

int main(void) {
    int pontos = 120;     // pontos do cartão fidelidade
    int *cartao = NULL;   // ponteiro para int; NULL: ainda não aponta para nada

    cartao = &pontos;     // o cliente passou o cartão: cartao guarda &pontos

    printf("&pontos = %p\n", (void *)&pontos);
    printf("cartao  = %p\n", (void *)cartao); // o mesmo endereço
    printf("*cartao = %d\n", *cartao);        // o que tem na gaveta apontada

    if (cartao != NULL) {
        *cartao = *cartao + 30; // compra de R$ 30: muda pontos ATRAVÉS do ponteiro
    } else {
        printf("Compra sem cartão\n");
    }
    printf("pontos  = %d\n", pontos);
    printf("&cartao = %p\n", (void *)&cartao); // o ponteiro também mora numa gaveta
    return 0;
}
// Saída (os endereços mudam a cada execução):
// &pontos = 0x7f631f200030
// cartao  = 0x7f631f200030
// *cartao = 120
// pontos  = 150
// &cartao = 0x7f631f200040
```

Três números diferentes: `cartao` é o endereço guardado (o de `pontos`),
`*cartao` é o valor lá dentro (120, depois 150) e `&cartao` é onde o próprio
ponteiro mora.

Antes de desreferenciar, o programa testa se o ponteiro aponta para algum
lugar. Esse teste contra `NULL` volta no curso inteiro:

{{fluxograma}}

> [!WARNING]
> Ponteiro não inicializado (`int *p;`) guarda **lixo**: um endereço qualquer.
> `*p = 10;` escreve numa gaveta desconhecida: pode travar na hora ou corromper
> outra variável e dar problema só depois. Inicialize sempre, com um endereço
> válido ou `NULL`. E em `int *a, b;` o `*` vale só para `a`; `b` é um `int`
> comum. Para dois ponteiros, `int *a, *b;`.

> [!TIP]
> **Por dentro do C:** todo ponteiro de dado tem o mesmo tamanho (8 bytes em
> 64 bits); o tipo muda a **leitura**: `*cartao` busca 4 bytes e os trata como
> `int`. O `NULL` é, na prática, o endereço 0, região proibida de propósito:
> desreferenciá-lo derruba o programa na hora (*segmentation fault*), em vez de
> corromper algo em silêncio.

> [!NOTE]
> **Pergunta para você:** depois de `int x = 5; int *p = &x; int *q = p;
> *q = 8;`, quanto valem `x` e `*p`? Quantas variáveis `int` existem nesse
> trecho?

{{pratique}}
