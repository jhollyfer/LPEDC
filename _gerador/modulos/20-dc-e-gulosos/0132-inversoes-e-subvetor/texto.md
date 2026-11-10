## 0132 · Inversões e subvetor de soma máxima

Você e o Caio montaram o top 8 de séries do ano. Os gostos batem? Se você
põe "Sintonia" antes de "Cidade Invisível" e o Caio faz o contrário, o par
está em desacordo.

Escreva as suas séries e, embaixo, a posição de cada uma no ranking do Caio:
se concordasse com tudo, o vetor seria `1 2 3 4 5 6 7 8`. Cada par em desacordo é uma **inversão**: posições `i < j` com `v[i] > v[j]`.
São zero inversões no vetor ordenado e `n(n - 1)/2` no vetor ao contrário.

Testar todos os pares é O(n²). Pegando carona no merge sort (0094), a divisão
e conquista faz em **O(n log n)**.

Divida o vetor ao meio. Toda inversão é de um destes tipos:

1. os dois elementos estão na metade **esquerda**;
2. os dois estão na metade **direita**;
3. um em cada metade: a inversão **cruza** o meio.

A recursão resolve os tipos 1 e 2. No tipo 3, com as metades **ordenadas**, a
intercalação conta de graça: quando um elemento da direita sai antes, ele é
menor que **todos** os `q - i` que sobram na esquerda, ou seja, `q - i`
inversões de uma vez.

A função devolve a contagem **e** deixa o pedaço ordenado: é a recorrência do
merge sort, O(n log n).

No vetor do Caio, são 3 inversões na esquerda, 4 na direita e mais 6 na
intercalação (o 2 passa na frente de 3, o 4 de 2 e o 6 de 1):

{{ideia}}

É o merge sort com um contador; o `printf` mostra as inversões da esquerda,
da direita e as cruzadas:

```c
#include <stdio.h>
#include <stdlib.h>

// junta v[p..q-1] e v[q..r-1], já ordenados, e devolve quantas inversões
// cruzam as duas metades
long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;       // v[j] é menor que TODOS os que sobram à esquerda
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

// ordena v[p..r-1] e devolve o número de inversões que havia nele
long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;                       // 0 ou 1 elemento: nenhuma inversão
    }
    int q = p + (r - p) / 2;
    long long esq = conta(v, w, p, q);  // inversões dentro da esquerda
    long long dir = conta(v, w, q, r);  // inversões dentro da direita
    long long cruz = intercala(v, w, p, q, r); // um de cada lado
    printf("[%d, %d): %lld + %lld + %lld\n", p, r, esq, dir, cruz);
    return esq + dir + cruz;
}

int main(void) {
    // posição, no ranking do Caio, de cada série do seu top 8
    int caio[] = {3, 7, 1, 5, 8, 2, 6, 4};
    int n = 8;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    long long total = conta(caio, w, 0, n);
    printf("Pares em desacordo: %lld de %d\n", total, n * (n - 1) / 2);
    free(w);
    return 0;
}
// Saída:
// [0, 2): 0 + 0 + 0
// [2, 4): 0 + 0 + 0
// [0, 4): 0 + 0 + 3
// [4, 6): 0 + 0 + 1
// [6, 8): 0 + 0 + 1
// [4, 8): 1 + 1 + 2
// [0, 8): 3 + 4 + 6
// Pares em desacordo: 13 de 28
```

### Passo a passo

Última intercalação: `1 3 5 7` com `2 4 6 8`. Quando o menor vem da direita,
soma os que sobram na esquerda:

| sai | de onde | sobram na esquerda | soma |
| --- | --- | --- | --- |
| 1 | esquerda | | 0 |
| 2 | direita | 3, 5, 7 | 3 |
| 3 | esquerda | | 3 |
| 4 | direita | 5, 7 | 5 |
| 5 | esquerda | | 5 |
| 6 | direita | 7 | 6 |
| 7 | esquerda | | 6 |
| 8 | direita | (nenhum) | 6 |

No fluxograma, as duas chamadas recursivas contam dentro de cada metade e a
intercalação conta o que cruza:

{{fluxograma}}

### O subvetor de soma máxima

Os mesmos três tipos resolvem outro problema. Um food truck anotou o lucro de
8 dias: `4 -6 3 5 -2 6 -9 2`. Qual faixa de dias **seguidos** deu o maior
lucro somado? Dividindo ao meio, ela está:

1. inteira na **esquerda** (`4 -6 3 5`): `3 5`, soma 8;
2. inteira na **direita** (`-2 6 -9 2`): `6`, soma 6;
3. **cruzando** o meio: melhor final da esquerda (`3 5`, 8) mais melhor
   começo da direita (`-2 6`, 4): `3 5 -2 6`, soma **12**.

A resposta é o maior dos três: 12, do dia 2 ao 5. O caso 3 é um laço do meio
para fora, O(n), e o total é O(n log n). O A263 traz o algoritmo em C e o
A264, um jeito em O(n).

> [!WARNING]
> A soma é `inv += q - i`, e não `inv++`: o `v[j]` que sai está fora de ordem
> com **todos** os elementos de `v[i]` a `v[q - 1]`. E o `<=` importa: valores
> iguais **não** são inversão.

> [!TIP]
> **Por dentro do C:** o contador é `long long`: 100 000 elementos ao contrário
> dão 4 999 950 000 inversões, mais que um `int` suporta. Contar também
> **ordena**; para manter a ordem original, conte numa cópia (`memcpy`).

> [!NOTE]
> **Pergunta para você:** quantas inversões tem o vetor `8 7 6 5 4 3 2 1`? E
> quanto o `printf` mostra na linha do `[0, 8)`? Confira a sua conta com a
> fórmula `n(n - 1)/2`.

{{pratique}}
