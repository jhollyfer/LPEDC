// Lista · Módulo 13 · Busca e ordenação
// Exercício P1313 · ★★☆ · O bubble no melhor e no pior dia
//
// Instrumente o bubble sort com parada antecipada (para quando uma passada
// não troca nada): escreva
//
//   void bubble(int v[], int n, int *comp, int *trocas, int *passadas)
//
// que ordena v e devolve quantas comparações v[j] > v[j + 1] fez, quantas
// trocas e quantas passadas rodou. Teste com três vetores de 6 senhas:
// crescente 1 2 3 4 5 6, invertido 6 5 4 3 2 1 e misturado 4 1 6 2 5 3.
// Mostre cada linha com printf("%-10s passadas %d, comparações %2d, trocas %2d\n", ...).
//
//   Saída esperada:
//   crescente  passadas 1, comparações  5, trocas  0
//   invertido  passadas 5, comparações 15, trocas 15
//   misturado  passadas 4, comparações 14, trocas  7
//
// Dicas:
// 1. A passada p compara j de 0 a n - p - 1: n - p comparações.
// 2. O melhor caso (já ordenado) faz uma passada só: n - 1 comparações, O(n).
// 3. O pior caso (invertido) troca em toda comparação: n(n - 1)/2 = 15.
// 4. O número de trocas é igual ao número de inversões do vetor: o
//    misturado tem 7.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
