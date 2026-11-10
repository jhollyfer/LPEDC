## 0120 · Counting sort

A dona da lanchonete quer 8 avaliações (A a H, com 3, 1, 3, 2, 1, 4, 0 e 3
estrelas) em ordem de nota. Ela faz cinco montes, um por nota, e junta os
montes do 0 ao 4, sem comparar pedido com pedido.

O assunto 0117 mostrou que a ordenação **por comparação** faz uns n log₂ n
testes no pior caso. O **counting sort** (ordenação por contagem) escapa desse
piso porque usa o **valor** da chave como **índice** de um vetor. As chaves
precisam ser inteiros num intervalo pequeno, de 0 a k - 1. São três laços:

1. **contar**: `c[x]` recebe quantos elementos têm a chave `x`;
2. **acumular**: `c[x]` passa a valer quantos têm chave **menor ou igual** a
   `x`, ou seja, onde termina o bloco de `x` na saída (as três avaliações de
   3 estrelas ocupam as posições 4, 5 e 6, porque 7 têm até 3 estrelas);
3. **distribuir**: percorra a entrada **de trás para a frente** e ponha cada
   elemento na última vaga livre do seu bloco: `c[x]--` e
   `saida[c[x]] = v[i]`.

Entre chaves iguais, quem vem por último na entrada ocupa a última vaga: a
ordem dos empates se mantém e o método é **estável**, o que o radix sort
(próximo assunto) aproveita. O custo é Θ(n + k), ou Θ(n) quando k = O(n). No
desenho, os pedidos de 3 estrelas (A, C e H, em verde) chegam à saída na ordem
original:

{{ideia}}

O counting sort não ordena no lugar: a saída vai para outro vetor.

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

No fim, cada `c[x]` aponta para o **começo** do bloco de `x`. Os três laços
são sequenciais: dois andam pelos n elementos e um pelas k chaves, então o
custo é **O(n + k)**:

{{fluxograma}}

> [!WARNING]
> Com o terceiro laço da frente para trás, os empates saem **invertidos**
> (H3 C3 A3), sem erro algum. A chave também tem que caber no vetor: a nota 5
> ou -1 vira `c[5]` ou `c[-1]`, escrita fora do vetor.

> [!TIP]
> **Por dentro do C:** o counting sort troca memória por tempo: `k`
> contadores mais um vetor de saída com `n` elementos. Com chaves de 0 a 1
> bilhão, `c` teria 4 GB e o `k` domina o custo. Use-o quando `k` for da ordem
> de `n` ou menor.

> [!NOTE]
> **Pergunta para você:** sem o código do pedido, dá para pular a saída e o
> acumulado e escrever cada nota `c[x]` vezes. Por que essa versão curta não
> serve para ordenar as avaliações com o código junto?

{{pratique}}
