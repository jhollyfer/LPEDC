## 0178 · Hash: divisão e multiplicação

No atacadão, fardos de 16 unidades são registrados pelo número do último
item: 16, 32, 48, até 160. A tabela tem 16 baldes e usa `k % 16` (0105): os
dez fardos caem **todos no balde 0**, e a busca volta a ser O(n). O problema
está no `m`.

O **método da divisão** é o que você já conhece: **h(k) = k mod m**. É rápido,
mas o `m` decide tudo:

- **m = 2^p é ruim**: `k % 2^p` são os **p bits de baixo** de `k` (`k & (m -
  1)`), e o resto é ignorado. Os fardos de 16 em 16 (4 bits de baixo sempre
  zero) colidem todos;
- **m = 10^d** só olha os d últimos dígitos (com m = 100, preços terminados
  em 00 caem no balde 0);
- **m = 2^p - 1** é ruim para textos: trocar duas letras de lugar não muda o
  balde;
- a regra do livro: um **primo longe de uma potência de 2**. Para 2000 chaves,
  com uns 3 por balde, serve 673 (longe de 512 e de 1024).

O **método da multiplicação** tira a dependência do `m`. Multiplique a chave
por uma constante `A` entre 0 e 1, fique com a **parte fracionária** e
multiplique por `m`:

**h(k) = ⌊m · (k·A mod 1)⌋**

A parte fracionária de `k·A` mistura todos os dígitos de `k`, então o `m` pode
ser qualquer um, até uma **potência de 2**. Knuth sugere **A ≈ (√5 − 1) / 2 =
0,6180339887...**: chaves seguidas pulam pela tabela inteira.

Em `double` a fórmula é lenta e arredonda. Use **inteiros**: com w = 32 bits
e m = 2^p, troque `A` por **s = ⌊A · 2^32⌋ = 2654435769**. Dos 64
bits de `k · s`, os 32 de baixo são o "k·A mod 1" em binário, e os **p bits
mais altos** deles são o balde: `(k * s) >> (32 - p)`, com `uint32_t`, que já
descarta os 32 de cima.

Os dez fardos passam por divisão por 16, divisão por 13 (primo) e
multiplicação com m = 16 (p = 4). No desenho, a conta do fardo 48:

{{ideia}}

No `espalha.c`, as duas multiplicações:

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

O programa do atacadão:

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

Com 16, os dez num balde só. Com 13, nenhuma colisão. Com a multiplicação,
uma (16 e 160), normal para 10 chaves em 16 baldes.

O fluxograma faz a conta do fardo 48: confere o `p` (deslocar 32 bits ou mais
é indefinido), multiplica, deixa o `uint32_t` cortar e desloca. Nenhuma
divisão:

{{fluxograma}}

> [!WARNING]
> O produto **tem que ser `unsigned`**: com `int`, `k * 2654435769` estoura, e
> estouro com sinal é comportamento indefinido. E pegue os bits **de cima**
> (`>> (32 - p)`), não os de baixo (`& (m - 1)`): os de baixo dependem só dos
> bits de baixo de `k`, o problema da divisão por 2^p.

> [!NOTE]
> **Pergunta para você:** com m = 32 (p = 5), em que balde cai o fardo 48 pela
> multiplicação em inteiros? Faça a conta com o produto `0xAA66D2B0` do
> desenho antes de rodar `esp_mult_desloca(48, 5)`.

{{pratique}}
