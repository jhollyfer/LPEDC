## 0003 · Tipos e limites

- **Bit e byte**: o bit vale 0 ou 1; oito bits formam um byte. Com `n` bits
  cabem 2ⁿ valores, então um byte vai de 0 a 255 (FEOFILOFF, 2009, ap. C).
- **Binário**: base 2; cada casa vale o dobro da casa à direita.
  `00001101` = 8 + 4 + 1 = 13 (FEOFILOFF, 2009, ap. C).
- **Hexadecimal**: base 16 (0 a 9 e A a F). Cada dígito vale 4 bits; no C
  começa com `0x`: `0xFF` = 255 (DEITEL; DEITEL, 2011).
- **Modificadores**: `short` (menor), `long` e `long long` (maiores) e
  `unsigned` (sem negativos, o dobro de positivos) (BACKES, 2013).
- **`<limits.h>` e `<stdint.h>`**: o padrão só garante tamanhos mínimos. O
  `limits.h` dá os limites reais (`INT_MAX`); o `stdint.h` dá tamanho exato
  (`int32_t`, `uint16_t`) (ISO/IEC, 2018).
- **Overflow**: passar do limite do tipo. Em `unsigned` o valor dá a volta,
  como um odômetro; com sinal é **comportamento indefinido** (ISO/IEC, 2018).
- **Complemento de dois**: forma de guardar negativos. Por isso a faixa é
  assimétrica (-128 a 127 num byte) (FEOFILOFF, 2009, ap. C).

| Tipo (PC Linux 64 bits) | Bytes | Faixa |
| --- | --- | --- |
| `char` | 1 | -128 a 127 |
| `unsigned char` | 1 | 0 a 255 |
| `short` | 2 | -32.768 a 32.767 |
| `unsigned short` | 2 | 0 a 65.535 |
| `int` | 4 | cerca de ±2,1 bilhões |
| `long` / `long long` | 8 | cerca de ±9,2 quintilhões |

> [!WARNING]
> Estouro em tipo com sinal não "dá a volta" de forma garantida:
> `int x = INT_MAX; x = x + 1;` é comportamento indefinido. Com as flags de
> estudo, o gcc acusa `signed integer overflow`. Escolha um tipo que caiba.

{{exemplo}}

A catraca de um estádio conta torcedores num `unsigned short` (16 bits). No
65.536º torcedor, o bit de cima não cabe e o painel volta a zero:

{{ideia}}

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

Quem decide "cabe em 16 bits?" é o hardware; se não cabe, guarda só os 16
bits de baixo, sem avisar:

{{fluxograma}}
