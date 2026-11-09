## 0178 · Hash: divisão e multiplicação

No atacadão, os produtos saem em fardos de 16 unidades, e cada fardo é
registrado pelo número do último item: 16, 32, 48, até 160. O sistema guarda
os fardos numa tabela hash de 16 baldes com `k % 16`, a função do 0105. Resultado:
os dez fardos caem **todos no balde 0**. A tabela virou uma lista, e a busca
voltou a ser O(n).

A culpa não é das chaves, é do `m`. O Cormen descreve duas famílias clássicas
de função hash para chaves inteiras, e cada uma tem a sua regra para escolher
`m`.

O **método da divisão** é o que você já conhece: **h(k) = k mod m**. É rápido
(uma divisão), mas o `m` decide tudo:

- **m = 2^p é ruim**: `k % 2^p` é exatamente os **p bits de baixo** de `k` (é o
  mesmo que `k & (m - 1)`). A função ignora todo o resto da chave. Chaves que
  só diferem nos bits de cima, como os fardos de 16 em 16 (os 4 bits de baixo
  são sempre zero), colidem todas;
- pela mesma razão, **m = 10^d** só olha os d últimos dígitos (preços
  redondos em centavos, todos terminados em 00, caem no balde 0 com m = 100);
- **m = 2^p - 1** também é ruim para textos: trocar duas letras de lugar não
  muda o balde;
- a regra do livro: escolha um **primo que não fique perto de uma potência de
  2**. Para 2000 chaves com uns 3 por balde, um primo perto de 667, como 673
  (longe de 512 e de 1024).

O **método da multiplicação** tira a dependência do `m`. Multiplique a chave
por uma constante `A` entre 0 e 1, fique só com a **parte fracionária** e
multiplique por `m`:

**h(k) = ⌊m · (k·A mod 1)⌋**

A parte fracionária de `k·A` mistura todos os dígitos de `k`, e aí o `m` pode
ser qualquer um, inclusive uma **potência de 2**. Knuth sugere
**A ≈ (√5 − 1) / 2 = 0,6180339887...**, a parte fracionária da razão áurea:
com ela, chaves seguidas pulam pela tabela inteira, sem se amontoar.

Com `double`, a fórmula tem erro de arredondamento e é lenta. A versão de
verdade é em **inteiros**: com palavras de w = 32 bits e m = 2^p, troque `A`
por **s = ⌊A · 2^32⌋ = 2654435769**. O produto `k · s` tem 64 bits; os 32 de
baixo são o "k·A mod 1" (a parte fracionária, em binário), e os **p bits mais
altos** deles são o balde. Em C: `(k * s) >> (32 - p)`, com `uint32_t`, que
já descarta os 32 bits de cima de graça.

Vamos ver na prática. Os dez fardos, com três funções: divisão por 16,
divisão por 13 (primo) e multiplicação com m = 16 (p = 4). No desenho, a conta
da multiplicação para o fardo 48:

{{ideia}}

O TAD é o `espalha.h`. As duas multiplicações do `espalha.c`:

```c
int esp_multiplicacao(uint32_t k, int m) {
    double produto = k * ESP_A;
    double fracao = produto - floor(produto); // k*A mod 1: só a parte depois da vírgula
    return (int)(m * fracao);
}

int esp_mult_desloca(uint32_t k, int p) {
    uint32_t produto = k * ESP_S; // unsigned: a conta é feita mod 2^32, sem estouro
    return (int)(produto >> (32 - p));
}
```

E o atacadão:

```c
#include <stdio.h>
#include "espalha.h"

int main(void) {
    int div16[16] = {0}, div13[13] = {0}, mult16[16] = {0};
    printf("fardo | k %% 16 | k %% 13 | multiplicação (m = 16)\n");
    for (uint32_t k = 16; k <= 160; k += 16) {
        int a = esp_divisao(k, 16), b = esp_divisao(k, 13), c = esp_mult_desloca(k, 4);
        div16[a]++;
        div13[b]++;
        mult16[c]++;
        printf("%5u | %6d | %6d | %d\n", k, a, b, c);
    }
    printf("Balde mais cheio: %d | %d | %d\n", esp_maior_balde(div16, 16),
           esp_maior_balde(div13, 13), esp_maior_balde(mult16, 16));
    return 0;
}
// Saída:
// fardo | k % 16 | k % 13 | multiplicação (m = 16)
//    16 |      0 |      3 | 14
//    32 |      0 |      6 | 12
//    48 |      0 |      9 | 10
//    64 |      0 |     12 | 8
//    80 |      0 |      2 | 7
//    96 |      0 |      5 | 5
//   112 |      0 |      8 | 3
//   128 |      0 |     11 | 1
//   144 |      0 |      1 | 15
//   160 |      0 |      4 | 14
// Balde mais cheio: 10 | 1 | 2
```

Com 16, os dez num balde só. Com 13, nenhuma colisão. Com a multiplicação e
m = 16, uma colisão (16 e 160), o que é normal para 10 chaves em 16 baldes:
a multiplicação não garante zero colisão, garante que o padrão das chaves não
importa.

Repara no fluxograma: é a conta do fardo 48 pela multiplicação em inteiros.
Depois de conferir o `p` (deslocar 32 bits ou mais é indefinido em C), são
três operações: multiplica, deixa o `uint32_t` cortar os bits de cima,
desloca. Nenhuma divisão:

{{fluxograma}}

> [!WARNING]
> Na versão em inteiros, o produto **tem que ser `unsigned`**. Com `int`,
> `k * 2654435769` estoura, e estouro de inteiro com sinal é comportamento
> indefinido em C (o sanitizer reclama). Com `uint32_t`, o padrão garante a
> conta mod 2^32, que é exatamente o "mod 1" da fórmula. E pegue os bits **de
> cima** (`>> (32 - p)`), não os de baixo (`& (m - 1)`): os de baixo do
> produto dependem só dos bits de baixo de `k`, e você volta ao problema da
> divisão por 2^p (é o bug do E1067).

> [!TIP]
> **Por dentro do C:** uma divisão inteira de 32 bits custa dezenas de ciclos
> num processador x86 moderno; uma multiplicação, uns 3; um deslocamento, 1. Por
> isso a multiplicação com deslocamento é a função hash preferida quando a
> tabela tem tamanho 2^p. O compilador sabe disso: quando o `m` da divisão é
> uma **constante**, ele troca o `%` por multiplicações e deslocamentos
> (tente `gcc -O2 -S` com `k % 13`). Com `m` numa variável, ele não pode, e a
> divisão de verdade acontece a cada busca.

> [!NOTE]
> **Pergunta para você:** com m = 32 (p = 5), em que balde cai o fardo 48 pela
> multiplicação em inteiros? Faça a conta com o produto `0xAA66D2B0` do
> desenho antes de rodar `esp_mult_desloca(48, 5)`.

{{pratique}}
