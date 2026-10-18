## 0123 · Quickselect

Você está procurando apartamento para alugar e anotou 9 anúncios do bairro:
R$ 1850, 1200, 2400, 980, 1450, 2050, 3100, 1600 e 1300. A média dá R$ 1770,
puxada para cima pela cobertura de R$ 3100. O número que diz quanto custa um
aluguel "típico" é a **mediana**: o valor do meio se a lista estivesse em
ordem. Metade dos anúncios custa menos, metade custa mais.

O jeito óbvio é ordenar e pegar `v[n / 2]`. Funciona, mas é trabalho demais:
para saber quem fica na posição 4, você arrumou as outras 8 posições também.
O problema geral se chama **seleção**: achar o **k-ésimo menor** elemento
(a mediana é o caso `k = n / 2`; o mínimo é `k = 0`).

O **quickselect** (Hoare, 1961, o mesmo do quick sort) usa a separação do
assunto 0095. Depois de um `separa`, o pivô está na posição **final** `j`:
à esquerda só há menores ou iguais, à direita só maiores. Então:

- se `j == k`, o pivô é a resposta;
- se `k < j`, a resposta está à **esquerda**: o lado direito pode ser
  esquecido;
- se `k > j`, a resposta está à **direita**.

A diferença para o quick sort é que ele segue **um lado só**. Não precisa
de recursão: um `while` que encolhe o intervalo `[p, r]` resolve. Você já viu
essa ideia de relance no exercício E569, do módulo 13; aqui ela ganha nome,
custo e cuidados.

Quanto custa? Se o pivô cai perto do meio, cada separação descarta metade:
`n + n/2 + n/4 + ...`, que é menos que `2n`. O quickselect é **O(n) em
média**, contra O(n log n) de ordenar. No pior caso, o pivô é sempre o
maior ou o menor e o custo vira **O(n²)**, como no quick sort.

Vamos ver na prática. A primeira separação, com pivô 1300, deixa o pivô na
posição 2. A mediana está na posição 4, à direita: os três primeiros nunca
mais são olhados. Duas separações depois, o pivô cai exatamente na posição 4:

{{ideia}}

O mesmo exemplo em C:

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// separação de Lomuto (assunto 0095): pivô v[r]; devolve a posição final dele
int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// devolve o elemento que ficaria na posição k (0, 1, ...) se v fosse ordenado
int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        printf("pivô %d na posição %d:", v[j], j);
        for (int i = p; i <= r; i++) {
            printf(" %d", v[i]);
        }
        if (j == k) {
            printf("  -> achou\n");
            return v[j];
        }
        if (k < j) {
            printf("  -> segue à esquerda\n");
            r = j - 1;                  // a resposta está em v[p..j-1]
        } else {
            printf("  -> segue à direita\n");
            p = j + 1;                  // a resposta está em v[j+1..r]
        }
    }
    return v[p];                        // sobrou um só
}

int main(void) {
    int alugueis[] = {1850, 1200, 2400, 980, 1450, 2050, 3100, 1600, 1300};
    int n = 9;

    int mediana = quickselect(alugueis, n, n / 2);
    printf("aluguel mediano: R$ %d\n", mediana);
    return 0;
}
// Saída:
// pivô 1300 na posição 2: 1200 980 1300 1850 1450 2050 3100 1600 2400  -> segue à direita
// pivô 2400 na posição 7: 1850 1450 2050 1600 2400 3100  -> segue à esquerda
// pivô 1600 na posição 4: 1450 1600 2050 1850  -> achou
// aluguel mediano: R$ 1600
```

Foram 8 + 5 + 3 = 16 comparações. Com 9 elementos a economia é pequena (o
quick sort completo faz 18 neste vetor), mas ela cresce com `n`. A conta
`n + n/2 + ...` supõe o pivô sempre no meio; com pivôs ao acaso, a média para
achar a mediana fica em torno de 3,4 `n`. Para um milhão de elementos, uns
3,4 milhões de comparações, contra mais de 20 milhões para ordenar.

Repara no fluxograma: diferente do quick sort, não há duas chamadas. Cada
volta do laço escolhe um lado e joga o outro fora:

{{fluxograma}}

> [!WARNING]
> Cuidado com o "k-ésimo". Em C, as posições começam em 0: o **menor** é
> `k = 0`, e "o 3º menor" é `k = 2`. Quem chama `quickselect(v, n, 3)`
> querendo o 3º menor recebe o 4º. E o quickselect **bagunça o vetor**: ele
> troca elementos de lugar a cada separação. Se você ainda precisa da ordem
> original (a ordem dos anúncios, por exemplo), passe uma cópia.

> [!TIP]
> **Por dentro do C:** a versão com `while` usa memória extra O(1): só `p`,
> `r`, `j` e as variáveis do `separa`, na pilha. Uma versão recursiva, que
> chama `quickselect` num dos lados, é **recursão de cauda** (a chamada é a
> última coisa que a função faz), e o gcc com `-O2` costuma transformá-la
> num laço sozinho. Mas sem otimização (o `rodar` compila sem `-O2`), cada
> chamada é um frame novo, e no pior caso são `n` frames. Escrever o laço à
> mão não depende da boa vontade do compilador.

> [!NOTE]
> **Pergunta para você:** o que acontece se você pedir a mediana de um vetor
> que **já está em ordem** crescente, com 10.001 elementos? Quantas
> separações o quickselect faz, com o pivô sempre no fim? E se o pivô for
> sorteado?

{{pratique}}
