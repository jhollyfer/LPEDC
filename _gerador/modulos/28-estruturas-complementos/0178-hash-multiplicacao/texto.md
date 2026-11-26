## 0178 · Hash: divisão e multiplicação

A tabela de dispersão do 0105 só é rápida se a função hash espalhar as chaves
pelos baldes. Imagine um atacadão que registra fardos de 16 unidades pelo
número do último item: 16, 32, 48, até 160. Com 16 baldes e `k % 16`, os dez
fardos caem todos no balde 0, a lista desse balde tem dez nós e a busca volta
a custar O(n). A conta está certa; o que falhou foi a escolha do tamanho da
tabela. Este assunto mostra como escolher bem e apresenta um método que
depende menos dessa escolha.

O **método da divisão** é o que você já usou: **h(k) = k mod m**, com `m` o
número de baldes. É uma conta só e roda rápido, mas o resultado depende muito
do valor de `m` (CORMEN et al., 2024, cap. 11). Alguns valores são ruins por
um motivo que dá para ver em binário.

Se `m = 2^p`, o resto da divisão por `m` é formado só pelos **p bits de
baixo** de `k`; em C, `k % 16` dá o mesmo que `k & 15`. O resto dos bits é
ignorado. Os fardos de 16 em 16 têm os 4 bits de baixo sempre zero, e por
isso colidem todos. Com `m = 10^d` acontece o mesmo em decimal: só os d
últimos dígitos contam, e com m = 100 todo preço terminado em 00 cai no balde
0. E `m = 2^p - 1` é ruim para textos tratados como números: trocar duas
letras de lugar não muda o balde (CORMEN et al., 2024, cap. 11).

A regra do Cormen para o método da divisão é escolher um **primo longe de uma
potência de 2**. Se você espera umas 2000 chaves e aceita uns 3 por balde,
precisa de uns 667 baldes; 673 é primo e fica longe de 512 e de 1024, então
serve (CORMEN et al., 2024, cap. 11).

O **método da multiplicação** tira o peso da escolha de `m`. Você multiplica a
chave por uma constante `A`, com `0 < A < 1`, fica só com a **parte
fracionária** do produto (o que vem depois da vírgula, escrito `k·A mod 1`) e
multiplica isso por `m`, descartando as casas decimais:
**h(k) = ⌊m · (k·A mod 1)⌋**. A parte fracionária de `k·A` depende de todos os
dígitos de `k`, não só dos últimos, então `m` pode ser qualquer valor, até
uma potência de 2 (CORMEN et al., 2024, cap. 11).

Qualquer `A` entre 0 e 1 funciona, mas alguns espalham melhor. Knuth sugere
**A ≈ (√5 − 1) / 2 = 0,6180339887...**, o inverso da razão áurea: com ele,
chaves seguidas caem longe umas das outras e cobrem a tabela inteira (KNUTH,
1998). Veja a chave 10 com m = 16: 10 · A = 6,180339..., a parte fracionária é
0,180339..., vezes 16 dá 2,88..., e o balde é 2.

Em `double`, essa conta é lenta e sujeita a arredondamento. A versão usada na
prática trabalha só com inteiros. Com palavras de 32 bits e `m = 2^p`, troque
`A` pela constante inteira **s = ⌊A · 2^32⌋ = 2654435769**. O produto `k · s`
tem até 64 bits; os 32 de baixo representam, em binário, a parte fracionária
de `k·A`. Os **p bits mais altos** desses 32 são o balde. Em C, um `uint32_t`
já guarda só os 32 bits de baixo do produto, e um deslocamento à direita de
`32 - p` posições deixa os p de cima (KNUTH, 1998):

```c
uint32_t k = 10, s = 2654435769u;
uint32_t produto = k * s;           // a conta é feita mod 2^32
printf("%u\n", produto >> (32 - 4)); // m = 16 = 2^4: os 4 bits de cima
// 2
```

O resultado bate com a conta em `double`: balde 2. Repare que não há divisão
nenhuma: só uma multiplicação e um deslocamento, que o processador faz bem
mais depressa que uma divisão.

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
