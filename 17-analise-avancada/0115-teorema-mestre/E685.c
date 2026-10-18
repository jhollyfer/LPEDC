// 0115 · Teorema mestre
// Exercício E685 · ★☆☆
//
// Complete a função caso(a, b, k): ela recebe uma recorrência
// T(n) = a T(n/b) + n^k e devolve o número do caso do teorema mestre
// (1 se a > b^k, 2 se a = b^k, 3 se a < b^k). Calcule b^k com inteiros,
// numa função potencia(b, k) com um laço. O main já testa sete
// recorrências:
//
//   Saída esperada:
//    2 T(n/2) + n^1 -> caso 2, empate: Θ(n^k log n)
//    4 T(n/2) + n^1 -> caso 1, folhas: Θ(n^(log_b a))
//    1 T(n/2) + n^1 -> caso 3, raiz: Θ(n^k)
//    9 T(n/3) + n^2 -> caso 2, empate: Θ(n^k log n)
//    5 T(n/4) + n^1 -> caso 1, folhas: Θ(n^(log_b a))
//    2 T(n/4) + n^1 -> caso 3, raiz: Θ(n^k)
//   16 T(n/4) + n^2 -> caso 2, empate: Θ(n^k log n)
//
// Dicas:
// 1. potencia(b, k) começa com p = 1 e multiplica por b, k vezes. Use long.
// 2. Depois são dois if: a > bk devolve 1; a == bk devolve 2; senão, 3.
// 3. Resposta esperada: a saída acima. Repare no 9 T(n/3) + n²: 9 = 3²,
//    então é empate, Θ(n² log n).
//
// Escreva sua resposta abaixo (complete caso e crie potencia):

#include <stdio.h>

int caso(int a, int b, int k) {
    (void)a; // apague estas três linhas
    (void)b;
    (void)k;
    return 0;
}

int main(void) {
    int r[][3] = {{2, 2, 1}, {4, 2, 1}, {1, 2, 1}, {9, 3, 2}, {5, 4, 1}, {2, 4, 1}, {16, 4, 2}};
    const char *resposta[] = {"???", "folhas: Θ(n^(log_b a))", "empate: Θ(n^k log n)", "raiz: Θ(n^k)"};
    for (int i = 0; i < 7; i++) {
        int c = caso(r[i][0], r[i][1], r[i][2]);
        printf("%2d T(n/%d) + n^%d -> caso %d, %s\n", r[i][0], r[i][1], r[i][2], c, resposta[c]);
    }
    return 0;
}
