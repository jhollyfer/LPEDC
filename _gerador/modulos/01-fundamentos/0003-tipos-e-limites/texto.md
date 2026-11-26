## 0003 · Tipos e limites

Toda variável tem um tamanho fixo, e um tamanho fixo tem um teto. Se o
número que você quer guardar não cabe, o C não aumenta a variável: ele
guarda só o pedaço que cabe e segue em frente, muitas vezes sem avisar.
Para escolher o tipo certo, você precisa saber como o número fica na
memória e até onde cada tipo vai.

Pense no odômetro de um carro antigo, com cinco rodinhas de 0 a 9. Ele mede
até 99.999 km. No quilômetro seguinte, todas as rodinhas voltam a zero e o
painel mostra 00000. O carro andou, mas o mostrador não tem casa para o
número novo. A memória do computador funciona do mesmo jeito, só que as
rodinhas têm duas posições em vez de dez.

Cada rodinha é um **bit**, uma chave que vale 0 ou 1. Oito bits formam um
**byte**. Com `n` bits cabem 2ⁿ combinações diferentes, então um byte guarda
256 valores, de 0 a 255 (FEOFILOFF, 2009, ap. C). Dois bytes guardam 65.536
valores; quatro bytes, mais de 4 bilhões.

O inteiro fica na memória em **binário**, a base 2. Na base 10, cada casa
vale dez vezes a casa da direita (unidade, dezena, centena). Na base 2, cada
casa vale o **dobro** da casa da direita: 1, 2, 4, 8, 16, 32, 64, 128. Para
ler um binário, some as casas que têm 1: `00001101` é 8 + 4 + 1 = 13
(FEOFILOFF, 2009, ap. C). Com os oito bits ligados, `11111111`, a soma dá
255, o maior valor de um byte.

| casa | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| vale | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

Escrever binário cansa, então se usa uma abreviação: o **hexadecimal**, a
base 16. Os dígitos vão de 0 a 9 e depois de A (10) a F (15). Cada dígito
hexa equivale a exatamente 4 bits, e um byte cabe em dois dígitos:
`1111 1111` é `FF`. No C, um número em hexadecimal começa com `0x`, e
`0xFF` vale 255 (DEITEL; DEITEL, 2011).

E os negativos? O C guarda os inteiros com sinal em **complemento de dois**:
o bit mais à esquerda pesa negativo. Num byte, ele vale -128 em vez de +128.
Assim, `10000000` é -128 e `11111111` é -128 + 127 = -1 (FEOFILOFF, 2009,
ap. C). Isso explica por que a faixa é assimétrica: há um negativo a mais,
-128 a 127. E mostra que o mesmo byte `0xFF` vale 255 num `unsigned char` e
-1 num `char`. Os bits são iguais; o tipo decide como lê-los.

O tamanho do tipo decide a sua **faixa**, o menor e o maior valor que ele
guarda. Os **modificadores** ajustam o `int`: `short` usa menos bytes,
`long` e `long long` usam mais, e `unsigned` troca os negativos por mais
positivos, quase o dobro (BACKES, 2013). Sem modificador o tipo tem sinal:
`int` e `signed int` são o mesmo tipo. Num PC Linux de 64 bits:

| Tipo (PC Linux 64 bits) | Bytes | Faixa |
| --- | --- | --- |
| `char` | 1 | -128 a 127 |
| `unsigned char` | 1 | 0 a 255 |
| `short` | 2 | -32.768 a 32.767 |
| `unsigned short` | 2 | 0 a 65.535 |
| `int` | 4 | cerca de ±2,1 bilhões |
| `long` / `long long` | 8 | cerca de ±9,2 quintilhões |

Esses números valem para essa máquina, não para todas. O padrão do C só
garante tamanhos **mínimos**: o `int` pode ter 2 bytes num
microcontrolador, e o `long` tem 4 bytes no Windows. Por isso existem dois
cabeçalhos (ISO/IEC, 2018). O **`<limits.h>`** traz os limites reais da
máquina em que o programa compila, como `INT_MAX` e `USHRT_MAX`. O
**`<stdint.h>`** traz tipos com o tamanho exato no nome: `int8_t`,
`uint16_t`, `int32_t`, `int64_t`.

Passar do limite do tipo se chama **overflow**, ou estouro. Num tipo
`unsigned`, o C garante o comportamento do odômetro: o valor dá a volta e
recomeça do zero. Um `unsigned short` em 65.535 tem os 16 bits ligados;
somar 1 pede um 17º bit, que não existe, e o resultado vira 0. Num tipo com
sinal, o padrão não promete nada: o estouro é **comportamento indefinido**,
e o programa pode fazer qualquer coisa (ISO/IEC, 2018).

> [!WARNING]
> Estouro em tipo com sinal não dá a volta com garantia:
> `int x = INT_MAX; x = x + 1;` é comportamento indefinido. Costuma virar
> -2147483648, mas não conte com isso. Com as flags de estudo, o gcc acusa
> `signed integer overflow`. Escolha um tipo que caiba.

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
