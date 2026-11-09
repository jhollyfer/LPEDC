// Lista · Módulo 12 · Pilhas e filas
// Exercício P1212 · ★★☆ · Uma pilha feita com duas filas

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int inicio, n;
} Fila;

bool insere(Fila *f, int x) {
    if (f->n == CAP) {
        return false;
    }
    f->v[(f->inicio + f->n) % CAP] = x;
    f->n++;
    return true;
}

bool retira(Fila *f, int *x) {
    if (f->n == 0) {
        return false;
    }
    *x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

bool vazia(const Fila *f) {
    return f->n == 0;
}

typedef struct {
    Fila a, b; // a guarda os itens com o topo na frente
} PilhaDeFilas;

int movidos = 0;

void pdf_empilha(PilhaDeFilas *p, int x) {
    insere(&p->b, x);
    int y;
    while (retira(&p->a, &y)) { // todo mundo vai para trás do x
        insere(&p->b, y);
        movidos++;
    }
    Fila t = p->a; // troca os papéis
    p->a = p->b;
    p->b = t;
}

bool pdf_desempilha(PilhaDeFilas *p, int *x) {
    return retira(&p->a, x);
}

int main(void) {
    PilhaDeFilas p = {{.inicio = 0, .n = 0}, {.inicio = 0, .n = 0}};
    pdf_empilha(&p, 1);
    pdf_empilha(&p, 2);
    pdf_empilha(&p, 3);
    int x;
    if (pdf_desempilha(&p, &x)) {
        printf("desempilha: %d\n", x);
    }
    pdf_empilha(&p, 4);
    printf("desempilha até o fim:");
    while (!vazia(&p.a) && pdf_desempilha(&p, &x)) {
        printf(" %d", x);
    }
    printf("\nitens movidos entre as filas: %d\n", movidos);
    return 0;
}
