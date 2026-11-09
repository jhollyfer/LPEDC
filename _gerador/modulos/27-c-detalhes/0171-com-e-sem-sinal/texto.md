## 0171 · Com sinal e sem sinal

A loja virtual tinha 2 fones em estoque e vendeu 3 numa promoção relâmpago.
O sistema, em vez de mostrar -1, passou a anunciar **4294967295 fones
disponíveis**. Ninguém errou a conta: o estoque era `unsigned`, e um número
sem sinal não sabe ser negativo.

Todo inteiro do C vem em duas versões. O **com sinal** (`int`, `signed char`,
`long`) guarda negativos: num `int` de 32 bits, de -2147483648 a 2147483647. O
**sem sinal** (`unsigned`, `unsigned char`, `size_t`) usa os mesmos 32 bits só
para o zero e os positivos: de 0 a 4294967295 (`UINT_MAX`). O `size_t`, que o
`sizeof` e o `strlen` devolvem, é sem sinal.

Os bits não sabem que tipo são. O -1 de um `int` são 32 bits ligados, e os
mesmos 32 bits lidos como `unsigned` valem 4294967295. Por isso a conta sem
sinal **dá a volta**, como um odômetro: `2u - 3u` é 4294967295, e
`UINT_MAX + 1u` é 0. Isso é definido pelo padrão (conta módulo 2³²). Já
estourar um `int` com sinal, como `INT_MAX + 1`, é comportamento indefinido.

Quando uma conta mistura tipos, o C aplica duas regras antes de calcular:

1. **Promoção inteira**: `char`, `short`, `unsigned char`, `bool` e `enum`
   viram `int` antes de qualquer conta. `unsigned char` 200 + 100 dá 300, um
   `int`, e só perde o excesso se você guardar o resultado num byte.
2. **Conversão aritmética usual**: os dois operandos viram o tipo "maior".
   Entre `int` e `unsigned` do mesmo tamanho, ganha o `unsigned`: o `int`
   vira sem sinal. Se o com sinal for maior e couber todo o sem sinal (um
   `long` de 64 bits contra um `unsigned` de 32), ganha o com sinal. E se
   houver um `double`, tudo vira `double`.

A regra 2 produz a pegadinha mais famosa de C: `-1 > 0u` é **verdadeiro**. O
`-1` vira `unsigned`, 4294967295, que é maior que 0. Já `-1L < 1u`
é verdadeiro no Linux de 64 bits, porque ali o `unsigned` cabe no `long` e
nada vira sem sinal.

O desenho mostra os 4 bytes do saldo -1, todos com os
oito bits ligados, e as duas leituras possíveis deles. A comparação com
`0u` escolhe a leitura sem sinal:

{{ideia}}

O programa repete as três situações: o estoque que dá a volta, a comparação
misturada e a promoção do `unsigned char`:

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

No fluxograma, a comparação não pergunta "-1 é maior que 0?". Antes dela já
houve uma conversão, e a pergunta real é sobre 4294967295:

{{fluxograma}}

> [!WARNING]
> O laço que desce com `size_t` nunca termina:
> `for (size_t i = n - 1; i >= 0; i--)`. Um `size_t` é sempre `>= 0`; quando
> `i` passa de 0, ele vira 18446744073709551615 e o laço lê fora do vetor. O
> gcc avisa ("comparison of unsigned expression in '>= 0' is always true").
> Escreva `for (size_t i = n; i-- > 0;)`: testa e depois desce, e funciona até
> com `n = 0`. Primo do mesmo erro, e sem aviso nenhum:
> `if (strlen(a) - strlen(b) > 0)` é verdadeiro sempre que os tamanhos são
> diferentes, porque a subtração de dois `size_t` nunca dá negativo.

> [!TIP]
> **Por dentro do C:** o processador usa o **complemento de dois**: o negativo
> de `x` é `~x + 1`. Com isso, somar com ou sem sinal é **a mesma
> instrução** (`add`), e a conversão entre `int` e `unsigned` não custa
> nada: os bits ficam iguais.
 O que muda é a instrução que lê o
> resultado: comparações com sinal usam `jl`/`jg`, sem sinal usam `jb`/`ja`,
> e o deslocamento à direita vira `sar` (copia o bit de sinal: `-16 >> 2` dá
> -4 no gcc) ou `shr` (entra zero). Deslocar um negativo para a direita é
> "definido pela implementação"; para a esquerda, é indefinido. Para bits e
> máscaras, use sempre `unsigned`.

> [!NOTE]
> **Pergunta para você:** com `unsigned char x = 0x0F;`, quanto vale `~x`? É
> 0xF0 (240) ou um número negativo? Pense na promoção inteira antes de rodar
> `printf("%d\n", ~x);`.

{{pratique}}
