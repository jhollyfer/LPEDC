// 0128 · N-rainhas
// Exercício E767 · ★★★
//
// Ache o bug. Este programa conta as soluções do 8-rainhas e devia mostrar
// 92, mas mostra 0. Ele compila sem aviso e roda sem erro do sanitizer: os
// índices nunca saem dos vetores. O erro está numa linha só. Ache,
// conserte e rode de novo.
//
//   Saída esperada:
//   92 soluções
//   vetores limpos no fim: sim
//
// Dicas:
// 1. Uma regra do backtracking: depois que a busca termina, todo vetor de
//    marcação volta a ser o que era no começo (tudo false). A função limpos
//    confere isso. O que ela diz antes do conserto?
// 2. Compare, letra por letra, a linha que marca com a linha que desmarca.
//    Um índice errado no desmarcar não dá erro: só deixa uma diagonal
//    marcada para sempre e libera outra que estava ocupada.
// 3. Resposta esperada: o desmarcar usava diag2[c - l + N - 1]; o certo é
//    diag2[l - c + N - 1], o mesmo índice da marcação. Consertado, a saída é
//    a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define N 8

bool coluna[N];
bool diag1[2 * N - 1];
bool diag2[2 * N - 1];
int solucoes = 0;

bool limpos(void) {
    for (int k = 0; k < 2 * N - 1; k++) {
        if ((k < N && coluna[k]) || diag1[k] || diag2[k]) {
            return false;
        }
    }
    return true;
}

void rainha(int l) {
    if (l == N) {
        solucoes++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;
        }
        coluna[c] = true;
        diag1[l + c] = true;
        diag2[l - c + N - 1] = true;
        rainha(l + 1);
        coluna[c] = false;
        diag1[l + c] = false;
        diag2[c - l + N - 1] = false;
    }
}

int main(void) {
    rainha(0);
    printf("%d soluções\n", solucoes);
    printf("vetores limpos no fim: %s\n", limpos() ? "sim" : "não");
    return 0;
}
