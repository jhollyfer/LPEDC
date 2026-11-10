## 0163 · Skip list

A rodovia tem paradas nos km 5, 12, 18, 23, 31, 40, 47 e 56. O **parador**
para em todas, o **semidireto** em algumas, o **direto** só nas principais.
Para o km 47, você vai de direto até onde der, troca para o semidireto e só
no fim pega o parador.

Uma lista ordenada (assunto 0078) é o ônibus parador: achar uma chave custa
O(n), e a busca binária não serve, pois lista não tem índice. A BST e a AVL
(módulo 14) resolvem com rotações.

A **skip list** fica com a lista e acrescenta as linhas expressas, os
**andares**. O andar 0 é a lista completa; o andar 1 tem parte dos nós, o 2
menos ainda. Cada nó tem um vetor `prox`: `prox[k]` é o próximo no andar `k`.
Uma **cabeça** sem chave está em todos os andares e começa toda busca.

**Buscar** é a viagem de ônibus. Comece no andar mais alto da cabeça. Se o
próximo nó do andar é menor que a chave, avance; se já passou (ou não existe),
desça. No andar 0, o próximo nó é a chave ou ela não existe.

Os andares de cada nó saem de uma **moeda**: todo nó novo entra no andar 0 e,
enquanto der cara, sobe mais um. Em média, metade chega ao andar 1, um quarto
ao 2, um oitavo ao 3, sem nunca arrumar nada.

**Inserir** é buscar guardando, em cada andar, o último nó visitado antes de
descer (o vetor `antes`). Sorteie os andares do nó novo e ligue-o depois de
`antes[k]` em cada andar `k`. A remoção usa o mesmo vetor para desligar o nó.

O custo é **O(log n) esperado**: com 1 milhão de chaves, uns 40 nós olhados
por busca, contra meio milhão na lista simples. "Esperado" é na média dos
sorteios, sem garantia.

As paradas entram com os andares sorteados: o 23 e o 56 em 3 andares, o 12 e
o 40 em 2, os outros só no 0. A busca pelo 47 anda no andar 2 até o 23 (o 56
já passou), desce, anda até o 40, desce, e o próximo no andar 0 é o 47:

{{ideia}}

O TAD fica em `skip.h` e `skip.c`. O nó e a busca:

```c
#define SKIP_MAX 12 // andares no máximo: dá para uns 4 mil nós (2 elevado a 12)

typedef struct NoSkip {
    int chave;
    int andares;                   // em quantos andares o nó aparece
    struct NoSkip *prox[SKIP_MAX]; // prox[k]: o próximo no andar k
} NoSkip;

bool skip_busca(const Skip *s, int chave, int *passos) {
    int olhados = 0;
    const NoSkip *x = &s->cabeca;
    for (int k = s->andares - 1; k >= 0; k--) { // do andar mais alto ao 0
        while (x->prox[k] != NULL) {
            olhados++;
            if (x->prox[k]->chave >= chave) {
                break; // o próximo já passou (ou é a chave): desce
            }
            x = x->prox[k]; // o próximo ainda é menor: avança
        }
    }
    if (passos != NULL) {
        *passos = olhados;
    }
    x = x->prox[0]; // no andar 0, o próximo é a chave ou ela não existe
    return x != NULL && x->chave == chave;
}
```

Para o desenho sair igual em toda execução, o exemplo usa
`skip_insere_andares`, com andares prontos; no uso normal, `skip_insere` joga
a moeda. O `skip_mostra` imprime cada chave sempre na mesma coluna:

```c
#include <stdio.h>
#include "skip.h"

void procura(const Skip *s, int km) {
    int passos;
    bool achou = skip_busca(s, km, &passos);
    printf("km %d: %s, %d nós olhados\n", km, achou ? "tem parada" : "não tem parada", passos);
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3}; // o que a moeda "deu"
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    skip_mostra(linha);
    procura(linha, 47);
    procura(linha, 20);

    skip_libera(linha);
    return 0;
}
// Saída:
// andar 2:              23              56
// andar 1:      12      23      40      56
// andar 0:   5  12  18  23  31  40  47  56
// km 47: tem parada, 5 nós olhados
// km 20: não tem parada, 5 nós olhados
```

O laço de dentro avança no andar, o de fora desce. O caminho verde é a busca
do 47: uma vez no andar 2, uma no andar 1, nenhuma no andar 0:

{{fluxograma}}

> [!WARNING]
> Na remoção, o nó sai de **todos** os andares em que aparece. Se o 23 sair só
> do andar 0 e for liberado, a cabeça continua apontando para ele no andar 2:
> ponteiro solto (assunto 0057). O E976 pede essa remoção.

> [!TIP]
> Com `prox[SKIP_MAX]`, todo nó ocupa 104 bytes mesmo usando em média 2
> ponteiros. Um **membro vetor flexível**, `struct NoSkip *prox[];`, com
> `malloc(sizeof(NoSkip) + andares * sizeof(NoSkip *))`, aloca só o
> necessário.

> [!NOTE]
> **Pergunta para você:** se o km 35 entrar com 2 andares, quais ponteiros
> mudam? Quem fica em `antes[0]` e em `antes[1]`? Desenhe antes de conferir com
> `skip_insere_andares` e `skip_mostra`.

{{pratique}}
