// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1919 · ★★☆ · Rainhas no tabuleiro furado
//
// O tabuleiro 6 × 6 do clube tem casas estragadas, marcadas com X, onde não
// dá para pôr peça. A rainha ainda ataca POR CIMA das casas estragadas (o
// furo não bloqueia o ataque). Quantas soluções das 6-rainhas sobram? O
// programa abaixo é o das N-rainhas do assunto 0128, que conta 4 soluções
// sem furos. Estenda-o: não coloque rainha numa casa X e mostre cada
// solução que sobra como o vetor de colunas, além do total.
//
//   Saída esperada:
//   pos = 2 5 1 4 0 3
//   pos = 4 2 0 5 3 1
//   Soluções: 2
//
// Dicas:
// 1. Basta um teste a mais no laço: if (tab[lin][col] == 'X') continue;
// 2. Para mostrar o vetor, guarde pos[lin] = col ao colocar a rainha.
// 3. Resposta esperada: sobram 2 soluções.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char tab[N][N + 1] = {
    "......",
    "...X..",
    "......",
    "X.....",
    "......",
    "..X...",
};
bool col_ocup[N], d1[2 * N], d2[2 * N];
int pos[N];
int solucoes = 0;

void coloca(int lin) {
    if (lin == N) {
        solucoes++;
        return;
    }
    for (int col = 0; col < N; col++) {
        int a = lin - col + N - 1, b = lin + col;
        if (col_ocup[col] || d1[a] || d2[b]) {
            continue;
        }
        col_ocup[col] = d1[a] = d2[b] = true;
        coloca(lin + 1);
        col_ocup[col] = d1[a] = d2[b] = false;
    }
}

int main(void) {
    coloca(0);
    printf("Soluções: %d\n", solucoes);
    return 0;
}
