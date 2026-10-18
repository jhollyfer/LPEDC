// 0162 · Matriz esparsa
// Exercício E968 · ★☆☆
//
// O estacionamento do shopping tem 4 andares com 6 vagas cada. A matriz
// andar x vaga guarda há quantas horas cada carro está parado; vaga livre
// vale 0. O sistema guarda só as triplas (andar, vaga, horas), em ordem.
// Escreva:
// - valor(t, n, i, j), que procura a tripla (i, j) e devolve as horas, ou 0
//   se ela não existir;
// - o main, que usa valor para imprimir a matriz cheia (cada número com
//   %3d) e, no fim, o total de horas.
//
//   Saída esperada:
//     0  0  2  0  0  0
//     5  0  0  0  1  0
//     0  0  0  0  0  0
//     0  3  0  0  0  4
//   Total: 15 horas em 5 vagas ocupadas
//
// Dicas:
// 1. valor é uma busca sequencial no vetor de triplas: compare lin e col.
// 2. O total não precisa da matriz cheia: some t[k].horas direto nas triplas.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int lin, col, horas;
} Tripla;

int main(void) {
    const Tripla vagas[] = {{0, 2, 2}, {1, 0, 5}, {1, 4, 1}, {3, 1, 3}, {3, 5, 4}};
    int n = 5;
    (void)vagas; // apague estas duas linhas
    (void)n;

    return 0;
}
