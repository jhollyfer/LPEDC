## 0165 · Juntando tudo

A loja tem 1000 produtos e 10 mil consultas por dia; os 20 da promoção levam
80% delas. Qual estrutura guarda o catálogo?

A **BST** (assunto 0099) tem altura que depende da ordem de chegada. A
**AVL** (0101) garante altura perto de log₂ n com rotações. A **skip list**
(0163) promete O(log n) esperado, sem rotação. A **lista com mover para a
frente** (0164) é O(n), mas aposta que os mais procurados ficam na frente. A
resposta sai de medir.

Três regras para medir com justiça: **as mesmas chaves, na mesma ordem**;
**as mesmas buscas**, sorteadas uma vez e guardadas num vetor; e o mesmo
**custo**, as chaves que a busca comparou.

As estruturas ficam atrás de uma **interface comum**: uma struct com
ponteiros para função (assunto 0050) e a estrutura de dados como `void *`
(0051). Quem mede chama `e->busca(d, chave, &custo)` sem saber o que há do
outro lado:

```c
typedef struct {
    const char *nome;
    void *(*cria)(void);
    void (*insere)(void *e, int chave);            // repetida é ignorada
    bool (*busca)(void *e, int chave, int *custo); // custo: chaves comparadas
    void (*libera)(void *e);
} Estrutura;

extern const Estrutura CONCORRENTES[NUM_CONCORRENTES];
```

O `bancada.c` traz os quatro concorrentes (a skip list é a do `skip.h`) e um
sorteio repetível, `bc_sorteio`, com o gerador de uma linha do `skip.c`.

Cada concorrente recebe as 1000 chaves duas vezes: embaralhadas e em ordem
crescente (o catálogo exportado de uma planilha ordenada). Depois responde às
mesmas 10 mil consultas:

{{ideia}}

O programa monta as duas ordens e as buscas, e a função `mede` faz o resto:

```c
#include <stdio.h>
#include "bancada.h"

#define N 1000       // produtos no catálogo
#define BUSCAS 10000 // consultas do dia
#define QUENTES 20   // os produtos da promoção

// insere as N chaves na ordem dada, faz as buscas e devolve o custo médio
double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado); // os QUENTES primeiros são a promoção

    // 80% das consultas vão para os 20 produtos da promoção
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        const Estrutura *e = &CONCORRENTES[k];
        printf("%-10s %12.1f %10.1f\n", e->nome, mede(e, embaralhada, buscas),
               mede(e, crescente, buscas));
    }
    return 0;
}
// Saída:
//             embaralhada  crescente
// BST               11.9      569.7
// AVL                8.9        9.1
// skip list         16.4       18.3
// lista MTF        114.6      114.5
```

O laço não sabe quem está medindo. Para acrescentar um concorrente, mexa no
vetor `CONCORRENTES`, nunca no teste:

{{fluxograma}}

A **BST** vai bem com chaves embaralhadas e desaba com a planilha ordenada:
vira lista, com mais de 500 comparações por busca. A **AVL** não percebe a
diferença; a **skip list** também não, porque a moeda decide a forma: olha
uns 18 nós contra uns 9 da AVL, sem rotação. A **lista MTF** perde feio: os
20% de consultas espalhadas custam umas 500 comparações. O A329 mostra quando
o jogo vira.

> [!WARNING]
> Gerar as buscas **dentro** de `mede` estraga a comparação: o sorteio continua
> de onde parou, e cada concorrente recebe consultas diferentes. Sorteie uma
> vez, antes, e guarde num vetor.

> [!TIP]
> `e->busca(d, ...)` é uma chamada **indireta**: o compilador em geral não a
> expande no lugar, e cada busca paga um salto a mais, visível só no
> cronômetro.

> [!NOTE]
> **Pergunta para você:** a coluna da lista MTF quase não muda entre as duas
> ordens. Por quê? Se a promoção tivesse 5 produtos e 99% das consultas, quem
> ganharia? Confira no A329.

{{pratique}}
