// 0075 · Vetor dinâmico
// Exercício E450 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
    int reallocs; // quantos realloc deram certo
} Vet;

static bool vet_empurra(Vet *v, int valor) {
    if (v->tam == v->cap) {
        int *novo = realloc(v->itens, v->cap * 2 * sizeof(int));
        if (novo == NULL) return false;
        v->itens = novo;
        v->cap *= 2;
        v->reallocs++;
    }
    v->itens[v->tam++] = valor;
    return true;
}

// tira o último item; encolhe quando tam <= cap / 4
static bool vet_tira(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    if (v->cap > 2 && v->tam <= v->cap / 4) {
        int *novo = realloc(v->itens, (v->cap / 2) * sizeof(int));
        if (novo != NULL) { // se falhar, só continua grande
            v->itens = novo;
            v->cap /= 2;
            v->reallocs++;
        }
    }
    return true;
}

// tira o último item; encolhe quando tam <= cap / 2
static bool vet_tira_metade(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    if (v->cap > 2 && v->tam <= v->cap / 2) {
        int *novo = realloc(v->itens, (v->cap / 2) * sizeof(int));
        if (novo != NULL) { // se falhar, só continua grande
            v->itens = novo;
            v->cap /= 2;
            v->reallocs++;
        }
    }
    return true;
}

// cria um vetor com 1, 2, 3, 4 (tam 4, cap 4) e zera o contador
static bool vet_quatro(Vet *v) {
    v->itens = malloc(2 * sizeof(int));
    if (v->itens == NULL) return false;
    v->tam = 0;
    v->cap = 2;
    for (int i = 1; i <= 4; i++) vet_empurra(v, i);
    v->reallocs = 0;
    return true;
}

int main(void) {
    Vet v = {malloc(2 * sizeof(int)), 0, 2, 0};
    if (v.itens == NULL) return 1;

    for (int i = 1; i <= 9; i++) vet_empurra(&v, i);
    printf("empurrou 9: tam %d, cap %d\n", v.tam, v.cap);

    int x;
    while (vet_tira(&v, &x)) {
        printf("tirou %d: tam %d, cap %d\n", x, v.tam, v.cap);
    }
    free(v.itens);

    Vet metade, quarto;
    if (!vet_quatro(&metade)) return 1;
    if (!vet_quatro(&quarto)) {
        free(metade.itens);
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        vet_empurra(&metade, 5);
        vet_tira_metade(&metade, &x);
        vet_empurra(&quarto, 5);
        vet_tira(&quarto, &x);
    }
    printf("alternando com 1/2: %d realloc\n", metade.reallocs);
    printf("alternando com 1/4: %d realloc\n", quarto.reallocs);

    free(metade.itens);
    free(quarto.itens);
    return 0;
}
