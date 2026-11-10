// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1801 · ★☆☆ · Counting sort passo a passo: o vetor C e a saída
//
// No posto de vacinação, as idades das 10 crianças da fila (0 a 4 anos) vão
// para o relatório em ordem. Escreva do zero o counting sort do Cormen e
// mostre o estado dos vetores como a prova pede:
//
// 1. C depois da contagem (C[x] = quantas crianças têm x anos);
// 2. C depois das somas acumuladas (C[x] = quantas têm idade <= x);
// 3. cada passo da colocação, de trás para frente: o valor, a posição em que
// ele entra na saída B e o vetor C logo depois;
// 4. o vetor B no fim.
//
// Use posições de 0 a n - 1 (em C, decremente antes de usar).
//
//   Saída esperada:
//   Contagem: C = 1 3 1 2 3
//   Acumulado: C = 1 4 5 7 10
//   A[9] = 1 vai para B[3] | C = 1 3 5 7 10
//   A[8] = 3 vai para B[6] | C = 1 3 5 6 10
//   A[7] = 4 vai para B[9] | C = 1 3 5 6 9
//   A[6] = 1 vai para B[2] | C = 1 2 5 6 9
//   A[5] = 2 vai para B[4] | C = 1 2 4 6 9
//   A[4] = 0 vai para B[0] | C = 0 2 4 6 9
//   A[3] = 4 vai para B[8] | C = 0 2 4 6 8
//   A[2] = 3 vai para B[5] | C = 0 2 4 5 8
//   A[1] = 1 vai para B[1] | C = 0 1 4 5 8
//   A[0] = 4 vai para B[7] | C = 0 1 4 5 7
//   B = 0 1 1 1 2 3 3 4 4 4
//
// Dicas:
// 1. Depois da soma acumulada, C[x] - 1 é a ÚLTIMA posição livre do bloco
//    dos x: por isso o laço da colocação anda de trás para frente e
//    decrementa antes de gravar.
// 2. Mostre C com uma função que recebe um rótulo, como mostra("C:", c).
// 3. O último elemento de A (1) é o primeiro a ser colocado: vai para a
//    última posição do bloco dos 1.
// 4. Resposta esperada: C = 1 3 1 2 3 depois da contagem, 1 4 5 7 10 depois
//    das somas, e B = 0 1 1 1 2 3 3 4 4 4.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 10
#define K 5 // idades de 0 a 4

int main(void) {
    int a[N] = {4, 1, 3, 4, 0, 2, 1, 4, 3, 1};

    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
