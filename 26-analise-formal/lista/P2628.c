// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2628 · ★★★ · Estimando o expoente
//
// Três funções sem documentação. Instrumente cada uma com um contador de
// passos (no laço mais interno), rode com n = 4096 e n = 8192 e estime o
// expoente p do custo n^p por p = log2(passos(2n) / passos(n)). Mostre os
// passos e o p estimado com 3 casas:
//
//   Saída esperada:
//   a:   176736 ->   498316, p = 1.495
//   b:  8386560 -> 33550336, p = 2.000
//   c:    49152 ->   106496, p = 1.115
//
// Dicas:
// 1. a: o laço de dentro roda enquanto j * j < i: uns sqrt(i) passos, e a
//    soma dá uns (2/3) n^1,5.
// 2. b: laço dependente j < i: n(n-1)/2, p perto de 2.
// 3. c: o de fora dobra e o de dentro anda n: n log n. O p sai um pouco acima
//    de 1 (o log engana o expoente).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>
#include <math.h>

void funcao_a(long n) {
    for (long i = 0; i < n; i++) {
        for (long j = 0; j * j < i; j++) {
        }
    }
}

void funcao_b(long n) {
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
        }
    }
}

void funcao_c(long n) {
    for (long i = 1; i < n; i *= 2) {
        for (long j = 0; j < n; j++) {
        }
    }
}

int main(void) {
    funcao_a(4096);
    funcao_b(4096);
    funcao_c(4096);
    printf("log2(8) = %.0f\n", log2(8));
    return 0;
}
