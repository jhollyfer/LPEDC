## 0003 · Tipos e limites

A catraca do estádio conta os torcedores num contador de 16 bits. No clássico
de domingo, o Maracanã recebeu 78.838 pessoas. Quando passou o torcedor número
65.536, o painel voltou a **zero**. Ninguém errou a conta: o número não cabia.

A memória é feita de **bits**, chavinhas que valem 0 ou 1. Oito bits formam um
**byte**. O inteiro é guardado em **binário** (base 2), em que cada casa vale
o dobro da casa da direita:

| casa | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| vale | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

Para ler um binário, some as casas com 1: `00001101` é 8 + 4 + 1 = 13. Com os
8 bits ligados, `11111111`, o total é 255. Logo **um byte vai de 0 a 255**:
2⁸ = 256 combinações. Com `n` bits, cabem 2ⁿ valores.

O **hexadecimal** (base 16) abrevia o binário, com dígitos 0 a 9 e A a F
(A = 10, ..., F = 15). Cada dígito hexa vale 4 bits, então um byte são dois
dígitos: `1111 1111` = `FF` = 255. No C, hexadecimal começa com `0x`: `0xFF`.

O tamanho de cada tipo inteiro decide sua **faixa**. Os **modificadores**
mudam o `int`: `short` (menor), `long` e `long long` (maiores) e `unsigned`
(sem sinal: troca os negativos por mais positivos). Sem modificador, o tipo é
**com sinal** (`signed`): `int` e `signed int` são o mesmo tipo. O `char`
puro depende da máquina; no PC Linux ele tem sinal. Num PC Linux de 64 bits:

| Tipo | Bytes | Faixa |
| --- | --- | --- |
| `char` | 1 | -128 a 127 |
| `unsigned char` | 1 | 0 a 255 |
| `short` | 2 | -32.768 a 32.767 |
| `unsigned short` | 2 | 0 a 65.535 |
| `int` | 4 | cerca de ±2,1 bilhões |
| `unsigned int` | 4 | 0 a cerca de 4,3 bilhões |
| `long` / `long long` | 8 | cerca de ±9,2 quintilhões |

O padrão do C só garante mínimos (o `int` pode ter 2 bytes num
microcontrolador, e o `long` tem 4 bytes no Windows). Por isso, o
**`<limits.h>`** traz os limites reais da máquina (`INT_MAX`, `SHRT_MIN`,
`USHRT_MAX`...). Para tamanho exato, o **`<stdint.h>`** tem tipos com os bits
no nome: `int8_t`, `uint16_t`, `int32_t`, `int64_t`.

Passar do limite é **overflow** (estouro). Num `unsigned`, o C garante que o
número dá a volta, como o odômetro que passa de 99999 para 00000. A catraca é
um `unsigned short` em 65.535, com os 16 bits ligados. Somar 1 dá 65.536, que
precisa de 17 bits; o bit de cima não cabe e some:

{{ideia}}

A catraca em C:

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned short catraca = 65535; // 16 bits, todos ligados
    printf("Maior unsigned short: %d\n", USHRT_MAX);
    printf("Catraca: %d (0x%X)\n", catraca, catraca);

    catraca = catraca + 1; // 65536 não cabe em 16 bits
    printf("Mais um torcedor: %d\n", catraca);

    int publico = 78838; // int tem 32 bits: sobra espaço
    printf("Público: %d (o int vai até %d)\n", publico, INT_MAX);
    return 0;
}
// Saída:
// Maior unsigned short: 65535
// Catraca: 65535 (0xFFFF)
// Mais um torcedor: 0
// Público: 78838 (o int vai até 2147483647)
```

No fluxograma, quem pergunta "cabe em 16 bits?" é o hardware. Se não cabe, ele
guarda só os 16 bits de baixo, sem avisar:

{{fluxograma}}

> [!WARNING]
> Com `unsigned`, o estouro dá a volta. Com tipos **com sinal** (`int`,
> `long`...), é **comportamento indefinido**: o padrão não diz o que
> acontece. `int x = INT_MAX; x = x + 1;` costuma virar -2147483648, mas não
> conte com isso. Com as flags de estudo, o gcc acusa
> `runtime error: signed integer overflow`. Escolha um tipo que caiba.

> [!TIP]
> Os negativos usam **complemento de dois**: o bit mais à esquerda pesa
> negativo (-128 num byte). Por isso a faixa é assimétrica (-128 a 127) e o
> byte `0xFF` é 255 num `unsigned char` e -1 num `char`: os bits são iguais,
> o tipo decide como ler.

> [!NOTE]
> **Pergunta para você:** se a catraca começasse em 65.530 e passassem 10
> torcedores, o que o painel mostraria? Mude o programa acima e confira.

{{pratique}}
