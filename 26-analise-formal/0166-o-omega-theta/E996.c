// 0166 · O, Ω e Θ de verdade
// Exercício E996 · ★★★
//
// Ache as duas fatias do sanduíche do Θ por busca. A função abaixo confere
// cada cliente da fila e cada par de clientes uma vez. Acrescente um
// contador global de passos (um passo para o cliente sozinho e um para
// cada par), rode confere_pares para todo n de 10 até 2000 e guarde o
// menor (c1) e o maior (c2) valor de passos / n². Depois mostre a
// contagem para n = 1000 ao lado da fórmula n(n+1)/2:
//
//   Saída esperada:
//   de n = 10 a 2000: c1 = 0.5002, c2 = 0.5500
//   n = 1000: 500500 passos, n(n+1)/2 = 500500
//   f(n) = Θ(n²) com c1 = 0.5, c2 = 0.55 e n0 = 10
//
// Dicas:
// 1. passos++ antes do laço de dentro (o cliente sozinho) e passos++ dentro
//    dele (o par).
// 2. A razão é (n + 1) / (2n): começa em 0.55 com n = 10 e desce para 0.5
//    sem nunca chegar lá. Por isso c1 = 0.5 serve para todo n.
// 3. Calcule a razão em double: (double)passos / ((double)n * n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

// confere cada par de clientes da fila uma vez, e cada cliente sozinho
void confere_pares(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // compara o cliente i com o cliente j
        }
    }
}

int main(void) {
    confere_pares(1000);
    printf("pares conferidos para n = 1000\n");
    return 0;
}
