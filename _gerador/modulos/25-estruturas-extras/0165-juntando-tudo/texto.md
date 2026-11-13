## 0165 · Juntando tudo

Uma loja virtual tem 1000 produtos e recebe 10 mil consultas por dia. Os 20
produtos da promoção levam 80% delas. Qual estrutura deve guardar o
catálogo? O módulo e os anteriores deixaram quatro candidatas, cada uma com
uma promessa diferente, e a pergunta só se responde medindo.

A **BST** (assunto 0099) busca em tempo proporcional à altura, e a altura
depende da ordem em que as chaves chegam: chaves embaralhadas dão uma árvore
baixa, chaves em ordem dão uma árvore que é uma lista. A **AVL** (0101)
garante altura perto de log₂ n, à custa de rotações a cada inserção. A
**skip list** (0163) promete O(log n) esperado, sem rotação nenhuma, porque
a forma dela vem da moeda e não da ordem de chegada (PUGH, 1990). A **lista
com mover para a frente** (0164) custa O(n) no pior caso, mas aposta que os
itens mais procurados vão ficar no começo.

Comparar estruturas exige uma medição justa, e justa quer dizer que só a
estrutura muda. Todas recebem **as mesmas chaves, na mesma ordem**. Todas
respondem **às mesmas buscas**, sorteadas uma vez e guardadas num vetor. E
todas usam o mesmo **custo**: o número de chaves que a busca comparou, que
não depende da máquina. Se uma dessas três coisas variar, a diferença no
resultado pode vir dela, não da estrutura.

Para o programa que mede não precisar conhecer cada estrutura, elas ficam
atrás de uma **interface comum**: uma struct de ponteiros para função
(assunto 0050), uma para cada operação, com a estrutura de dados passada
como `void *` (assunto 0051), o ponteiro genérico que aponta para qualquer
coisa (KERNIGHAN; RITCHIE, 1989):

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

Quem mede chama `e->busca(d, chave, &custo)` sem saber o que há do outro
lado: pode ser uma árvore, uma skip list ou uma lista. Para acrescentar um
concorrente, basta pôr mais uma struct no vetor `CONCORRENTES`; o teste não
muda.

Essa flexibilidade tem um custo pequeno. `e->busca(d, ...)` é uma
**chamada indireta**: o programa só descobre qual função chamar na hora,
lendo o ponteiro. Por isso o compilador em geral não consegue copiar o
corpo da função no lugar da chamada, e cada busca paga um salto a mais. Esse
salto não aparece na contagem de chaves comparadas; só um cronômetro o vê.

O resultado da medição confirma a teoria. Com as chaves em ordem crescente,
como num catálogo exportado de uma planilha ordenada, a BST vira lista e
passa de 500 comparações por busca. A AVL e a skip list nem percebem a
diferença entre as duas ordens. A lista com mover para a frente perde: os
20% de consultas espalhadas pelos outros produtos custam centenas de
comparações cada. O A329 mostra em que ponto o jogo vira a favor dela.

> [!WARNING]
> Gerar as buscas **dentro** da função que mede estraga a comparação: o
> sorteio continua de onde parou, e cada concorrente recebe consultas
> diferentes. Sorteie uma vez, antes, e guarde num vetor.

{{exemplo}}

Uma loja tem 1000 produtos e 10 mil consultas por dia, 80% delas nos 20 da
promoção. Cada concorrente recebe as chaves embaralhadas e em ordem crescente e
responde às mesmas consultas:

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
