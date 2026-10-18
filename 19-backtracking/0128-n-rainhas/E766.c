// 0128 · N-rainhas
// Exercício E766 · ★★☆
//
// Na sala de prova, as carteiras formam uma grade n × n. O fiscal vai
// sentar n alunos: um em cada fileira (linha) e um em cada coluna. A regra
// contra cola é mais fraca que a da rainha: dois alunos de fileiras VIZINHAS
// não podem estar em colunas vizinhas (aí um enxerga a prova do outro na
// diagonal). Alunos em fileiras mais distantes podem estar na diagonal sem
// problema.
//
// O programa abaixo conta as soluções das n-rainhas para n = 4, 5 e 6.
// Estenda-o (mudando a poda e o que for preciso) para contar as arrumações
// da sala de prova e mostrar a primeira de cada n.
//
//   Saída esperada:
//   n = 4: 2 arrumações, primeira: 1 3 0 2
//   n = 5: 14 arrumações, primeira: 0 2 4 1 3
//   n = 6: 90 arrumações, primeira: 0 2 4 1 3 5
//
// Dicas:
// 1. A coluna continua proibida de repetir. As diagonais saem: o único
//    teste novo compara c com pos[l - 1], e só quando l > 0.
// 2. "Colunas vizinhas" quer dizer abs(c - pos[l - 1]) == 1.
// 3. Guarde a primeira arrumação de cada n num vetor separado.
// 4. Resposta esperada: as 3 linhas acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n;
int pos[MAX];
bool coluna[MAX];
bool diag1[2 * MAX - 1];
bool diag2[2 * MAX - 1];
int solucoes;

void rainha(int l) {
    if (l == n) {
        solucoes++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + n - 1]) {
            continue;
        }
        pos[l] = c;
        coluna[c] = diag1[l + c] = diag2[l - c + n - 1] = true;
        rainha(l + 1);
        coluna[c] = diag1[l + c] = diag2[l - c + n - 1] = false;
    }
}

int main(void) {
    for (n = 4; n <= 6; n++) {
        solucoes = 0;
        rainha(0);
        printf("n = %d: %d soluções das rainhas\n", n, solucoes);
    }
    return 0;
}
