## 0004 · Binário, hexadecimal, bit e byte

Já reparou que 255 aparece em todo canto? Cor RGB vai de 0 a 255, cada pedaço
de um IP (`192.168.0.255`) também. Não é coincidência: é o maior número que
cabe em **um byte**.

O computador é feito de bilhões de chavinhas que só têm dois estados: ligada
ou desligada. Cada chavinha guarda um **bit**: 0 ou 1. Oito bits juntos formam
um **byte**. Toda informação, seja número, letra, foto ou o seu programa, vira
uma fileira de bits.

Para contar só com 0 e 1 usamos a **base 2** (binário). Funciona igual à base
10 que você já usa, só que cada casa vale o dobro da casa da direita, em vez de
10 vezes mais:

| casa | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| vale | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

**Binário para decimal**: some o valor das casas que têm 1. **Decimal para
binário**: divida por 2 até chegar a 0 e leia os restos de baixo para cima. Ou
pegue as casas da maior para a menor: cabe 8? cabe 4? E assim por diante.

Escrever 32 zeros e uns é cansativo. Por isso existe a **base 16**
(hexadecimal), que usa 0 a 9 e A a F (A = 10, ..., F = 15). Cada dígito
hexadecimal vale **exatamente 4 bits**. Um byte são dois dígitos: `1111 1111`
= `FF` = 255. No C, hexadecimal começa com `0x`: `0xFF`.

Vamos ver na prática. O número 13 em binário: cabe 8 (sobra 5), cabe 4 (sobra
1), não cabe 2, cabe 1. As casas 8, 4 e 1 ficam com 1, e a casa 2 fica com 0:

{{ideia}}

O C mostra o mesmo número nas três bases. O laço que monta o binário usa
operadores de bits, que você vai estudar no assunto 0070. Por enquanto, confie
e repare na saída:

```c
#include <stdio.h>

int main(void) {
    int n = 13;

    printf("decimal: %d\n", n);     // %d mostra em base 10
    printf("hexa:    0x%X\n", n);   // %X mostra em base 16

    printf("binário: ");
    for (int casa = 3; casa >= 0; casa--) {
        printf("%d", (n >> casa) & 1); // pega o bit daquela casa
    }
    printf("\n");
    return 0;
}
// Saída:
// decimal: 13
// hexa:    0xD
// binário: 1101
```

Repara no fluxograma: o "decimal para binário" é uma repetição. Pergunta se a
casa cabe, anota 1 ou 0 e vai para a próxima, até acabarem as casas:

{{fluxograma}}

> [!WARNING]
> `10` pode ser dez, dois (em binário) ou dezesseis (em hexadecimal). Sempre
> deixe a base clara. No C: `10` é decimal, `0x10` é hexadecimal (16) e, cuidado,
> `010` é **octal** (8)! Um zero à esquerda muda o valor. Nunca escreva
> `int ddd = 092;`: nem compila, porque 9 não existe em octal.

> [!TIP]
> **Por dentro do C:** um `int` costuma ter 4 bytes (32 bits). O 13 fica na
> memória como `00000000 00000000 00000000 00001101`. E em que ordem os 4 bytes
> ficam? Nos PCs (Intel/AMD) e na maioria dos celulares (ARM), o byte **menos**
> significativo vem primeiro, no endereço menor. Isso se chama
> **little-endian**: na memória, o 13 aparece como `0D 00 00 00`. Você vai
> enxergar isso de verdade no módulo de ponteiros.

> [!NOTE]
> **Pergunta para você:** quanto é `1111` em decimal? E `10000`? Por que
> somar 1 em `1111` dá `10000`? Pense no odômetro do carro passando de 9999
> para 10000.

{{pratique}}
