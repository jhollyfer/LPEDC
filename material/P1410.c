// Lista · Módulo 14 · Árvores
// Exercício P1410 · ★☆☆ · Montando o heap de uma vez
//
// As quantidades de 9 produtos no estoque estão num vetor desordenado:
// 4, 17, 9, 23, 8, 31, 12, 2, 19. Transforme o vetor num heap de máximo com o
// BUILD-MAX-HEAP: chame desce(v, n, i) para cada pai, do último
// (i = n / 2 - 1) até a raiz (i = 0). Mostre o vetor depois de cada desce.
// A função desce está pronta.
//
//   Saída esperada:
//   desce(3): 4 17 9 23 8 31 12 2 19
//   desce(2): 4 17 31 23 8 9 12 2 19
//   desce(1): 4 23 31 19 8 9 12 2 17
//   desce(0): 31 23 12 19 8 9 4 2 17
//
// Dicas:
// 1. Os índices de n / 2 até n - 1 são folhas: já são heaps de um elemento.
// 2. No desce(1), o 17 troca com o 23 e depois com o 19: um elemento pode
//    descer vários níveis.
// 3. Construir assim custa O(n), menos que n inserções (O(n log n)).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva o main):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

int main(void) {

    return 0;
}
