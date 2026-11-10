// 0086 · Fila encadeada
// Exercício E514 · ★★☆
//
// A fila de pedidos da cozinha funciona bem no começo da noite. Mas o
// sanitizer explode quando a fila esvazia e chega um pedido novo. Rode, leia
// o relatório (procure "heap-use-after-free" e a linha), conserte e rode de
// novo: as quatro linhas têm que aparecer sem nenhum relatório do sanitizer.
//
//   Saída esperada depois do conserto:
//   Pronto: 11
//   Pronto: 12
//   Pronto: 13
//   Pronto: 14
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int numero;
    struct pedido *prox;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Cozinha;

bool cozinha_entra(Cozinha *f, int numero) {
    Pedido *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->numero = numero;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;
}

bool cozinha_sai(Cozinha *f, int *numero) {
    if (f->inicio == NULL) {
        return false;
    }
    Pedido *velho = f->inicio;
    *numero = velho->numero;
    f->inicio = velho->prox;
    free(velho);
    return true;
}

int main(void) {
    Cozinha f = {NULL, NULL};
    int n;

    cozinha_entra(&f, 11);
    cozinha_entra(&f, 12);
    while (cozinha_sai(&f, &n)) {
        printf("Pronto: %d\n", n);
    }

    cozinha_entra(&f, 13); // a fila tinha esvaziado
    cozinha_entra(&f, 14);
    while (cozinha_sai(&f, &n)) {
        printf("Pronto: %d\n", n);
    }
    return 0;
}
