// 0115 · Teorema mestre
// Exercício E685 · ★☆☆
//
// Escreva "int caso(int a, int b, int k)": recebe T(n) = a T(n/b) + n^k e
// devolve o caso do teorema mestre (1 se a > b^k, 2 se a = b^k, 3 se a < b^k),
// com b^k calculado em inteiros por uma função potencia(b, k) com laço. Teste
// as recorrências (a, b, k) = (2,2,1), (4,2,1), (1,2,1), (9,3,2), (5,4,1),
// (2,4,1) e (16,4,2), mostrando o caso e a classe: folhas Θ(n^(log_b a)),
// empate Θ(n^k log n) ou raiz Θ(n^k).
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
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
