## 0120 · Counting sort

- **Ordenação por comparação**: decide a ordem só comparando pares de chaves.
  No pior caso faz cerca de n log₂ n comparações (assunto 0117)
  (CORMEN et al., 2024, cap. 8).
- **Counting sort** (ordenação por contagem): usa o **valor** da chave como
  **índice** de um vetor de contadores e por isso escapa desse piso. As chaves
  são inteiros de 0 a k - 1 (CORMEN et al., 2024, cap. 8).
- **Três laços**: **contar** (`c[x]` = quantos têm chave `x`), **acumular**
  (`c[x]` = quantos têm chave menor ou igual a `x`, o fim do bloco de `x`) e
  **distribuir** (de trás para a frente, `c[x]--` e `saida[c[x]] = v[i]`)
  (CORMEN et al., 2024, cap. 8).
- **Estável**: entre chaves iguais, a ordem da entrada se mantém. O radix sort
  (assunto 0121) depende disso (SEDGEWICK; WAYNE, 2011).
- **Custo**: Θ(n + k) de tempo, e memória para `k` contadores mais a saída de
  `n` elementos. Vale a pena quando `k` é da ordem de `n` ou menor
  (CORMEN et al., 2024, cap. 8).
- **Não ordena no lugar**: o resultado vai para outro vetor
  (LINTZMAYER; MOTA, 2023).

> [!WARNING]
> Com o terceiro laço da frente para trás, os empates saem **invertidos**, sem
> erro. E a chave tem que caber em `c`: a nota 5 ou -1 vira `c[5]` ou `c[-1]`,
> escrita fora do vetor.

{{exemplo}}

Oito avaliações de uma lanchonete (A a H, de 0 a 4 estrelas) vão para a ordem
de nota. Os pedidos de 3 estrelas (A, C e H, em verde) chegam à saída na ordem
original:

{{ideia}}

```c
#include <stdio.h>

#define K 5 // estrelas vão de 0 a 4

typedef struct {
    char codigo; // pedido 'A', 'B', ...
    int estrelas;
} Avaliacao;

void mostra(const char *rotulo, const int c[]) {
    printf("%-10s", rotulo);
    for (int x = 0; x < K; x++) {
        printf(" %d", c[x]);
    }
    printf("\n");
}

// ordena v pelas estrelas, de forma estável, e grava o resultado em saida
void counting_sort(const Avaliacao v[], Avaliacao saida[], int n) {
    int c[K] = {0};
    for (int i = 0; i < n; i++) {
        c[v[i].estrelas]++;              // 1) conta cada valor
    }
    mostra("contagem:", c);
    for (int x = 1; x < K; x++) {
        c[x] += c[x - 1];                // 2) c[x] = quantos têm <= x
    }
    mostra("acumulado:", c);
    for (int i = n - 1; i >= 0; i--) {   // 3) de trás para a frente
        int x = v[i].estrelas;
        c[x]--;
        saida[c[x]] = v[i];              // última vaga livre do bloco x
    }
}

int main(void) {
    Avaliacao v[] = {{'A', 3}, {'B', 1}, {'C', 3}, {'D', 2},
                     {'E', 1}, {'F', 4}, {'G', 0}, {'H', 3}};
    Avaliacao saida[8];
    int n = 8;

    counting_sort(v, saida, n);
    printf("ordenado: ");
    for (int i = 0; i < n; i++) {
        printf(" %c%d", saida[i].codigo, saida[i].estrelas);
    }
    printf("\n");
    return 0;
}
// Saída:
// contagem:  1 2 1 3 1
// acumulado: 1 3 4 7 8
// ordenado:  G0 B1 E1 D2 A3 C3 H3 F4
```

Os três laços são sequenciais: dois andam pelos n elementos e um pelas k
chaves, então o custo é **O(n + k)**:

{{fluxograma}}

### Passo a passo

O terceiro laço, com o acumulado `1 3 4 7 8` no começo. Cada linha usa uma
vaga e diminui o contador da nota:

| i | pedido | c[x] antes | vai para | c depois |
| --- | --- | --- | --- | --- |
| 7 | H3 | c[3] = 7 | saida[6] | 1 3 4 6 8 |
| 6 | G0 | c[0] = 1 | saida[0] | 0 3 4 6 8 |
| 5 | F4 | c[4] = 8 | saida[7] | 0 3 4 6 7 |
| 4 | E1 | c[1] = 3 | saida[2] | 0 2 4 6 7 |
| 3 | D2 | c[2] = 4 | saida[3] | 0 2 3 6 7 |
| 2 | C3 | c[3] = 6 | saida[5] | 0 2 3 5 7 |
| 1 | B1 | c[1] = 2 | saida[1] | 0 1 3 5 7 |
| 0 | A3 | c[3] = 5 | saida[4] | 0 1 3 4 7 |

No fim, cada `c[x]` aponta para o **começo** do bloco de `x`.
