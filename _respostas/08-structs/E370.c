// 0062 · Ponteiro para struct
// Exercício E370 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    double preco;
} Produto;

Produto *criar_produto(const char *nome, double preco) {
    Produto *p = malloc(sizeof *p);
    if (p == NULL) {
        return NULL;
    }
    strcpy(p->nome, nome);
    p->preco = preco;
    return p;
}

int main(void) {
    Produto *fone = criar_produto("Fone Bluetooth", 149.90);
    if (fone == NULL) {
        return 1;
    }
    printf("%s: R$ %.2f\n", fone->nome, fone->preco);
    free(fone);
    return 0;
}
