// 0128 · N-rainhas
// Exercício E767 · ★★★
//
// Resposta: o desmarcar da diagonal ↘ usava c - l em vez de l - c. O índice
// continuava dentro do vetor, mas apontava para a diagonal espelhada: a
// diagonal certa ficava marcada para sempre (podando casas livres) e outra
// era liberada sem nunca ter sido ocupada.

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
        diag2[l - c + N - 1] = false; // o mesmo índice da marcação
    }
}

int main(void) {
    rainha(0);
    printf("%d soluções\n", solucoes);
    printf("vetores limpos no fim: %s\n", limpos() ? "sim" : "não");
    return 0;
}
