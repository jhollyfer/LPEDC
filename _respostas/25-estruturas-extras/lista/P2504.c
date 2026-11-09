// Lista · Módulo 25 · Estruturas especiais
// Exercício P2504 · ★☆☆ · As horas extras do mês

#include <stdio.h>
#include <stdlib.h>

#define F 5
#define D 30

typedef struct Celula {
    int dia, horas;
    struct Celula *prox;
} Celula;

Celula *linha[F]; // uma lista por funcionário, em ordem de dia

void define(int f, int dia, int horas) {
    Celula **p = &linha[f];
    while (*p != NULL && (*p)->dia < dia) p = &(*p)->prox;
    if (*p != NULL && (*p)->dia == dia) { // já existe: só troca o valor
        (*p)->horas = horas;
        return;
    }
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) exit(1);
    nova->dia = dia;
    nova->horas = horas;
    nova->prox = *p;
    *p = nova;
}

int main(void) {
    const char *nomes[F] = {"Ana", "Bruno", "Carla", "Diego", "Elisa"};
    int lancamentos[][3] = {{0, 12, 2}, {3, 5, 1}, {0, 3, 3}, {2, 28, 4}, {0, 20, 1},
                            {3, 5, 2}, {4, 9, 2}, {4, 1, 1}, {0, 12, 3}};
    for (int k = 0; k < 9; k++) define(lancamentos[k][0], lancamentos[k][1], lancamentos[k][2]);

    int celulas = 0;
    for (int f = 0; f < F; f++) {
        int soma = 0;
        printf("%-6s", nomes[f]);
        for (Celula *c = linha[f]; c != NULL; c = c->prox) {
            printf(" dia %d: %dh;", c->dia, c->horas);
            soma += c->horas;
            celulas++;
        }
        printf(" total %dh\n", soma);
    }
    printf("Células: %d de %d\n", celulas, F * D);

    for (int f = 0; f < F; f++)
        while (linha[f] != NULL) {
            Celula *c = linha[f];
            linha[f] = c->prox;
            free(c);
        }
    return 0;
}
