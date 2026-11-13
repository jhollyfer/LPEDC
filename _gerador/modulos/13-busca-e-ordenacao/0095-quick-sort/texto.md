## 0095 · Quick sort

- **Quick sort**: escolhe um **pivô**, separa o pedaço em `menores ou iguais
  | pivô | maiores` e ordena cada lado com o próprio quick sort. Criado por
  Tony Hoare em 1960 (CORMEN et al., 2024, cap. 7).
- **Separação** (ou **partição**): rearranja o pedaço e deixa o pivô na sua
  posição **final**, `j`. As chamadas seguintes são em `v[p..j-1]` e
  `v[j+1..r]` (FEOFILOFF, 2009).
- **Lomuto** (a `PARTITION` do Cormen): pivô `v[r]`; `k` anda pelo pedaço e
  `j` marca a fronteira dos `<=` pivô. No fim, troca o pivô com `v[j]`
  (CORMEN et al., 2024, cap. 7).
- **Hoare**: dois índices vindos das pontas, que trocam os que estão do lado
  errado (ZIVIANI, 2010, cap. 4).
- **Ao contrário do merge**: o trabalho está em dividir, e juntar é de graça.
  Não precisa de rascunho (FEOFILOFF, 2009).
- **Custo**: com o pivô perto do meio, **O(n log n)**; sempre o menor ou o
  maior, **O(n²)**, como no vetor **já ordenado** com pivô no fim. Na média,
  O(n log n). Não é estável (CORMEN et al., 2024, cap. 7).
- **Pilha**: no pior caso a recursão desce `n` níveis. Defesas: **mediana de
  três** como pivô e recursão só no lado **menor**, no máximo `log₂ n` níveis
  (FEOFILOFF, 2009).

> [!WARNING]
> Com `quick_sort(v, p, j)`, o pivô entra de novo no pedaço da esquerda. Se é
> o maior (`j == r`), a chamada recebe o mesmo pedaço e nunca para: estouro de
> pilha. As chamadas precisam bater com o que a separação promete sobre `j`.

{{exemplo}}

Black Friday: 7 fones de R$ 35, 12, 48, 7, 29, 51 e 20. O 20 (roxo) é o pivô:
separa o vetor e fica verde, no lugar. Cada lado escolhe o seu pivô:

{{ideia}}

Em C:

```c
#include <stdio.h>

static int comparacoes = 0;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// separa v[p..r] em torno do pivô v[r]: menores ou iguais à esquerda,
// maiores à direita. Devolve a posição final do pivô.
int separa(int v[], int p, int r) {
    int pivo = v[r];
    int j = p;                          // v[p..j-1] são os <= pivô
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);                // o pivô vai para o meio deles
    return j;
}

// ordena v[p..r] (intervalo fechado)
void quick_sort(int v[], int p, int r) {
    if (p >= r) {
        return;                         // 0 ou 1 elemento
    }
    int j = separa(v, p, r);
    printf("pivô %d foi para a posição %d:", v[j], j);
    for (int i = p; i <= r; i++) printf(" %d", v[i]);
    printf("\n");
    quick_sort(v, p, j - 1);            // o pivô já está no lugar:
    quick_sort(v, j + 1, r);            // fica fora das duas chamadas
}

int main(void) {
    int precos[] = {35, 12, 48, 7, 29, 51, 20};
    int n = 7;

    quick_sort(precos, 0, n - 1);
    printf("resultado:");
    for (int i = 0; i < n; i++) printf(" %d", precos[i]);
    printf("\n%d comparações\n", comparacoes);
    return 0;
}
// Saída:
// pivô 20 foi para a posição 2: 12 7 20 35 29 51 48
// pivô 7 foi para a posição 0: 7 12
// pivô 48 foi para a posição 5: 35 29 48 51
// pivô 29 foi para a posição 3: 29 35
// resultado: 7 12 20 29 35 48 51
// 11 comparações
```

### Passo a passo

A primeira separação, com pivô 20. `k` anda; `j` marca onde entra o próximo
"pequeno":

| k | v[k] | `v[k] <= 20`? | ação | vetor | j |
| --- | --- | --- | --- | --- | --- |
| | | | | 35 12 48 7 29 51 **20** | 0 |
| 0 | 35 | não | nada | 35 12 48 7 29 51 20 | 0 |
| 1 | 12 | sim | troca v[0] e v[1] | 12 35 48 7 29 51 20 | 1 |
| 2 | 48 | não | nada | 12 35 48 7 29 51 20 | 1 |
| 3 | 7 | sim | troca v[1] e v[3] | 12 7 48 35 29 51 20 | 2 |
| 4 | 29 | não | nada | 12 7 48 35 29 51 20 | 2 |
| 5 | 51 | não | nada | 12 7 48 35 29 51 20 | 2 |
| fim | | | troca v[2] e o pivô | 12 7 **20** 35 29 51 48 | 2 |

Seis comparações. Depois vêm `[12 7]` (1), `[35 29 51 48]` (3) e `[35 29]`
(1): **11 comparações**.

O pivô fica fora das duas chamadas, e por isso o problema sempre diminui:

{{fluxograma}}
