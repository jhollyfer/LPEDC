// 0102 · Heap e fila de prioridade
// Exercício E608 · ★☆☆
//
// Complete eh_heap(v, n): devolve true se o vetor v[0..n-1] for um heap de
// máximo. O main testa os vetores do E607:
//
//   Saída esperada:
//   a) heap
//   b) não é heap
//   c) heap
//   d) não é heap
//   e) heap
//
// Dicas:
// 1. Basta um laço: para i de 1 até n - 1, se v[i] > v[(i - 1) / 2], não é.
// 2. Também dá para olhar do ponto de vista do pai (filhos 2i + 1 e 2i + 2),
//    mas aí precisa conferir se os filhos existem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete eh_heap):

#include <stdio.h>
#include <stdbool.h>

bool eh_heap(const int v[], int n) {
    (void)v; // apague estas duas linhas
    (void)n;
    return false;
}

int main(void) {
    int a[] = {95, 60, 80, 20, 60, 75, 10};
    int b[] = {50, 40, 45, 42, 10, 30, 44};
    int c[] = {7};
    int d[] = {10, 20};
    int e[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("a) %s\n", eh_heap(a, 7) ? "heap" : "não é heap");
    printf("b) %s\n", eh_heap(b, 7) ? "heap" : "não é heap");
    printf("c) %s\n", eh_heap(c, 1) ? "heap" : "não é heap");
    printf("d) %s\n", eh_heap(d, 2) ? "heap" : "não é heap");
    printf("e) %s\n", eh_heap(e, 9) ? "heap" : "não é heap");
    return 0;
}
