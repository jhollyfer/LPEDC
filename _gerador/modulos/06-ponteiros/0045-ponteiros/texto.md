## 0045 · Ponteiros

Quando você pede comida pelo app, o entregador não leva a sua casa no
celular: leva o **endereço** dela. Com o endereço, ele chega na porta e
entrega o pedido. Mudou o que tem dentro da casa sem nunca ter carregado a
casa.

Um **ponteiro** é isso: uma variável que guarda um **endereço** em vez de um
valor comum. Ela também mora numa gaveta da memória (tem o próprio
endereço), mas o que está dentro dela é o número de **outra** gaveta.

Declarar tem um `*` antes do nome: `int *cartao;` se lê "cartao é um
ponteiro para int". O tipo importa: diz **o que** mora no endereço apontado,
e portanto quantos bytes ler lá (4 para `int`, 8 para `double`).

Dois operadores fazem todo o serviço:

- **`&x`** dá o endereço de `x` (assunto 0044). É o que você guarda no
  ponteiro: `cartao = &pontos;`;
- **`*cartao`** vai até o endereço guardado e mexe no que está lá. Isso se
  chama **desreferenciar**. Ler `*cartao` dá o valor de `pontos`; escrever
  `*cartao = 150;` muda `pontos`.

O `*` tem três papéis e só o contexto separa: multiplicação (`a * b`),
declaração (`int *p`) e desreferência (`*p = 5`). Leia devagar no começo.

E se o ponteiro ainda não aponta para nada? Use **`NULL`**: um endereço
especial que significa "lugar nenhum". Dá para testar (`if (cartao != NULL)`)
antes de usar.

Vamos ver na prática. No caixa da farmácia, o cliente tem 120 pontos no
cartão fidelidade. O ponteiro `cartao` começa em `NULL` (nenhum cartão).
Quando o cliente passa o cartão, `cartao` recebe `&pontos`. A compra de
R$ 30 soma 30 pontos **através do ponteiro**, e `pontos` vira 150:

{{ideia}}

No código, repare que a linha que muda `pontos` nem cita o nome `pontos`:

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

Três números diferentes, não confunda: `cartao` é o endereço guardado (o de
`pontos`), `*cartao` é o valor lá dentro (120, depois 150) e `&cartao` é
onde o próprio ponteiro mora.

Repara no fluxograma: antes de desreferenciar, o programa pergunta se o
ponteiro aponta para algum lugar. Esse teste contra `NULL` é um hábito que
você vai repetir o curso inteiro:

{{fluxograma}}

> [!WARNING]
> Ponteiro declarado e não inicializado (`int *p;`) guarda **lixo**: um
> endereço qualquer. `*p = 10;` escreve 10 numa gaveta desconhecida. Pode
> travar na hora, pode corromper outra variável e só dar problema bem
> depois. Sempre inicialize: com um endereço válido ou com `NULL`. E cuidado
> com `int *a, b;`: o `*` vale só para `a`. Aqui `b` é um `int` comum. Para
> dois ponteiros, `int *a, *b;`.

> [!TIP]
> **Por dentro do C:** todo ponteiro de dado tem o mesmo tamanho, 8 bytes
> num sistema de 64 bits, aponte ele para `char` ou para `double`. O tipo
> não muda o ponteiro: muda a **leitura**. `*cartao` manda o processador
> buscar 4 bytes a partir do endereço e tratar como `int`. E o `NULL` vale,
> na prática, o endereço 0. O sistema deixa essa região da memória proibida
> de propósito: desreferenciar `NULL` derruba o programa na hora
> (*segmentation fault*), em vez de corromper algo em silêncio. Falhar cedo
> é bom.

> [!NOTE]
> **Pergunta para você:** depois de `int x = 5; int *p = &x; int *q = p;
> *q = 8;`, quanto valem `x` e `*p`? Quantas variáveis `int` existem nesse
> trecho?

{{pratique}}
