// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1022 · ★★★ · Turmas como conjuntos ordenados

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- conjunto.h -----------------------------------------------------------
typedef struct conjunto Conjunto;

Conjunto *conj_cria(void);
bool conj_insere(Conjunto *c, int x); // mantém a ordem; ignora repetido
Conjunto *conj_uniao(const Conjunto *a, const Conjunto *b, long *comp);
Conjunto *conj_intersecao(const Conjunto *a, const Conjunto *b, long *comp);
void conj_imprime(const Conjunto *c);
void conj_libera(Conjunto *c);

// ---- conjunto.c -----------------------------------------------------------
// Invariante: v[0..n-1] em ordem estritamente crescente, n <= cap.
struct conjunto {
    int *v;
    int n, cap;
};

Conjunto *conj_cria(void) {
    Conjunto *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    c->v = malloc(4 * sizeof(int));
    if (c->v == NULL) {
        free(c);
        return NULL;
    }
    c->n = 0;
    c->cap = 4;
    return c;
}

// acrescenta no fim (quem chama garante que x é maior que todos)
static bool poe_no_fim(Conjunto *c, int x) {
    if (c->n == c->cap) {
        int *novo = realloc(c->v, 2 * c->cap * sizeof(int));
        if (novo == NULL) {
            return false;
        }
        c->v = novo;
        c->cap *= 2;
    }
    c->v[c->n++] = x;
    return true;
}

bool conj_insere(Conjunto *c, int x) {
    for (int i = 0; i < c->n; i++) {
        if (c->v[i] == x) {
            return true; // já está
        }
    }
    if (!poe_no_fim(c, x)) {
        return false;
    }
    int i = c->n - 1;
    while (i > 0 && c->v[i - 1] > x) { // desloca os maiores para a direita
        c->v[i] = c->v[i - 1];
        i--;
    }
    c->v[i] = x;
    return true;
}

Conjunto *conj_uniao(const Conjunto *a, const Conjunto *b, long *comp) {
    Conjunto *r = conj_cria();
    if (r == NULL) {
        return NULL;
    }
    int i = 0, j = 0;
    *comp = 0;
    while (i < a->n && j < b->n) {
        (*comp)++;
        if (a->v[i] < b->v[j]) {
            poe_no_fim(r, a->v[i++]);
        } else if (a->v[i] > b->v[j]) {
            poe_no_fim(r, b->v[j++]);
        } else {
            poe_no_fim(r, a->v[i]);
            i++;
            j++;
        }
    }
    while (i < a->n) {
        poe_no_fim(r, a->v[i++]);
    }
    while (j < b->n) {
        poe_no_fim(r, b->v[j++]);
    }
    return r;
}

Conjunto *conj_intersecao(const Conjunto *a, const Conjunto *b, long *comp) {
    Conjunto *r = conj_cria();
    if (r == NULL) {
        return NULL;
    }
    int i = 0, j = 0;
    *comp = 0;
    while (i < a->n && j < b->n) {
        (*comp)++;
        if (a->v[i] < b->v[j]) {
            i++;
        } else if (a->v[i] > b->v[j]) {
            j++;
        } else {
            poe_no_fim(r, a->v[i]);
            i++;
            j++;
        }
    }
    return r;
}

void conj_imprime(const Conjunto *c) {
    for (int i = 0; i < c->n; i++) {
        printf(i == 0 ? "%d" : " %d", c->v[i]);
    }
}

void conj_libera(Conjunto *c) {
    if (c != NULL) {
        free(c->v);
        free(c);
    }
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    int py[5] = {25, 3, 12, 8, 20};
    int cc[5] = {30, 8, 5, 20, 8};
    Conjunto *a = conj_cria(), *b = conj_cria();
    if (a == NULL || b == NULL) {
        conj_libera(a);
        conj_libera(b);
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        conj_insere(a, py[i]);
        conj_insere(b, cc[i]);
    }
    printf("Python: ");
    conj_imprime(a);
    printf("\nC: ");
    conj_imprime(b);
    printf("\n");

    long comp;
    Conjunto *u = conj_uniao(a, b, &comp);
    if (u != NULL) {
        printf("União: ");
        conj_imprime(u);
        printf(" (%ld comparações)\n", comp);
    }
    Conjunto *in = conj_intersecao(a, b, &comp);
    if (in != NULL) {
        printf("Interseção: ");
        conj_imprime(in);
        printf(" (%ld comparações)\n", comp);
    }

    // ingênua: para cada número de Python, percorre a turma de C inteira
    int va[5] = {3, 8, 12, 20, 25}, vb[4] = {5, 8, 20, 30};
    long ing = 0;
    printf("Interseção ingênua:");
    for (int i = 0; i < 5; i++) {
        bool achou = false;
        for (int j = 0; j < 4; j++) {
            ing++;
            if (va[i] == vb[j]) {
                achou = true;
            }
        }
        if (achou) {
            printf(" %d", va[i]);
        }
    }
    printf(" (%ld comparações)\n", ing);

    conj_libera(a);
    conj_libera(b);
    conj_libera(u);
    conj_libera(in);
    return 0;
}
