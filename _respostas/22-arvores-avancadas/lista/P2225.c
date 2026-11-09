// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2225 · ★★★ · Pintar uma árvore de busca de rubro-negra

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 16

typedef struct No {
    int chave;
    bool vermelho;
    struct No *esq, *dir;
} No;

No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){chave, false, esq, dir};
    return n;
}

No *f(int chave) {
    return no(chave, NULL, NULL);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

No *ordem[MAXN];
int pai[MAXN], n;
int validas;
char primeira[128];

void lista(No *r, int p) {
    if (r == NULL) {
        return;
    }
    int eu = n++;
    ordem[eu] = r;
    pai[eu] = p;
    lista(r->esq, eu);
    lista(r->dir, eu);
}

int altura_negra(const No *r) {
    if (r == NULL) {
        return 0;
    }
    int e = altura_negra(r->esq), d = altura_negra(r->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (r->vermelho ? 0 : 1);
}

void pinta(int i) {
    if (i == n) {
        if (!ordem[0]->vermelho && altura_negra(ordem[0]) >= 0) {
            validas++;
            if (validas == 1) {
                int k = 0;
                for (int j = 0; j < n; j++) {
                    k += sprintf(primeira + k, " %d%s", ordem[j]->chave, ordem[j]->vermelho ? "*" : "");
                }
            }
        }
        return;
    }
    ordem[i]->vermelho = false;
    pinta(i + 1);
    if (i > 0 && !ordem[pai[i]]->vermelho) {
        ordem[i]->vermelho = true;
        pinta(i + 1);
        ordem[i]->vermelho = false;
    }
}

void testa(char nome, No *r) {
    n = 0;
    lista(r, -1);
    validas = 0;
    primeira[0] = '\0';
    pinta(0);
    printf("%c: %d coloração(ões)", nome, validas);
    if (validas > 0) {
        printf(", a primeira:%s", primeira);
    }
    printf("\n");
    libera(r);
}

int main(void) {
    testa('A', no(20, no(10, f(5), f(15)), no(30, f(25), f(40))));
    testa('B', no(20, no(10, f(5), NULL), no(30, f(25), no(40, NULL, f(50)))));
    testa('C', no(20, f(10), no(30, f(25), no(40, NULL, no(50, NULL, f(60))))));
    return 0;
}
