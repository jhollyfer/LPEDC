// Lista · Módulo 12 · Pilhas e filas
// Exercício P1218 · ★★☆ · A fila do lava-jato que trava
//
// O lava-jato tem vaga para 4 carros na fila. A fila circular abaixo (com
// inicio, fim e n) compila sem aviso, mas tem TRÊS erros de propósito: um
// em insere e dois em retira. O resultado é que a fila "trava" e recusa
// carros que cabem. Conserte os três para a saída ficar:
//
//   Saída esperada:
//   entram 1 2 3
//   saem 1 2
//   entram 4 5 6
//   saem até esvaziar: 3 4 5 6
//
// Dicas:
// 1. Depois de "entram 1 2 3" e "saem 1 2", sobra 1 carro e há 3 vagas.
//    Acompanhe inicio, fim e n à mão (ou com um printf) e veja qual campo
//    sai errado primeiro.
// 2. O fim precisa dar a volta no vetor, como o inicio.
// 3. Com a fila cheia, inicio == fim, igual à fila vazia: quem distingue os
//    dois casos é o n.
// 4. Resposta esperada: em insere, fim = (fim + 1) % CAP; em retira, teste
//    vazia com n == 0 e faça n-- ao retirar.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAP 4

typedef struct {
    int *v;
    int inicio, fim, n;
} Fila;

bool insere(Fila *f, int x) {
    if (f->n == CAP) {
        return false;
    }
    f->v[f->fim] = x;
    f->fim = f->fim + 1;
    f->n++;
    return true;
}

bool retira(Fila *f, int *x) {
    if (f->inicio == f->fim) {
        return false;
    }
    *x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    return true;
}

void entram(Fila *f, int de, int ate) {
    printf("entram");
    for (int c = de; c <= ate; c++) {
        if (insere(f, c)) {
            printf(" %d", c);
        } else {
            printf(" (%d recusado)", c);
        }
    }
    printf("\n");
}

int main(void) {
    Fila f = {malloc(CAP * sizeof(int)), 0, 0, 0};
    if (f.v == NULL) {
        return 1;
    }
    int x;
    entram(&f, 1, 3);
    printf("saem");
    for (int i = 0; i < 2 && retira(&f, &x); i++) {
        printf(" %d", x);
    }
    printf("\n");
    entram(&f, 4, 6);
    printf("saem até esvaziar:");
    for (int voltas = 0; voltas < 10 && retira(&f, &x); voltas++) { // trava de segurança
        printf(" %d", x);
    }
    printf("\n");
    free(f.v);
    return 0;
}
