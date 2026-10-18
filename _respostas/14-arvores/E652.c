// 0109 · Juntando tudo
// Exercício E652 · ★★☆

#include <stdio.h>
#include "cadastro.h"

int proxima(const NoAluno *r, int x) {
    int candidata = -1;
    while (r != NULL) {
        if (r->a.matricula > x) {
            candidata = r->a.matricula; // serve; procura uma menor à esquerda
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return candidata;
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
    int testes[] = {45, 50, 10, 80};
    for (int i = 0; i < 4; i++) {
        printf("depois de %d: %d\n", testes[i], proxima(cad, testes[i]));
    }
    cad = cad_libera(cad);
    return 0;
}
