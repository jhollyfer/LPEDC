// A330 · Um concorrente novo na bancada

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000

// ---- o concorrente novo: lista com contagem (assunto 0164), com int ----
typedef struct NoC {
    int chave, acessos;
    struct NoC *prox;
} NoC;

void *cont_cria(void) {
    NoC **inicio = malloc(sizeof(NoC *)); // a "estrutura" é só o ponteiro inicial
    if (inicio == NULL) {
        exit(1);
    }
    *inicio = NULL;
    return inicio;
}

void cont_insere(void *e, int chave) {
    NoC **p = e;
    while (*p != NULL) { // vai até o fim (repetida é ignorada)
        if ((*p)->chave == chave) {
            return;
        }
        p = &(*p)->prox;
    }
    *p = malloc(sizeof(NoC));
    if (*p == NULL) {
        exit(1);
    }
    (*p)->chave = chave;
    (*p)->acessos = 0;
    (*p)->prox = NULL;
}

bool cont_busca(void *e, int chave, int *custo) {
    NoC **p = e;
    int c = 0;
    while (*p != NULL) {
        c++;
        if ((*p)->chave == chave) {
            break;
        }
        p = &(*p)->prox;
    }
    *custo = c;
    if (*p == NULL) {
        return false;
    }
    NoC *achado = *p;
    achado->acessos++;
    *p = achado->prox; // tira da lista e reinsere antes do primeiro com menos acessos
    NoC **q = e;
    while (*q != NULL && (*q)->acessos >= achado->acessos) {
        q = &(*q)->prox;
    }
    achado->prox = *q;
    *q = achado;
    return true;
}

void cont_libera(void *e) {
    NoC *p = *(NoC **)e;
    while (p != NULL) {
        NoC *prox = p->prox;
        free(p);
        p = prox;
    }
    free(e);
}

// ---- o teste: a promoção muda no meio do dia ----
void mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long metade[2] = {0, 0};
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        metade[i >= BUSCAS / 2] += custo;
    }
    e->libera(d);
    printf("%-10s %8.1f %8.1f\n", e->nome, metade[0] / (BUSCAS / 2.0), metade[1] / (BUSCAS / 2.0));
}

int main(void) {
    const Estrutura contagem = {"contagem", cont_cria, cont_insere, cont_busca, cont_libera};

    unsigned estado = 5;
    int ordem[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        ordem[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(ordem, N, &estado);
    bc_embaralha(sorteio, N, &estado);

    // manhã: 95% em sorteio[0..9]; tarde: 95% em sorteio[10..19]
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        int base = i < BUSCAS / 2 ? 0 : 10;
        if (bc_sorteio(&estado) % 100 < 95) {
            buscas[i] = sorteio[base + bc_sorteio(&estado) % 10];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    printf("%-10s %9s %8s\n", "", "manhã", "tarde"); // %9s: o "ã" ocupa 2 bytes
    mede(&CONCORRENTES[1], ordem, buscas); // AVL
    mede(&CONCORRENTES[3], ordem, buscas); // lista MTF
    mede(&contagem, ordem, buscas);
    return 0;
}
// Saída:
//               manhã    tarde
// AVL             8.8      9.5
// lista MTF      29.2     35.7
// contagem       28.7     45.1
