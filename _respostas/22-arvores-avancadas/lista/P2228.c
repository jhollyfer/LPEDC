// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2228 · ★★★ · O parente comum mais próximo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    const char *nome;
    struct No *filho, *irmao, *pai;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){nome, NULL, NULL, NULL};
    return n;
}

No *filho(No *p, const char *nome) {
    No *f = novo(nome);
    f->pai = p;
    No **x = &p->filho;
    while (*x != NULL) {
        x = &(*x)->irmao;
    }
    *x = f;
    return f;
}

No *acha(No *r, const char *nome) {
    if (r == NULL) {
        return NULL;
    }
    if (strcmp(r->nome, nome) == 0) {
        return r;
    }
    No *x = acha(r->filho, nome);
    return x != NULL ? x : acha(r->irmao, nome);
}

int profundidade(const No *x) {
    int d = 0;
    while (x->pai != NULL) {
        x = x->pai;
        d++;
    }
    return d;
}

const No *lca(const No *a, const No *b) {
    int da = profundidade(a), db = profundidade(b);
    while (da > db) {
        a = a->pai;
        da--;
    }
    while (db > da) {
        b = b->pai;
        db--;
    }
    while (a != b) {
        a = a->pai;
        b = b->pai;
    }
    return a;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->filho);
        libera(r->irmao);
        free(r);
    }
}

int main(void) {
    No *sev = novo("Severino");
    No *ant = filho(sev, "Antônio"), *ben = filho(sev, "Benedita");
    No *car = filho(ant, "Carla");
    filho(ant, "Diego");
    filho(car, "Igor");
    No *ela = filho(ben, "Elaine");
    filho(ben, "Fábio");
    No *glo = filho(ben, "Glória");
    filho(ela, "Júlia");
    filho(ela, "Kauã");
    filho(glo, "Hugo");
    const char *pares[4][2] = {{"Igor", "Diego"}, {"Júlia", "Hugo"}, {"Kauã", "Elaine"}, {"Igor", "Hugo"}};
    for (int i = 0; i < 4; i++) {
        const No *a = acha(sev, pares[i][0]), *b = acha(sev, pares[i][1]);
        const No *c = lca(a, b);
        int d = profundidade(a) + profundidade(b) - 2 * profundidade(c);
        printf("%s e %s: %s (distância %d)\n", a->nome, b->nome, c->nome, d);
    }
    libera(sev);
    return 0;
}
