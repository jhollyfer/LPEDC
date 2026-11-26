## 0120 · Counting sort

Todas as ordenações vistas até o módulo 17 são **ordenações por comparação**:
decidem a ordem só perguntando qual de duas chaves é menor. O assunto 0117
provou que elas fazem cerca de n log₂ n comparações no pior caso, e nenhuma
esperteza muda isso (CORMEN et al., 2024, cap. 8). Para ordenar mais rápido, é
preciso mudar a regra do jogo e usar alguma coisa além da comparação.

Pense na dona de uma lanchonete com uma pilha de avaliações, cada uma com nota
de 0 a 4 estrelas. Ela não compara avaliação com avaliação. Faz cinco montes,
um por nota, joga cada avaliação no monte da sua nota e no fim junta os montes
do 0 ao 4. A nota diz direto onde a avaliação vai. Esse é o **counting sort**,
ou ordenação por contagem: ele usa o **valor** da chave como **índice** de um
vetor de contadores (CORMEN et al., 2024, cap. 8). Para isso funcionar, as
chaves precisam ser inteiros num intervalo pequeno, de `0` a `k - 1`.

O algoritmo tem três laços, e cada um faz uma coisa simples. O primeiro
**conta**: percorre a entrada e, para cada chave `x`, soma 1 em `c[x]`. No fim,
`c[x]` diz quantos elementos têm a chave `x`. Com 8 avaliações de notas 3, 1,
3, 2, 1, 4, 0 e 3, o vetor fica `c = {1, 2, 1, 3, 1}`.

O segundo laço **acumula**: cada `c[x]` passa a valer a soma dele com todos os
anteriores, ou seja, quantos elementos têm chave **menor ou igual** a `x`. O
vetor do exemplo vira `{1, 3, 4, 7, 8}`. Esse número diz onde termina o bloco
de cada chave na saída: 7 avaliações têm até 3 estrelas, então as três de 3
estrelas ocupam as posições 4, 5 e 6 (CORMEN et al., 2024, cap. 8).

O terceiro laço **distribui**. Ele percorre a entrada **de trás para a frente**
e, para cada elemento de chave `x`, faz `c[x]--` e grava o elemento em
`saida[c[x]]`, a última vaga livre do bloco de `x`. O decremento faz o próximo
elemento com a mesma chave ocupar a vaga logo antes.

Andar de trás para a frente tem um motivo. O último elemento de chave `x` na
entrada pega a última vaga do bloco, o penúltimo pega a anterior, e assim por
diante. Entre chaves iguais, a ordem da entrada se mantém, e por isso o
counting sort é **estável** (SEDGEWICK; WAYNE, 2011). Isso importa quando a
chave vem junto com outros dados, como o código da avaliação, e importa ainda
mais para o radix sort do assunto 0121, que depende dessa propriedade.

O custo é Θ(n + k): os laços que andam pela entrada fazem `n` passos, e o que
acumula faz `k`. Quando `k` é da ordem de `n` ou menor, o total é Θ(n), linear
(CORMEN et al., 2024, cap. 8). O preço é memória. O counting sort não ordena
no lugar: precisa de `k` contadores e de um vetor de saída com `n` elementos
(LINTZMAYER; MOTA, 2023). Com chaves de 0 a 1 bilhão, o vetor `c` teria 4 GB,
e o `k` dominaria tudo. Por isso ele só vale para chaves num intervalo curto.

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
