// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2202 · ★☆☆ · Quem tem mais filhos

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

void filho(No *p, No *f) {
    No **x = &p->filho;
    while (*x != NULL) {
        x = &(*x)->irmao;
    }
    *x = f;
}

int conta_filhos(const No *r) {
    int c = 0;
    for (const No *f = r->filho; f != NULL; f = f->irmao) {
        c++;
    }
    return c;
}

void mostra(const No *r, int nivel) {
    if (r == NULL) {
        return;
    }
    printf("%*s%s (%d)\n", 2 * nivel, "", r->nome, conta_filhos(r));
    mostra(r->filho, nivel + 1);
    mostra(r->irmao, nivel);
}

const No *mais_filhos(const No *r, int *max) {
    if (r == NULL) {
        return NULL;
    }
    const No *melhor = NULL;
    int c = conta_filhos(r);
    if (c > *max) {
        *max = c;
        melhor = r;
    }
    const No *f = mais_filhos(r->filho, max);
    if (f != NULL) {
        melhor = f;
    }
    const No *i = mais_filhos(r->irmao, max);
    if (i != NULL) {
        melhor = i;
    }
    return melhor;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->filho);
        libera(r->irmao);
        free(r);
    }
}

int main(void) {
    No *rai = novo("Raimundo"), *joa = novo("Joana"), *ped = novo("Pedro"), *rit = novo("Rita"), *eli = novo("Elis");
    filho(rai, joa);
    filho(rai, ped);
    filho(rai, rit);
    filho(joa, novo("Ana"));
    filho(joa, novo("Bruno"));
    filho(ped, novo("Caio"));
    filho(ped, novo("Davi"));
    filho(ped, eli);
    filho(ped, novo("Fábio"));
    filho(rit, novo("Gabi"));
    filho(eli, novo("Helena"));
    mostra(rai, 0);
    int max = -1;
    const No *m = mais_filhos(rai, &max);
    printf("Mais filhos: %s, com %d\n", m->nome, max);
    libera(rai);
    return 0;
}
