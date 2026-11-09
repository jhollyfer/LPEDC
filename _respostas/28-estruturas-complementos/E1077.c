// 0180 · Pigeonhole e chave composta
// Exercício E1077 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include "pombal.h"

// o campo turma guarda a posição original; estável = entre notas iguais,
// as posições originais continuam crescendo
bool eh_estavel(const Aluno *v, int n) {
    for (int i = 1; i < n; i++) {
        if (v[i].nota == v[i - 1].nota && v[i].turma < v[i - 1].turma) {
            return false;
        }
    }
    return true;
}

void prepara(Aluno *v, int n) {
    int notas[] = {4, 8, 4, 2, 8, 4, 6, 2, 8, 6};
    for (int i = 0; i < n; i++) {
        snprintf(v[i].nome, sizeof v[i].nome, "a%d", i);
        v[i].nota = notas[i];
        v[i].turma = i; // a etiqueta com a posição de chegada
    }
}

int main(void) {
    Aluno v[10];
    prepara(v, 10);
    pb_selecao(v, 10);
    printf("seleção:    %s | ", eh_estavel(v, 10) ? "estável    " : "não estável");
    pb_mostra(v, 10);
    prepara(v, 10);
    pb_insercao(v, 10);
    printf("inserção:   %s | ", eh_estavel(v, 10) ? "estável    " : "não estável");
    pb_mostra(v, 10);
    prepara(v, 10);
    if (pb_pigeonhole(v, 10, 0, 10) != 0) {
        return 1;
    }
    printf("pigeonhole: %s | ", eh_estavel(v, 10) ? "estável    " : "não estável");
    pb_mostra(v, 10);
    return 0;
}
