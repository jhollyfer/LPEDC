## 0091 · Bubble sort

No app de delivery, cinco restaurantes prometem entregar em 42, 17, 35, 8 e 23
minutos. Para mostrá-los do mais rápido ao mais lento, o vetor precisa estar
**ordenado**.

O **bubble sort** (ordenação por bolha) compara **vizinhos**, `v[j]` com
`v[j + 1]`, e troca os dois se o da esquerda for maior. Uma varredura é uma
**passada**.

Em cada passada, o maior elemento vai parar na última gaveta. Daí vêm duas
regras:

- **n - 1 passadas bastam**: com os `n - 1` maiores no lugar, o que sobra já
  está na frente;
- a passada `k` não olha as últimas `k - 1` gavetas: o laço interno vai até
  `j < n - passada`.

A **bandeira** (`bool trocou`) dá uma terceira: passada sem troca significa
vetor ordenado, e o laço para.

No pior caso (vetor ao contrário), são `(n - 1) + (n - 2) + ... + 1 =
n(n - 1)/2` comparações, todas viram trocas: **O(n²)**. No melhor caso (vetor
em ordem, com bandeira), uma passada de `n - 1` comparações: **O(n)**.

Na passada 1 o 42 afunda até o fim (verde). Na 2, o 35 acha o seu lugar. Na
3, o 8 chega à frente. A passada 4 não troca nada e a bandeira encerra:

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

Somando as quatro passadas: 4 + 3 + 2 + 1 = **10 comparações** e
4 + 2 + 1 + 0 = **7 trocas**. Esse 7 é o número de **inversões** do vetor
original, os pares na ordem errada (42 com 17, 35, 8 e 23; 17 com 8; 35 com 8
e 23). Cada troca de vizinhos desfaz uma inversão.

O laço de dentro (`j`) faz uma passada; o de fora repete enquanto a bandeira
indicar troca:

{{fluxograma}}

> [!WARNING]
> `v[j] = v[j + 1]; v[j + 1] = v[j];` não troca nada: os dois ficam iguais.
> Use uma variável auxiliar. Com `j < n` no laço interno, a última volta lê
> `v[n]`, fora do vetor.

> [!TIP]
> O bubble faz uma troca por inversão (cerca de `n²/4` num vetor aleatório):
> serve para aprender, não para código real.

> [!NOTE]
> **Pergunta para você:** quantas passadas o bubble com bandeira faz no vetor
> `8 17 23 35 42`, que já está ordenado? E em `17 23 35 42 8`, com o menor no
> fim?

{{pratique}}
