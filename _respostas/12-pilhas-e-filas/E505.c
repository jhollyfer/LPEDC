// 0085 · Fila
// Exercício E505 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define CAP 4

typedef struct {
    int itens[CAP];
    int inicio;
    int n;
} Fila4;

bool insere(Fila4 *f, int valor) {
    if (f->n == CAP) {
        return false;
    }
    f->itens[(f->inicio + f->n) % CAP] = valor;
    f->n++;
    return true;
}

bool retira(Fila4 *f, int *valor) {
    if (f->n == 0) {
        return false;
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

void mostra(const Fila4 *f) {
    printf("[");
    for (int i = 0; i < CAP; i++) {
        if (i > 0) {
            printf(" ");
        }
        if (f->itens[i] == -1) {
            printf("_"); // gaveta nunca usada
        } else {
            printf("%d", f->itens[i]);
        }
    }
    printf("] inicio %d, n %d\n", f->inicio, f->n);
}

int main(void) {
    Fila4 f = {.itens = {-1, -1, -1, -1}, .inicio = 0, .n = 0};
    int x;

    for (int v = 1; v <= 6; v++) {
        printf("insere %d: ", v);
        if (!insere(&f, v)) {
            printf("recusado ");
        }
        mostra(&f);
        if (v == 2 && retira(&f, &x)) { // depois do 2, sai um
            printf("retira %d: ", x);
            mostra(&f);
        }
    }
    for (int i = 0; i < 2; i++) {
        if (retira(&f, &x)) {
            printf("retira %d: ", x);
            mostra(&f);
        }
    }
    printf("próxima vaga: gaveta %d\n", (f.inicio + f.n) % CAP);
    return 0;
}
