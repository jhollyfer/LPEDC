// 0085 · Fila
// Exercício E507 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int inicio; // próximo a sair
    int fim;    // próxima vaga (sempre livre)
} FilaSacrificada;

bool fc_vazia(const FilaSacrificada *f) {
    return f->inicio == f->fim;
}

bool fc_cheia(const FilaSacrificada *f) {
    return (f->fim + 1) % TAM == f->inicio;
}

bool fc_insere(FilaSacrificada *f, int valor) {
    if (fc_cheia(f)) {
        return false;
    }
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    return true;
}

bool fc_retira(FilaSacrificada *f, int *valor) {
    if (fc_vazia(f)) {
        return false;
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    return true;
}

int main(void) {
    FilaSacrificada f = {.inicio = 0, .fim = 0};
    int x;

    for (int v = 1; v <= 5; v++) {
        if (!fc_insere(&f, v)) {
            printf("%d recusado: fila cheia\n", v);
        }
    }
    for (int i = 0; i < 2; i++) {
        if (fc_retira(&f, &x)) {
            printf("saiu %d\n", x);
        }
    }
    for (int v = 6; v <= 8; v++) {
        if (!fc_insere(&f, v)) {
            printf("%d recusado: fila cheia\n", v);
        }
    }
    printf("Na fila:");
    while (fc_retira(&f, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    return 0;
}
