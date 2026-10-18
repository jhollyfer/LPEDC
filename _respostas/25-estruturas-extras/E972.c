// 0162 · Matriz esparsa
// Exercício E972 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

Esparsa *multiplica(const Esparsa *a, const Esparsa *b) {
    Esparsa *c = esp_cria(a->linhas, b->colunas);
    int *acum = malloc(b->colunas * sizeof(int));
    if (acum == NULL) {
        exit(1);
    }
    for (int i = 0; i < a->linhas; i++) {
        for (int j = 0; j < b->colunas; j++) {
            acum[j] = 0;
        }
        for (const Celula *x = a->linha[i]; x != NULL; x = x->prox) {
            // a[i][k] != 0: a linha k de b contribui para a linha i de c
            for (const Celula *y = b->linha[x->col]; y != NULL; y = y->prox) {
                acum[y->col] += x->valor * y->valor;
            }
        }
        for (int j = 0; j < b->colunas; j++) {
            if (acum[j] != 0) {
                esp_define(c, i, j, acum[j]); // em ordem de j: entra no fim
            }
        }
    }
    free(acum);
    return c;
}

int main(void) {
    const char *cidade[] = {"Manaus", "Belém", "Recife", "Brasília", "São Paulo", "Porto Alegre"};
    int voo[][2] = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 4}, {3, 2},
                    {3, 4}, {4, 3}, {4, 5}, {5, 4}};
    Esparsa *voos = esp_cria(6, 6);
    for (int k = 0; k < 10; k++) {
        esp_define(voos, voo[k][0], voo[k][1], 1);
    }

    Esparsa *duas = multiplica(voos, voos);
    esp_mostra(duas);
    for (int i = 0; i < duas->linhas; i++) {
        int rotas = 0;
        for (const Celula *c = duas->linha[i]; c != NULL; c = c->prox) {
            rotas += c->valor;
        }
        printf("%s: %d %s com uma escala\n", cidade[i], rotas, rotas == 1 ? "rota" : "rotas");
    }

    esp_libera(voos);
    esp_libera(duas);
    return 0;
}
