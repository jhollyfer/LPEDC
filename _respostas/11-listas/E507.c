// 0085 · Lista circular
// Exercício E507 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct motorista {
    char nome[20];
    int km;
    struct motorista *prox;
} Motorista;

// põe no fim da roda e devolve o novo último
static Motorista *entra_na_roda(Motorista *ultimo, const char *nome) {
    Motorista *novo = malloc(sizeof(Motorista));
    if (novo == NULL) exit(1);
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->km = 0;
    if (ultimo == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    return novo;
}

int main(void) {
    Motorista *roda = NULL;
    roda = entra_na_roda(roda, "Rita");
    roda = entra_na_roda(roda, "Davi");
    roda = entra_na_roda(roda, "Lia");

    int falta = 1000;
    int trecho = 1;
    Motorista *volante = roda->prox;
    while (falta > 0) {
        int km = falta < 150 ? falta : 150;
        printf("trecho %d: %s dirige %d km\n", trecho, volante->nome, km);
        volante->km += km;
        falta -= km;
        trecho++;
        volante = volante->prox;
    }

    Motorista *p = roda->prox;
    do {
        printf("%s: %d km\n", p->nome, p->km);
        p = p->prox;
    } while (p != roda->prox);

    p = roda->prox;
    roda->prox = NULL; // corta o círculo
    while (p != NULL) {
        Motorista *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    return 0;
}
