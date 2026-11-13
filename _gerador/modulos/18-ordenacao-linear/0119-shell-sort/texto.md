## 0119 · Shell sort

- **Shell sort**: insertion sort (assunto 0093) repetido com **saltos** `h`
  cada vez menores. O elemento anda `h` casas por movimento, não uma
  (SHELL, 1959).
- **Vetor h-ordenado**: cada fileira de elementos a `h` casas de distância
  está em ordem. Com `h = 4`, são quatro insertion sorts entrelaçados
  (KNUTH, 1998).
- **Rodada final**: sempre com `h = 1`. Ela pega um vetor **quase ordenado**,
  caso em que o insertion sort é rápido (ZIVIANI, 2010, cap. 4).
- **Sequência de Knuth**: `h = 3h + 1` (1, 4, 13, 40, 121...). Comece no maior
  salto abaixo de `n / 3` e divida por 3 a cada rodada (SEDGEWICK, 1998, cap. 6).
- **Custo**: com os saltos de Knuth, o pior caso é O(n^1,5). Com os saltos de
  Shell (`n/2, n/4, ..., 1`), é O(n²): pares e ímpares só se comparam no fim
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **Memória**: ordena no lugar, sem vetor extra. Não é **estável**: iguais
  podem trocar de ordem (ZIVIANI, 2010, cap. 4).

> [!WARNING]
> A última rodada **tem** que ser com `h = 1`; sem ela o vetor termina fora de
> ordem e sem erro. No laço de dentro, use `j >= h`, não `j > 0`, senão
> `v[j - h]` lê antes do vetor.

{{exemplo}}

O motorista da van recebe 10 pacotes fora da ordem de rota. Com `n = 10`, os
saltos são 4 e 1; cada cor do desenho é uma fileira de salto 4:

{{ideia}}

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
`3 * h + 1` e o laço para quando `h` vira 0:

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
