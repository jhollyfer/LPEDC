// 0185 · Cadeia de matrizes
// Exercício E1105 · ★☆☆

#include <stdio.h>

long custo(int p, int q, int r) { // (p x q) vezes (q x r)
    return (long)p * q * r;
}

int main(void) {
    // A: 50 x 10, B: 10 x 40, C: 40 x 30
    long esquerda = custo(50, 10, 40) + custo(50, 40, 30); // (A B) dá 50 x 40
    long direita = custo(10, 40, 30) + custo(50, 10, 30);  // (B C) dá 10 x 30
    printf("(A B) C: %ld multiplicações\n", esquerda);
    printf("A (B C): %ld multiplicações\n", direita);
    printf("Melhor: %s, %.1f vezes mais barata\n", esquerda < direita ? "(A B) C" : "A (B C)",
           esquerda < direita ? (double)direita / esquerda : (double)esquerda / direita);
    return 0;
}
