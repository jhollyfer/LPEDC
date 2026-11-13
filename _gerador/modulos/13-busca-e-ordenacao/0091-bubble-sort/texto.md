## 0091 · Bubble sort

- **Bubble sort** (ordenação por bolha): compara **vizinhos**, `v[j]` com
  `v[j + 1]`, e troca os dois se o da esquerda for maior. Cada varredura é
  uma **passada** (CELES; RANGEL, 2002).
- **O maior afunda**: a cada passada, o maior restante vai para a última
  gaveta livre. Por isso `n - 1` passadas bastam, e a passada `k` não olha
  as últimas `k - 1` gavetas (DEITEL; DEITEL, 2011, cap. 6).
- **Bandeira** (`bool trocou`): passada sem troca quer dizer vetor
  ordenado, e o laço para (CELES; RANGEL, 2002).
- **Custo**: no pior caso (vetor ao contrário), `n(n - 1)/2` comparações,
  todas viram trocas: **O(n²)**. No melhor caso, com bandeira, uma passada:
  **O(n)** (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **Inversão**: par na ordem errada. Cada troca de vizinhos desfaz uma; num
  vetor aleatório são cerca de `n²/4`. Serve para aprender, não para código
  real (CORMEN et al., 2024, cap. 2).

> [!WARNING]
> `v[j] = v[j + 1]; v[j + 1] = v[j];` não troca nada: os dois ficam iguais.
> Use uma variável auxiliar. Com `j < n` no laço interno, a última volta lê
> `v[n]`, fora do vetor.

{{exemplo}}

Cinco restaurantes prometem entregar em 42, 17, 35, 8 e 23 minutos. Na
passada 1 o 42 afunda até o fim; na 2, o 35 acha o seu lugar; na 3, o 8 chega
à frente. A passada 4 não troca nada e a bandeira encerra:

{{ideia}}

O código conta comparações e trocas:

```c
#include <stdio.h>
#include <stdbool.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void bubble_sort(int v[], int n) {
    int comparacoes = 0, trocas = 0;
    for (int passada = 1; passada < n; passada++) {
        bool trocou = false;
        // os últimos passada-1 já estão no lugar: nem olha
        for (int j = 0; j < n - passada; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {      // vizinhos fora de ordem: troca
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocas++;
                trocou = true;
            }
        }
        printf("passada %d:", passada);
        mostra(v, n);
        if (!trocou) {
            break;                      // nenhuma troca: já está ordenado
        }
    }
    printf("%d comparações, %d trocas\n", comparacoes, trocas);
}

int main(void) {
    int minutos[] = {42, 17, 35, 8, 23};
    int n = 5;

    printf("início:   ");
    mostra(minutos, n);
    bubble_sort(minutos, n);
    return 0;
}
// Saída:
// início:    42 17 35  8 23
// passada 1: 17 35  8 23 42
// passada 2: 17  8 23 35 42
// passada 3:  8 17 23 35 42
// passada 4:  8 17 23 35 42
// 10 comparações, 7 trocas
```

### Passo a passo

A passada 1 por dentro; em negrito, o par comparado:

| j | antes | `v[j] > v[j+1]`? | depois |
| --- | --- | --- | --- |
| 0 | **42 17** 35 8 23 | sim, troca | 17 42 35 8 23 |
| 1 | 17 **42 35** 8 23 | sim, troca | 17 35 42 8 23 |
| 2 | 17 35 **42 8** 23 | sim, troca | 17 35 8 42 23 |
| 3 | 17 35 8 **42 23** | sim, troca | 17 35 8 23 42 |

Nas quatro passadas: 4 + 3 + 2 + 1 = **10 comparações** e 4 + 2 + 1 + 0 =
**7 trocas**, o número de inversões do vetor original.

O laço de dentro (`j`) faz uma passada; o de fora repete enquanto a bandeira
indicar troca:

{{fluxograma}}
