## 0103 · Heapsort

Os tempos da corrida de rua, em minutos, chegaram nesta ordem: 52, 18, 73, 40,
91, 25 e 66. Você quer o ranking crescente, no próprio vetor, sem alocar outro.

O heap tira o maior em O(log n). Tire os n elementos e eles saem em ordem
decrescente: é o **heapsort**. No **mesmo vetor**: a cada máximo que sai, o
heap encolhe uma casa, e essa casa livre no fim é a posição final do máximo.

Duas fases:

1. **Construir o heap** no vetor. É mais barato fazer cada **pai** descer, do
   último (`n / 2 - 1`) até a raiz, porque as folhas já são heaps: só O(n).
   É a `BUILD-MAX-HEAP` do Cormen.
2. **Ordenar**: troque a raiz (o máximo) com o último elemento do heap, que
   fica no lugar definitivo. Encolha o heap em uma casa e faça a nova raiz
   descer. Repita até restar um elemento.

Na fase 2, o vetor tem o **heap** no começo e a parte **ordenada** no fim.

A fase 1 é O(n) e a fase 2 faz n - 1 descidas de no máximo log₂ n níveis:
O(n log n) **sempre**. O quick sort (assunto 0095) pode cair em O(n²); o merge
sort (0094) precisa de vetor extra. O heapsort garante n log n sem memória
extra.

Depois da fase 1, o vetor é o heap `[91 52 73 40 18 25 66]`. Na fase 2, o 91
troca com o 66 e fica no fim, em verde. O 66 desce pelo maior filho (73):

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

> [!WARNING]
> Na fase 2, o `desce` recebe o tamanho **do heap** (`fim`), não o do vetor
> (`n`). Com `desce(v, n, 0)`, a raiz trata os elementos já ordenados como
> filhos e desfaz o trabalho. O vetor sai embaralhado sem aviso: os índices
> continuam válidos.

> [!TIP]
> O heapsort é **in-place** (O(1) de memória, sem recursão) e **não é
> estável**. O quick sort costuma ganhar por usar melhor o cache.

> [!NOTE]
> **Pergunta para você:** o exemplo A206 ordena mil números em ordem
> decrescente com insertion sort e com heapsort. Quantas comparações cada um
> faz? E se o vetor já estivesse em ordem crescente, qual ganharia?

{{pratique}}
