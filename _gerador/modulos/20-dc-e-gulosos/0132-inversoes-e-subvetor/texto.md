## 0132 · Inversões e subvetor de soma máxima

Você e o Caio montaram, cada um, o top 8 de séries do ano. Os gostos de
vocês batem? Um jeito honesto de medir: pegue cada **par** de séries e veja se
os dois concordam sobre qual vem antes. Se você põe "Sintonia" antes de "Cidade
Invisível" e o Caio faz o contrário, é um par em desacordo. Os aplicativos de
recomendação fazem essa conta o tempo todo para achar gente de gosto parecido.

Escreva as suas séries na sua ordem e, embaixo de cada uma, a posição que ela
tem no ranking do Caio. Se ele concordasse com tudo, o vetor sairia
`1 2 3 4 5 6 7 8`. Cada par em desacordo vira uma **inversão**: um par de
posições `i < j` com `v[i] > v[j]`. Contar inversões é medir o quanto um vetor
está fora de ordem: zero no vetor ordenado, `n(n - 1)/2` no vetor ao contrário.

O jeito óbvio testa todos os pares com dois laços: O(n²). Para 8 séries, 28
pares, tudo bem. Para comparar o histórico de 1 milhão de usuários, são meio
trilhão de pares. A divisão e conquista do assunto anterior resolve em
**O(n log n)**, pegando carona no merge sort (assunto 0094).

Divida o vetor ao meio. Toda inversão é de um destes três tipos:

1. os dois elementos estão na metade **esquerda**;
2. os dois estão na metade **direita**;
3. um em cada metade: a inversão **cruza** o meio.

Os tipos 1 e 2 são o mesmo problema, menor: a recursão resolve. O pulo do gato
está no tipo 3. Se as duas metades já estiverem **ordenadas**, a intercalação
conta as inversões cruzadas de graça: quando um elemento da direita sai antes,
ele é menor que **todos** os que ainda sobram na esquerda. Se sobram `q - i`
elementos lá, são `q - i` inversões de uma vez, sem olhar um por um.

Por isso a função faz duas coisas ao mesmo tempo: devolve a contagem **e**
deixa o pedaço ordenado, pronto para a intercalação de cima. A recorrência é a
do merge sort, T(n) = 2T(n/2) + O(n), que dá O(n log n).

Vamos ver na prática. No vetor do Caio, a metade esquerda tem 3 inversões
dentro dela e a direita tem 4. Depois de ordenadas, a intercalação das duas
acha mais 6 cruzadas: o 2 passa na frente de 3 elementos da esquerda, o 4 de
2 e o 6 de 1:

{{ideia}}

O mesmo exemplo em C. É o merge sort com um contador; o `printf` mostra, para
cada pedaço, as inversões da esquerda, da direita e as cruzadas:

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

A última intercalação: `1 3 5 7` com `2 4 6 8`. Toda vez que o menor vem da
direita, ele soma os que ainda sobram na esquerda:

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

Repara no fluxograma: é a chamada de cima, com o vetor inteiro. As duas
chamadas recursivas contam dentro de cada metade, e a intercalação conta o
que cruza:

{{fluxograma}}

### O subvetor de soma máxima

O mesmo raciocínio dos três tipos resolve outro problema clássico. Um food
truck anotou o lucro de 8 dias, com prejuízo em alguns: `4 -6 3 5 -2 6 -9 2`.
Qual sequência de dias **seguidos** deu o maior lucro somado? Testar todas as
faixas é O(n²). Dividindo ao meio, a melhor faixa está:

1. inteira na **esquerda** (`4 -6 3 5`): a melhor é `3 5`, soma 8;
2. inteira na **direita** (`-2 6 -9 2`): a melhor é `6`, soma 6;
3. **cruzando** o meio: ela é o melhor final da esquerda grudado no melhor
   começo da direita. O melhor final da esquerda é `3 5` (8); o melhor começo
   da direita é `-2 6` (4). Juntos, `3 5 -2 6`, soma **12**.

A resposta é o maior dos três: 12, do dia 2 ao dia 5. Os casos 1 e 2 são
recursão; o caso 3 é um laço que anda do meio para fora, O(n). Mesma
recorrência, mesmo O(n log n). O exemplo A263 traz esse algoritmo em C, e o
A264 mostra um jeito ainda mais rápido, em O(n).

> [!WARNING]
> Na intercalação, a soma é `inv += q - i`, e não `inv++`. Quando o `v[j]` da
> direita sai, ele está fora de ordem com **todos** os elementos de `v[i]` até
> `v[q - 1]`, porque a esquerda está ordenada. Somar 1 contaria só o par com
> `v[i]`. E repare no `<=`: em caso de empate, sai o da esquerda, porque dois
> valores iguais **não** são uma inversão. Com `<`, cada empate viraria uma
> inversão falsa.

> [!TIP]
> **Por dentro do C:** o contador é `long long` de propósito. Um vetor de
> 100 000 elementos ao contrário tem 100 000 · 99 999 / 2 = 4 999 950 000
> inversões, e um `int` de 32 bits vai só até 2 147 483 647. O estouro de
> `int` com sinal é comportamento indefinido; com o `rodar`, o sanitizer
> avisa com `runtime error: signed integer overflow`. Repare também que contar
> **ordena** o vetor: se você ainda precisar da ordem original, conte numa
> cópia (`memcpy` para um vetor alocado antes).

> [!NOTE]
> **Pergunta para você:** quantas inversões tem o vetor `8 7 6 5 4 3 2 1`? E
> quanto o `printf` mostra na linha do `[0, 8)`? Confira a sua conta com a
> fórmula `n(n - 1)/2`.

{{pratique}}
