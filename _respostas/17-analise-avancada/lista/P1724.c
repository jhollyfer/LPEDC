// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1724 · ★★★ · A fila circular que dobra sem perder a ordem

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int ini, num, cap;
} Fila;

long copias;
int crescimentos;

void cresce(Fila *f) {
    int *novo = malloc(2 * f->cap * sizeof *novo);
    if (novo == NULL) exit(1);
    printf("cresce %4d -> %4d (ini era %d)\n", f->cap, 2 * f->cap, f->ini);
    for (int i = 0; i < f->num; i++) { // na ordem da fila, a partir de ini
        novo[i] = f->item[(f->ini + i) % f->cap];
        copias++;
    }
    free(f->item);
    f->item = novo;
    f->ini = 0;
    f->cap *= 2;
    crescimentos++;
}

void enfileira(Fila *f, int x) {
    if (f->num == f->cap) cresce(f);
    f->item[(f->ini + f->num) % f->cap] = x;
    f->num++;
}

int desenfileira(Fila *f) {
    int x = f->item[f->ini];
    f->ini = (f->ini + 1) % f->cap;
    f->num--;
    return x;
}

int main(void) {
    Fila f = {malloc(sizeof(int)), 0, 0, 1};
    if (f.item == NULL) return 1;
    int proxima = 1;  // número da próxima senha
    int esperada = 1; // a próxima que deve ser atendida
    bool em_ordem = true;

    for (int r = 0; r < 1000; r++) {
        // chega, chega, atende, chega, atende, chega, atende
        enfileira(&f, proxima++);
        for (int k = 0; k < 3; k++) {
            enfileira(&f, proxima++);
            if (desenfileira(&f) != esperada++) em_ordem = false;
        }
    }
    printf("Crescimentos: %d | cópias: %ld | senhas enfileiradas: %d\n", crescimentos, copias, proxima - 1);
    printf("Atendidas em ordem: %s | na fila: %d (cap %d)\n", em_ordem ? "sim" : "não", f.num, f.cap);
    free(f.item);
    return 0;
}
