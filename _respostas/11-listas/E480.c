// 0080 · Vetor dinâmico
// Exercício E480 · ★★★
//
// Por que 1/4: encolhendo na metade, um vetor com tam 4 e cap 4 que alterna
// "empurra, tira" faria um realloc (que copia tudo) a CADA operação: empurra
// cresce para cap 8; tira volta a tam 4, metade de 8, e encolhe para 4;
// empurra cresce de novo... Encolhendo em 1/4, logo depois de encolher o
// vetor fica pela metade, com folga para os dois lados antes do próximo
// realloc.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
} Vet;

static bool vet_empurra(Vet *v, int valor) {
    if (v->tam == v->cap) {
        int *novo = realloc(v->itens, v->cap * 2 * sizeof(int));
        if (novo == NULL) return false;
        v->itens = novo;
        v->cap *= 2;
    }
    v->itens[v->tam++] = valor;
    return true;
}

static bool vet_tira(Vet *v, int *saiu) {
    if (v->tam == 0) return false;
    v->tam--;
    *saiu = v->itens[v->tam];
    if (v->cap > 2 && v->tam <= v->cap / 4) {
        int *novo = realloc(v->itens, (v->cap / 2) * sizeof(int));
        if (novo != NULL) { // se falhar, só continua grande
            v->itens = novo;
            v->cap /= 2;
        }
    }
    return true;
}

int main(void) {
    Vet v = {malloc(2 * sizeof(int)), 0, 2};
    if (v.itens == NULL) return 1;

    for (int i = 1; i <= 9; i++) vet_empurra(&v, i);
    printf("empurrou 9: tam %d, cap %d\n", v.tam, v.cap);

    int x;
    while (vet_tira(&v, &x)) {
        printf("tirou %d: tam %d, cap %d\n", x, v.tam, v.cap);
    }

    free(v.itens);
    return 0;
}
