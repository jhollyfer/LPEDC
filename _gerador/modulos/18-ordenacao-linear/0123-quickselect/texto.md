## 0123 · Quickselect

- **Seleção**: achar o **k-ésimo menor** de um vetor sem ordenar tudo. O
  mínimo é `k = 0`; a **mediana** é `k = n / 2` (CORMEN et al., 2024, cap. 9).
- **Quickselect**: separa o vetor em torno de um pivô (assunto 0095), como o
  quick sort, mas segue **um lado só** (HOARE, 1961).
- **Regra do lado**: com o pivô na posição final `j`, se `j == k` achou; se
  `k < j`, segue à esquerda; se `k > j`, segue à direita. Um `while` que
  encolhe `[p, r]` basta (FEOFILOFF, 2009).
- **Custo médio**: com o pivô perto do meio, `n + n/2 + n/4 + ...` < `2n`, logo
  O(n). Com o pivô sempre no extremo, O(n²)
  (CORMEN et al., 2024, cap. 9).
- **`RANDOMIZED-SELECT`**: a versão com pivô sorteado; o esperado é O(n)
  (CORMEN et al., 2024, cap. 9).
- **`SELECT`** (mediana das medianas): escolhe um pivô bom o bastante para
  garantir O(n) no **pior** caso (BLUM et al., 1973).
- **Memória**: a versão com `while` usa O(1) extra. A recursiva é de cauda; o
  gcc com `-O2` costuma virar laço, sem ele o pior caso empilha `n` chamadas
  (SEDGEWICK, 1998, cap. 7).

> [!WARNING]
> As posições começam em 0: "o 3º menor" é `k = 2`, e `quickselect(v, n, 3)`
> devolve o 4º. O quickselect também **bagunça o vetor**: para manter a ordem
> original, passe uma cópia.

{{exemplo}}

Nove aluguéis anotados, de R$ 980 a R$ 3100; o típico é a mediana. O pivô
1300 cai na posição 2, e a mediana (posição 4) está à direita: os três
primeiros nunca mais são lidos.

{{ideia}}

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

Foram 8 + 5 + 3 = 16 comparações (o quick sort completo faz 18). Cada volta do
laço escolhe um lado e descarta o outro:

{{fluxograma}}
