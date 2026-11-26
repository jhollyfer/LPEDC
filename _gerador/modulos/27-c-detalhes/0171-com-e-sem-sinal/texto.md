## 0171 · Com sinal e sem sinal

A loja tinha 2 fones no estoque, vendeu 3, e o sistema anunciou um estoque
de **4294967295 fones**. Ninguém digitou esse número. O estoque estava numa
variável `unsigned`, e uma variável sem sinal não consegue guardar -1: a
conta deu a volta e caiu no maior valor possível. Entender por que isso
acontece evita uma família inteira de erros silenciosos em C.

Os tipos inteiros do C se dividem em dois grupos. Os **com sinal**, como
`int`, `signed char` e `long`, guardam números negativos e positivos: num
`int` de 32 bits, de -2147483648 a 2147483647 (BACKES, 2013). Os **sem
sinal**, como `unsigned`, `unsigned char` e `size_t`, guardam só zero e
positivos, e com os mesmos 32 bits vão de 0 a 4294967295, o valor da
constante `UINT_MAX`. O tipo sem sinal aparece mesmo quando você não o
pediu: `sizeof` e `strlen` devolvem `size_t` (KERNIGHAN; RITCHIE, 1988,
cap. 2).

Os mesmos bits podem significar números diferentes, conforme o tipo. O C
guarda os negativos em **complemento de dois**: o -1 de um `int` são os 32
bits todos ligados. Lidos como `unsigned`, esses mesmos 32 bits valem
4294967295 (DEITEL; DEITEL, 2011, apêndice D). O número na memória não
muda; muda a leitura.

A aritmética sem sinal **dá a volta**, como o odômetro de um carro que passa
de 999999 para 000000. Toda conta é feita módulo 2³²: `2u - 3u` dá
4294967295, e `UINT_MAX + 1u` dá 0. Esse comportamento é definido pela
norma e você pode contar com ele. Já estourar um tipo **com sinal**, como
em `INT_MAX + 1`, é comportamento indefinido: a norma não diz o que
acontece (ISO/IEC, 2018).

O perigo maior aparece quando uma expressão mistura tipos. Antes de
calcular, o C aplica duas regras. A primeira é a **promoção inteira**: os
tipos menores que `int` (`char`, `short`, `unsigned char`, `bool` e os
`enum`) viram `int` antes de qualquer conta (ISO/IEC, 2018). Por isso dois
`unsigned char` valendo 200 e 100 somam 300, um `int`; o excesso só é
cortado se você guardar o resultado num byte, e aí sobra 44.

A segunda é a **conversão aritmética usual**: quando os dois operandos têm
tipos diferentes, os dois viram o tipo "maior" antes da conta (KERNIGHAN;
RITCHIE, 1988, cap. 2). Entre `int` e `unsigned` do mesmo tamanho, ganha o
`unsigned`. Se o tipo com sinal for maior e conseguir guardar todos os
valores do sem sinal, como um `long` de 64 bits contra um `unsigned` de 32,
ganha o com sinal. E se um dos dois é `double`, tudo vira `double`.

Dessa segunda regra sai a pegadinha mais famosa: `-1 > 0u` é
**verdadeiro**. O `0u` é `unsigned`, então o `-1` é convertido para
`unsigned` e vira 4294967295, que é maior que 0. Já `-1L < 1u` é
verdadeiro no Linux de 64 bits, porque lá o `long` tem 64 bits e o
`unsigned` cabe nele, e a comparação é feita com sinal.

Há um lugar em que o sem sinal é a escolha certa: bits e máscaras. Deslocar
um número negativo com `<<` é indefinido, e com `>>` depende da
implementação. Com `unsigned`, os deslocamentos e o `~` fazem exatamente o
que os bits sugerem (DEITEL; DEITEL, 2011, cap. 10).

| Expressão | Resultado | Por quê |
| --- | --- | --- |
| `-1 > 0u` | verdadeiro | o `-1` vira 4294967295 |
| `-1L < 1u` | verdadeiro (Linux 64 bits) | o `unsigned` cabe no `long` |
| `2u - 3u` | 4294967295 | volta módulo 2³² |

> [!WARNING]
> `for (size_t i = n - 1; i >= 0; i--)` nunca termina: o `size_t` é sempre
> `>= 0` e, ao passar de 0, vira 18446744073709551615. Escreva
> `for (size_t i = n; i-- > 0;)`. E `strlen(a) - strlen(b) > 0` é
> verdadeiro sempre que os tamanhos diferem.

{{exemplo}}

Uma loja vendeu 3 fones de um estoque `unsigned` de 2. O desenho mostra os 4
bytes do saldo -1 e as duas leituras; a comparação com `0u` usa a sem sinal:

{{ideia}}

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
