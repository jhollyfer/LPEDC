// 0185 · Cadeia de matrizes
// Exercício E1106 · ★☆☆
//
// A tabela s diz onde cortar; o servidor precisa da LISTA de
// multiplicações, na ordem em que vão ser feitas. O programa abaixo já
// preenche m e s para cinco matrizes (p = 8, 20, 4, 15, 6, 25). Escreva a
// função int executa(int i, int j), que percorre a árvore de cortes em
// pós-ordem (primeiro as duas metades, depois a junção), numera cada
// intermediária (M1, M2, ...) e mostra cada multiplicação com as dimensões
// e o custo. Ela devolve o número da intermediária criada, ou 0 quando
// i == j (aí a "matriz" é a própria Ai).
//
//   Saída esperada:
//   M1 = A1 x A2  (8x20 por 20x4: 640)
//   M2 = A3 x A4  (4x15 por 15x6: 360)
//   M3 = M1 x M2  (8x4 por 4x6: 192)
//   M4 = M3 x A5  (8x6 por 6x25: 1200)
//   Total: 2392
//
// Dicas:
// 1. Com k = s[i][j], chame executa(i, k) e executa(k + 1, j) ANTES de
//    mostrar a multiplicação atual. Um contador global dá o número da nova.
// 2. A junção é uma p[i-1] x p[k] por uma p[k] x p[j].
// 3. Resposta esperada: a saída acima. Os custos somam m[1][5] = 2392.
//
// Escreva sua resposta abaixo (complete a função executa):

#include <limits.h>
#include <stdio.h>

#define N 5

const int p[N + 1] = {8, 20, 4, 15, 6, 25};
long m[N + 1][N + 1];
int s[N + 1][N + 1];
int contador = 0; // numera as intermediárias M1, M2, ...

int executa(int i, int j) {
    (void)i, (void)j; // apague esta linha ao escrever a função
    return 0;
}

int main(void) {
    for (int tam = 2; tam <= N; tam++)
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {
                long c = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (c < m[i][j]) m[i][j] = c, s[i][j] = k;
            }
        }
    executa(1, N);
    printf("Total: %ld\n", m[1][N]);
    return 0;
}
