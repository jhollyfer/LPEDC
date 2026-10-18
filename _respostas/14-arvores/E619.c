// 0104 · Juntando tudo
// Exercício E619 · ★☆☆

#include <stdio.h>
#include "cadastro.h"

int conta_brinde(const NoAluno *r) {
    if (r == NULL) {
        return 0;
    }
    int este = r->a.treinos >= 10 ? 1 : 0;
    return este + conta_brinde(r->esq) + conta_brinde(r->dir);
}

void mostra_brinde(const NoAluno *r) {
    if (r == NULL) {
        return;
    }
    mostra_brinde(r->esq);
    if (r->a.treinos >= 10) {
        printf(" %s", r->a.nome);
    }
    mostra_brinde(r->dir);
}

int main(void) {
    Aluno turma[] = {
        {50, "Ana", 12}, {30, "Bruno", 8}, {70, "Carla", 15}, {20, "Davi", 4},
        {40, "Eva", 20}, {60, "Fabio", 9}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, turma[i]);
    }

    printf("Ganham brinde:");
    mostra_brinde(cad);
    printf("\nTotal: %d\n", conta_brinde(cad));

    cad = cad_libera(cad);
    return 0;
}
