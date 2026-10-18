// 0165 · Juntando tudo
// Exercício E990 · ★★★
//
// A lista MTF leva o achado para a frente. Dá para fazer o mesmo numa BST:
// depois de achar a chave, suba o nó até a RAIZ com rotações (as do assunto
// 0101), uma por nível. As chaves procuradas há pouco ficam perto do topo.
// Escreva esse concorrente, "para raiz":
// - insere: a inserção comum da BST, com laço (sem rotação);
// - busca: desce contando os nós comparados e, se achar, sobe o nó até a
//   raiz; se não achar, a árvore fica como está;
// - libera: solta todos os nós e a struct.
//
//   Saída esperada:
//               embaralhada  crescente
//   BST                11.9      569.7
//   AVL                 8.9        9.1
//   skip list          16.4       18.3
//   lista MTF         114.6      114.5
//   para raiz           6.6        7.0
//
// Dicas:
// 1. Guarde a raiz numa struct (typedef struct { NoR *raiz; } Raiz;) para
//    a busca poder trocá-la. A busca recursiva devolve a nova raiz da
//    subárvore: r->esq = sobe(r->esq, ...); se o achado está agora em
//    r->esq, rotacione r à direita (e à esquerda no lado direito).
// 2. Use um bool *achou para a volta da recursão saber se deve rotacionar.
//    Nas rotações, não há altura para atualizar.
// 3. Resposta esperada: a saída acima. Mesmo com as chaves em ordem
//    crescente, que fazem a BST virar uma lista, as buscas repetidas puxam
//    os produtos da promoção para perto da raiz.
//
// Escreva sua resposta abaixo (complete as funções):

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20

void *raiz_cria(void) {
    return NULL; // troque: aloque e devolva a estrutura vazia
}

void raiz_insere(void *e, int chave) {
    (void)e; // apague estas duas linhas
    (void)chave;
}

bool raiz_busca(void *e, int chave, int *custo) {
    (void)e; // apague estas duas linhas
    (void)chave;
    *custo = 0;
    return false;
}

void raiz_libera(void *e) {
    free(e); // troque: libere tudo o que a estrutura alocou
}

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
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    // os quatro da bancada e mais o novo, no fim
    Estrutura todos[NUM_CONCORRENTES + 1];
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        todos[k] = CONCORRENTES[k];
    }
    todos[NUM_CONCORRENTES] = (Estrutura){"para raiz", raiz_cria, raiz_insere, raiz_busca, raiz_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
