## 0178 · Hash: divisão e multiplicação

- **Método da divisão**: **h(k) = k mod m**. É rápido, mas o `m` decide tudo
  (CORMEN et al., 2024, cap. 11).
- **m ruins**: `m = 2^p` usa só os p bits de baixo de `k` (`k & (m - 1)`);
  `m = 10^d`, só os d últimos dígitos; `m = 2^p - 1` não distingue duas letras
  trocadas de lugar num texto (CORMEN et al., 2024, cap. 11).
- **m bom**: um **primo longe de uma potência de 2**. Para 2000 chaves com uns
  3 por balde, 673 serve (longe de 512 e de 1024) (CORMEN et al., 2024, cap. 11).
- **Método da multiplicação**: **h(k) = ⌊m · (k·A mod 1)⌋**, com `0 < A < 1`.
  A parte fracionária mistura todos os dígitos de `k`, e o `m` pode ser até
  potência de 2 (CORMEN et al., 2024, cap. 11).
- **Constante de Knuth**: **A ≈ (√5 − 1) / 2 = 0,6180339887...**; chaves
  seguidas pulam pela tabela inteira (KNUTH, 1998).
- **Versão em inteiros**: com 32 bits e `m = 2^p`, troque `A` por
  **s = ⌊A · 2^32⌋ = 2654435769**. O balde são os p bits de cima dos 32 de
  baixo de `k · s`: `(k * s) >> (32 - p)` com `uint32_t` (KNUTH, 1998).

> [!WARNING]
> O produto **tem que ser `unsigned`**: com `int`, `k * 2654435769` estoura
> (comportamento indefinido). E pegue os bits **de cima** (`>> (32 - p)`), não
> os de baixo (`& (m - 1)`), que repetem o problema da divisão por 2^p.

{{exemplo}}

Um atacadão registra fardos de 16 unidades pelo número do último item: 16,
32, 48 até 160. Com `k % 16`, os dez caem no balde 0. Os fardos passam por
divisão por 16, divisão por 13 e multiplicação com m = 16; no desenho, a conta
do fardo 48:

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

Com 16, os dez num balde só; com 13, nenhuma colisão; com a multiplicação,
uma (16 e 160). O fluxograma confere o `p` (deslocar 32 bits ou mais é
indefinido), multiplica, deixa o `uint32_t` cortar e desloca:

{{fluxograma}}
