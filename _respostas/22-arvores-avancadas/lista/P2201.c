// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2201 · ★☆☆ · Quantos níveis tem o organograma?

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    const char *nome;
    struct No *filho, *irmao;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    n->nome = nome;
    n->filho = n->irmao = NULL;
    return n;
}

// pendura f como ÚLTIMO filho de p
void filho(No *p, No *f) {
    if (p->filho == NULL) {
        p->filho = f;
        return;
    }
    No *x = p->filho;
    while (x->irmao != NULL) {
        x = x->irmao;
    }
    x->irmao = f;
}

void libera(No *r) {
    if (r == NULL) {
        return;
    }
    libera(r->filho);
    libera(r->irmao);
    free(r);
}

int altura(const No *r) {
    if (r == NULL) {
        return 0;
    }
    int desce = 1 + altura(r->filho);
    int lado = altura(r->irmao);
    return desce > lado ? desce : lado;
}

int main(void) {
    No *pref = novo("Prefeito"), *saude = novo("Saúde"), *norte = novo("UBS Norte"), *educ = novo("Educação");
    filho(pref, saude);
    filho(pref, educ);
    filho(pref, novo("Obras"));
    filho(saude, novo("UBS Centro"));
    filho(saude, norte);
    filho(norte, novo("Farmácia"));
    filho(educ, novo("Creche"));
    printf("Níveis: %d\n", altura(pref));
    libera(pref);
    return 0;
}
