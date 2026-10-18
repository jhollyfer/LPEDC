// 0104 · Juntando tudo
// Exercício E620 · ★☆☆

#include <stdio.h>
#include "cadastro.h"

void resumo(const NoAluno *cad) {
    if (cad == NULL) {
        printf("cadastro vazio\n");
        return;
    }
    printf("raiz %d (%s), altura %d, %d alunos\n", cad->a.matricula, cad->a.nome,
           cad_altura(cad), cad_conta(cad));
}

int main(void) {
    Aluno turma[] = {
        {40, "Teo", 11}, {20, "Paulo", 7}, {60, "Caio", 6},
        {10, "Rita", 3}, {30, "Lia", 9}, {50, "Joana", 5},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 6; i++) {
        cad = cad_insere(cad, turma[i]);
    }
    resumo(cad);

    // remove sempre quem está na raiz, até não sobrar ninguém
    while (cad != NULL) {
        cad = cad_remove(cad, cad->a.matricula);
        resumo(cad);
    }
    return 0;
}
