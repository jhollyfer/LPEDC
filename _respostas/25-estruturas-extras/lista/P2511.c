// Lista · Módulo 25 · Estruturas especiais
// Exercício P2511 · ★★☆ · O estoque que não esquece o zero

#include <stdio.h>
#include <stdlib.h>

#define F 3

typedef struct Celula {
    int produto, qtd;
    struct Celula *prox;
} Celula;

Celula *linha[F];
int celulas = 0;

// estoque[f][produto] = qtd; qtd 0 APAGA a célula
void define(int f, int produto, int qtd) {
    Celula **p = &linha[f];
    while (*p != NULL && (*p)->produto < produto) p = &(*p)->prox;
    if (*p != NULL && (*p)->produto == produto) {
        if (qtd == 0) { // o conserto: zero não se guarda, a célula sai da lista
            Celula *velha = *p;
            *p = velha->prox;
            free(velha);
            celulas--;
        } else {
            (*p)->qtd = qtd;
        }
        return;
    }
    if (qtd == 0) return; // já era zero: nada a fazer
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) exit(1);
    nova->produto = produto;
    nova->qtd = qtd;
    nova->prox = *p;
    *p = nova;
    celulas++;
}

int main(void) {
    define(0, 4, 10);
    define(0, 7, 3);
    define(1, 2, 8);
    define(2, 4, 1);
    define(2, 9, 6);
    define(0, 7, 0); // a filial 0 vendeu o último do produto 7
    define(2, 4, 0); // a filial 2 também zerou o produto 4
    define(1, 5, 0); // zera um que nem existia

    for (int f = 0; f < F; f++) {
        printf("filial %d:", f);
        for (Celula *c = linha[f]; c != NULL; c = c->prox) printf(" p%d=%d", c->produto, c->qtd);
        printf("\n");
    }
    printf("Células: %d\n", celulas);
    for (int f = 0; f < F; f++)
        while (linha[f] != NULL) {
            Celula *c = linha[f];
            linha[f] = c->prox;
            free(c);
        }
    return 0;
}
