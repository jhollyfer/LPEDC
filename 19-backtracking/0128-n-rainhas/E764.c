// 0128 · N-rainhas
// Exercício E764 · ★☆☆
//
// O programa abaixo resolve as 6-rainhas e mostra cada solução como o vetor
// pos (a coluna da rainha de cada linha). Faltam as linhas que marcam e
// desmarcam a coluna e as duas diagonais. Complete usando os índices do
// texto (l + c para a diagonal ↗ e l - c + N - 1 para a ↘).
//
//   Saída esperada:
//   1 3 5 0 2 4
//   2 5 1 4 0 3
//   3 0 4 1 5 2
//   4 2 0 5 3 1
//   4 soluções
//
// Dicas:
// 1. Marcar: coluna[c], diag1[l + c] e diag2[l - c + N - 1] recebem true,
//    logo antes da chamada rainha(l + 1).
// 2. Desmarcar: as mesmas três posições recebem false, logo depois.
// 3. Repare que as soluções vêm em pares espelhados: trocando cada c de
//    1 3 5 0 2 4 por 5 - c, sai 4 2 0 5 3 1.
// 4. Resposta esperada: as 5 linhas acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define N 6

int pos[N];
bool coluna[N];
bool diag1[2 * N - 1];
bool diag2[2 * N - 1];
int solucoes = 0;

void rainha(int l) {
    if (l == N) {
        solucoes++;
        for (int k = 0; k < N; k++) {
            printf(k == 0 ? "%d" : " %d", pos[k]);
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;
        }
        pos[l] = c;
        // complete: marque a coluna e as duas diagonais

        rainha(l + 1);
        // complete: desmarque a coluna e as duas diagonais

    }
}

int main(void) {
    rainha(0);
    printf("%d soluções\n", solucoes);
    return 0;
}
