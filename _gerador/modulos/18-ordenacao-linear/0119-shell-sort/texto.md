## 0119 · Shell sort

O motorista da van recebe 10 pacotes fora da ordem de rota. No insertion sort,
o pacote 9, na quinta posição, precisa de quatro empurrões para chegar à
frente.

O **insertion sort** (assunto 0093) anda **uma casa por movimento**: num vetor
invertido, a conta vira n²/2. Em 1959, Donald Shell propôs andar de **h em
h**. O **shell sort** repete o insertion sort com saltos `h` cada vez
menores. A última rodada é sempre com `h = 1`, sobre um vetor **quase
ordenado**, caso em que o insertion sort é rápido.

Depois da rodada com salto `h`, o vetor está **h-ordenado**: cada fileira de
um elemento a cada `h` casas está em ordem. Com `h = 4`, são quatro insertion
sorts entrelaçados (posições 0, 4, 8; 1, 5, 9; 2, 6; 3, 7).

A sequência de **Knuth** é `h = 3h + 1`: 1, 4, 13, 40, 121, 364... Comece com o
maior salto abaixo de `n / 3` e divida por 3 a cada rodada. Com `n = 10`, os
saltos são 4 e 1.

Na primeira linha do desenho, cada cor é uma fileira de salto 4: três
movimentos deixam o vetor quase pronto.

{{ideia}}

Em C, o laço de dentro é o insertion sort do assunto 0093 com o `1` trocado
por `h`:

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

// insertion sort com saltos: os saltos seguem a sequência de Knuth
void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;                  // 1, 4, 13, 40, 121...
    }
    for (; h >= 1; h /= 3) {            // ..., 121, 40, 13, 4, 1
        int movimentos = 0;
        // insertion sort entre elementos que estão a h casas de distância
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];        // empurra h casas para a direita
                j -= h;
                movimentos++;
            }
            v[j] = x;
        }
        printf("h = %d:", h);
        mostra(v, n);
        printf("  (%d movimentos)\n", movimentos);
    }
}

int main(void) {
    int rotas[] = {62, 17, 85, 40, 9, 73, 28, 51, 94, 33};
    int n = 10;

    printf("início:");
    mostra(rotas, n);
    printf("\n");
    shell_sort(rotas, n);
    return 0;
}
// Saída:
// início: 62 17 85 40 9 73 28 51 94 33
// h = 4: 9 17 28 40 62 33 85 51 94 73  (3 movimentos)
// h = 1: 9 17 28 33 40 51 62 73 85 94  (6 movimentos)
```

São 9 movimentos; o insertion sort comum faria 21. O `h /= 3` desfaz o
`3 * h + 1`: 13 / 3 é 4 e 4 / 3 é 1. O laço para quando `h` vira 0.

{{fluxograma}}

### Passo a passo

A rodada com `h = 4`; cada `v[i]` se compara só com quem está 4, 8, ... casas
para trás:

| i | x | compara com | ação | vetor depois |
| --- | --- | --- | --- | --- |
| 4 | 9 | v[0] = 62 | 62 pula para v[4]; 9 vai para v[0] | 9 17 85 40 62 73 28 51 94 33 |
| 5 | 73 | v[1] = 17 | nada | 9 17 85 40 62 73 28 51 94 33 |
| 6 | 28 | v[2] = 85 | 85 pula para v[6]; 28 vai para v[2] | 9 17 28 40 62 73 85 51 94 33 |
| 7 | 51 | v[3] = 40 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 8 | 94 | v[4] = 62 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 9 | 33 | v[5] = 73, depois v[1] = 17 | 73 pula para v[9]; 33 vai para v[5] | 9 17 28 40 62 33 85 51 94 73 |

> [!WARNING]
> A última rodada **tem** que ser com `h = 1`: depois do `h = 4`, o 62 ainda
> está antes do 33. Sem o 1, o programa termina sem erro e com o vetor fora de
> ordem. Use `j >= h`, não `j > 0`, senão `v[j - h]` lê antes do vetor.

> [!TIP]
> **Por dentro do C:** o shell sort não usa memória extra. Com os saltos de
> Knuth, o pior caso é O(n^1,5); com `n/2, n/4, ..., 1` (os de Shell), é
> O(n²), porque posições pares e ímpares só se comparam na rodada final.

> [!NOTE]
> **Pergunta para você:** o shell sort é estável? Faça `5 3a 3b 1` (dois 3
> iguais) com saltos 2 e 1 no papel e veja em que ordem os 3 terminam.

{{pratique}}
