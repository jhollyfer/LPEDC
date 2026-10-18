// 0162 · Matriz esparsa
// Exercício E971 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

// pendura uma célula no fim da linha; *fim é o ponteiro que vai apontar para ela
static Celula **pendura(Esparsa *c, Celula **fim, int col, int valor) {
    if (valor == 0) {
        return fim; // zero não se guarda
    }
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        exit(1);
    }
    nova->col = col;
    nova->valor = valor;
    nova->prox = NULL;
    *fim = nova;
    c->nao_zeros++;
    return &nova->prox;
}

Esparsa *soma(const Esparsa *a, const Esparsa *b) {
    Esparsa *c = esp_cria(a->linhas, a->colunas);
    for (int i = 0; i < a->linhas; i++) {
        const Celula *pa = a->linha[i];
        const Celula *pb = b->linha[i];
        Celula **fim = &c->linha[i];
        while (pa != NULL && pb != NULL) {
            if (pa->col < pb->col) {
                fim = pendura(c, fim, pa->col, pa->valor);
                pa = pa->prox;
            } else if (pa->col > pb->col) {
                fim = pendura(c, fim, pb->col, pb->valor);
                pb = pb->prox;
            } else { // mesma coluna: soma (e pode zerar)
                fim = pendura(c, fim, pa->col, pa->valor + pb->valor);
                pa = pa->prox;
                pb = pb->prox;
            }
        }
        for (; pa != NULL; pa = pa->prox) {
            fim = pendura(c, fim, pa->col, pa->valor);
        }
        for (; pb != NULL; pb = pb->prox) {
            fim = pendura(c, fim, pb->col, pb->valor);
        }
    }
    return c;
}

int main(void) {
    Esparsa *estoque = esp_cria(3, 6);
    esp_define(estoque, 0, 0, 4);
    esp_define(estoque, 0, 2, 5);
    esp_define(estoque, 1, 0, 2);
    esp_define(estoque, 1, 3, 3);
    esp_define(estoque, 2, 1, 2);

    Esparsa *movimento = esp_cria(3, 6);
    esp_define(movimento, 0, 2, -5); // vendeu tudo do produto 2
    esp_define(movimento, 0, 4, 9);  // chegou o produto 4
    esp_define(movimento, 1, 0, -2);

    Esparsa *novo = soma(estoque, movimento);
    printf("Estoque novo:\n");
    esp_mostra(novo);
    printf("Células: %d\n", novo->nao_zeros);

    esp_libera(estoque);
    esp_libera(movimento);
    esp_libera(novo);
    return 0;
}
