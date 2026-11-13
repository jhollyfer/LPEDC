## 0103 · Heapsort

- **Heapsort**: ordena tirando o máximo do heap n vezes. Tudo no **mesmo
  vetor**: o heap encolhe uma casa a cada máximo, e essa casa livre no fim é o
  lugar final dele (CORMEN et al., 2024, cap. 6).
- **Fase 1, construir o heap**: cada **pai** desce, do último (`n / 2 - 1`)
  até a raiz. As folhas já são heaps, e a fase custa só O(n). É a
  `BUILD-MAX-HEAP` do Cormen (CORMEN et al., 2024, cap. 6).
- **Fase 2, ordenar**: troca a raiz com o último do heap, encolhe o heap e faz
  a nova raiz descer. O vetor fica com o heap no começo e a parte ordenada no
  fim (FEOFILOFF, 2009).
- **Custo**: n - 1 descidas de no máximo log₂ n níveis, O(n log n)
  **sempre**. O quick sort (0095) pode cair em O(n²) e o merge sort (0094)
  precisa de vetor extra (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **In-place e não estável**: usa O(1) de memória, sem recursão, mas pode
  trocar a ordem de chaves iguais. Na prática o quick sort costuma ser mais
  rápido (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).

> [!WARNING]
> Na fase 2, o `desce` recebe o tamanho **do heap** (`fim`), não o do vetor
> (`n`). Com `desce(v, n, 0)`, a raiz trata os já ordenados como filhos e
> desfaz o trabalho, sem aviso: os índices continuam válidos.

{{exemplo}}

Os tempos da corrida de rua chegaram como 52, 18, 73, 40, 91, 25 e 66. Depois
da fase 1, o heap é `[91 52 73 40 18 25 66]`. O 91 troca com o 66 e fica no
fim, em verde; o 66 desce pelo maior filho (73):

{{ideia}}

O `desce` é o do heap, com o tamanho atual do heap como parâmetro. A `mostra`
separa o heap da parte ordenada com `|`:

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// mostra o heap (v[0..fim-1]) e a parte já ordenada, separados por |
void mostra(const char *rotulo, const int v[], int n, int fim) {
    printf("%-12s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(i == fim ? " | %d" : " %d", v[i]);
    }
    printf("\n");
}

// desce v[i] dentro do heap v[0..n-1], trocando com o maior filho
void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(int v[], int n) {
    // fase 1: transforma o vetor em heap, do último pai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    mostra("heap:", v, n, n);
    // fase 2: o máximo vai para o fim; o heap encolhe uma casa
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
        mostra("", v, n, fim);
    }
}

int main(void) {
    int tempos[] = {52, 18, 73, 40, 91, 25, 66}; // minutos de cada corredor
    int n = 7;

    mostra("antes:", tempos, n, n);
    heapsort(tempos, n);
    return 0;
}
// Saída:
// antes:       52 18 73 40 91 25 66
// heap:        91 52 73 40 18 25 66
//              73 52 66 40 18 25 | 91
//              66 52 25 40 18 | 73 91
//              52 40 25 18 | 66 73 91
//              40 18 25 | 52 66 73 91
//              25 18 | 40 52 66 73 91
//              18 | 25 40 52 66 73 91
```

No fluxograma, a fase 1 é uma caixa só, e o laço da fase 2 repete trocar e
descer até `fim` chegar a 0:

{{fluxograma}}

### Passo a passo

A fase 1. Os pais são os índices 2, 1 e 0 (`n / 2 - 1 = 2`):

| Pai que desce | Filhos | O que acontece | Vetor |
| --- | --- | --- | --- |
| `v[2] = 73` | 25 e 66 | 73 já é o maior: fica | `52 18 73 40 91 25 66` |
| `v[1] = 18` | 40 e 91 | troca com o 91 | `52 91 73 40 18 25 66` |
| `v[0] = 52` | 91 e 73 | troca com o 91; depois, filhos 40 e 18: fica | `91 52 73 40 18 25 66` |
