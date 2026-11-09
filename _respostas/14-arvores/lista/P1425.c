// Lista · Módulo 14 · Árvores
// Exercício P1425 · ★★★ · O paciente que piorou na fila

#include <stdio.h>

#define MAX 10

typedef struct {
    int heap[MAX];    // ids dos pacientes, heap de máximo pela gravidade
    int pos[MAX];     // pos[id] = índice do paciente no heap (-1 se fora)
    int gravidade[MAX];
    int n;
} Fila;

// id a deve sair antes de id b?
int antes(const Fila *f, int a, int b) {
    if (f->gravidade[a] != f->gravidade[b]) {
        return f->gravidade[a] > f->gravidade[b];
    }
    return a < b; // empate: quem tem a ficha menor
}

void troca(Fila *f, int i, int j) {
    int t = f->heap[i];
    f->heap[i] = f->heap[j];
    f->heap[j] = t;
    f->pos[f->heap[i]] = i; // as trocas mantêm pos[] em dia
    f->pos[f->heap[j]] = j;
}

void sobe(Fila *f, int i) {
    while (i > 0 && antes(f, f->heap[i], f->heap[(i - 1) / 2])) {
        troca(f, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void desce(Fila *f, int i) {
    while (2 * i + 1 < f->n) {
        int c = 2 * i + 1;
        if (c + 1 < f->n && antes(f, f->heap[c + 1], f->heap[c])) {
            c++;
        }
        if (!antes(f, f->heap[c], f->heap[i])) {
            break;
        }
        troca(f, i, c);
        i = c;
    }
}

void chega(Fila *f, int id, int g) {
    f->gravidade[id] = g;
    f->heap[f->n] = id;
    f->pos[id] = f->n;
    f->n++;
    sobe(f, f->n - 1);
}

// a gravidade só aumenta: o paciente só pode subir
void piorou(Fila *f, int id, int g) {
    f->gravidade[id] = g;
    sobe(f, f->pos[id]);
}

int atende(Fila *f) {
    int id = f->heap[0];
    f->n--;
    if (f->n > 0) {
        troca(f, 0, f->n);
        desce(f, 0);
    }
    f->pos[id] = -1;
    return id;
}

int main(void) {
    Fila f = {.n = 0};
    int g[] = {3, 5, 2, 4, 2, 1};
    for (int id = 0; id < 6; id++) {
        chega(&f, id, g[id]);
    }

    printf("atendido: ficha %d\n", atende(&f));
    piorou(&f, 5, 4);
    printf("ficha 5 piorou para 4\n");
    piorou(&f, 2, 6);
    printf("ficha 2 piorou para 6\n");
    while (f.n > 0) {
        int id = atende(&f);
        printf("atendido: ficha %d (gravidade %d)\n", id, f.gravidade[id]);
    }
    return 0;
}
