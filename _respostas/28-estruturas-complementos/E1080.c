// 0180 · Pigeonhole e chave composta
// Exercício E1080 · ★★★

#include <stdio.h>
#include "pombal.h"

// seleção estável: o menor não troca de lugar com v[i]; quem está entre
// eles anda uma casa para a direita, e o menor entra em v[i]
void selecao_estavel(Aluno *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].nota < v[menor].nota) { // <: no empate, fica o primeiro
                menor = j;
            }
        }
        Aluno x = v[menor];
        for (int k = menor; k > i; k--) {
            v[k] = v[k - 1];
        }
        v[i] = x;
    }
}

int main(void) {
    Aluno chamada[] = {
        {"Ana", 7, 1},   {"Bruno", 5, 2}, {"Carla", 9, 1}, {"Diego", 5, 1},
        {"Elisa", 7, 2}, {"Fabio", 3, 2}, {"Gabi", 9, 2},  {"Hugo", 5, 1},
    };
    Aluno a[8], b[8];
    for (int i = 0; i < 8; i++) {
        a[i] = chamada[i];
        b[i] = chamada[i];
    }
    pb_selecao(a, 8);
    printf("seleção comum:   ");
    pb_mostra(a, 8);
    selecao_estavel(b, 8);
    printf("seleção estável: ");
    pb_mostra(b, 8);
    return 0;
}
