## 0171 · Com sinal e sem sinal

A loja vendeu 3 fones de um estoque de 2, e o sistema anunciou **4294967295
fones**. O estoque era `unsigned`, e número sem sinal não é negativo.

O **com sinal** (`int`, `signed char`, `long`) guarda negativos: num `int` de
32 bits, de -2147483648 a 2147483647. O **sem sinal** (`unsigned`, `unsigned
char`, `size_t`) vai de 0 a 4294967295 (`UINT_MAX`). `sizeof` e `strlen`
devolvem `size_t`.

O -1 de um `int` são 32 bits ligados, que como `unsigned` valem 4294967295. A
conta sem sinal **dá a volta**, como um odômetro: `2u - 3u` é 4294967295 e
`UINT_MAX + 1u` é 0 (módulo 2³², definido). Estourar um `int` com sinal, como
`INT_MAX + 1`, é comportamento indefinido.

Com tipos misturados, o C aplica duas regras antes de calcular:

1. **Promoção inteira**: `char`, `short`, `unsigned char`, `bool` e `enum`
   viram `int`. `unsigned char` 200 + 100 dá 300, um `int`; só guardar num
   byte corta o excesso.
2. **Conversão aritmética usual**: os operandos viram o tipo "maior". Entre
   `int` e `unsigned` do mesmo tamanho, ganha o `unsigned`. Se o com sinal
   for maior e couber todo o sem sinal (`long` de 64 bits contra `unsigned`
   de 32), ganha o com sinal. Com `double`, tudo vira `double`.

A regra 2 gera a pegadinha mais famosa: `-1 > 0u` é **verdadeiro**, porque o
`-1` vira 4294967295. Já `-1L < 1u` é verdadeiro no Linux de 64 bits: o `unsigned`
cabe no `long`.

O desenho mostra os 4 bytes do saldo -1 e as duas leituras. A comparação com
`0u` usa a sem sinal:

{{ideia}}

O programa repete as três situações:

```c
#include <limits.h>
#include <stdio.h>

int main(void) {
    unsigned estoque = 2;  // 2 fones na prateleira
    estoque = estoque - 3; // vendeu 3: unsigned não tem negativo, dá a volta
    printf("estoque = %u (UINT_MAX = %u)\n", estoque, UINT_MAX);

    int saldo = -1;        // R$ -1 na conta
    unsigned zero = 0u;
    // saldo > zero misturaria int e unsigned: o int viraria unsigned.
    // O gcc avisa (-Wsign-compare); aqui a conversão vai escrita, à vista
    printf("(unsigned)saldo = %u\n", (unsigned)saldo);
    printf("-1 > 0u? %s\n", (unsigned)saldo > zero ? "sim" : "não");
    printf("-1 > 0?  %s\n", saldo > 0 ? "sim" : "não");

    unsigned char a = 200, b = 100; // dois bytes de 0 a 255
    printf("a + b = %d\n", a + b);  // promoção: os dois viram int antes da soma
    unsigned char c = a + b;        // guardar num byte corta: 300 - 256
    printf("c = %d\n", c);
    return 0;
}
// Saída:
// estoque = 4294967295 (UINT_MAX = 4294967295)
// (unsigned)saldo = 4294967295
// -1 > 0u? sim
// -1 > 0?  não
// a + b = 300
// c = 44
```

No fluxograma, a pergunta real é sobre 4294967295:

{{fluxograma}}

> [!WARNING]
> `for (size_t i = n - 1; i >= 0; i--)` nunca termina: o `size_t` é sempre
> `>= 0` e, ao passar de 0, vira 18446744073709551615 e o laço lê fora do
> vetor. O gcc avisa ("comparison of unsigned expression in '>= 0' is always
> true"). Escreva `for (size_t i = n; i-- > 0;)`, que funciona até com `n =
> 0`.
>
> Sem aviso: `if (strlen(a) - strlen(b) > 0)` é verdadeiro sempre que os
> tamanhos diferem, porque a subtração de `size_t` nunca dá negativo.

> [!TIP]
> Para bits e máscaras, use `unsigned`: deslocar negativo é indefinido ou
> depende da implementação.

> [!NOTE]
> **Pergunta para você:** com `unsigned char x = 0x0F;`, quanto vale `~x`? É
> 0xF0 (240) ou um número negativo? Pense na promoção inteira antes de rodar
> `printf("%d\n", ~x);`.

{{pratique}}
