## 0123 · Quickselect

Você anotou 9 aluguéis: R$ 1850, 1200, 2400, 980, 1450, 2050, 3100, 1600 e
1300. O aluguel "típico" é a **mediana**, o valor do meio da lista em ordem.
Ordenar tudo arruma posições que ninguém pediu. O problema geral é a
**seleção**: achar o **k-ésimo menor** (a mediana é `k = n / 2`; o mínimo é
`k = 0`).

O **quickselect** (Hoare, 1961) usa a separação do assunto 0095. Depois de um
`separa`, o pivô está na posição **final** `j`, com menores à esquerda e
maiores à direita:

- se `j == k`, o pivô é a resposta;
- se `k < j`, a resposta está à **esquerda**, e a direita é descartada;
- se `k > j`, a resposta está à **direita**.

Ao contrário do quick sort, ele segue **um lado só**: um `while` que encolhe
o intervalo `[p, r]` basta (ideia do exercício E569, do módulo 13).

Com o pivô perto do meio, o custo é `n + n/2 + n/4 + ...`, menos que `2n`:
**O(n) em média**, contra O(n log n) de ordenar. Com o pivô sempre no maior ou
no menor, vira **O(n²)**. O Cormen chama a versão de pivô sorteado de
`RANDOMIZED-SELECT` e traz o `SELECT` (mediana das medianas, 1973), que
garante O(n) no pior caso.

Nos aluguéis, o pivô 1300 cai na posição 2, e a mediana (posição 4) está à
direita: os três primeiros nunca mais são lidos.

{{ideia}}

Em C:

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

Foram 8 + 5 + 3 = 16 comparações (o quick sort completo faz 18). Com pivôs ao
acaso, a mediana custa em torno de 3,4 `n` comparações. Cada volta do laço
escolhe um lado e descarta o outro:

{{fluxograma}}

> [!WARNING]
> As posições começam em 0: o **menor** é `k = 0`, e "o 3º menor" é `k = 2`.
> `quickselect(v, n, 3)` devolve o 4º. O quickselect também **bagunça o
> vetor**: para manter a ordem original, passe uma cópia.

> [!TIP]
> **Por dentro do C:** a versão com `while` usa memória extra O(1). A versão
> recursiva é **recursão de cauda**, que o gcc com `-O2` costuma transformar em
> laço. Sem `-O2`, cada chamada é um frame novo, e no pior caso são `n`.

> [!NOTE]
> **Pergunta para você:** quantas separações o quickselect faz para a mediana
> de um vetor **já em ordem** com 10.001 elementos, com o pivô sempre no fim?
> E com o pivô sorteado?

{{pratique}}
