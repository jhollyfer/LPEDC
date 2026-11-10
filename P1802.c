// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1802 · ★☆☆ · Shell sort com os saltos de Shell: n/2, n/4, ..., 1
//
// Os saltos originais de Donald Shell (1959) são n/2, n/4, ..., 1 (divisão
// inteira). Ordene as alturas, em cm, dos 10 atletas do time de basquete da
// escola com essa sequência e mostre o vetor depois de cada passada, junto
// com o salto e as comparações feitas naquela passada.
//
// Cada passada com salto h é um insertion sort que compara v[j] com
// v[j - h] em vez de v[j - 1].
//
//   Saída esperada:
//   início: 190 175 201 168 183 178 194 172 186 181
//   h = 5:  178 175 172 168 181 190 194 201 186 183  (5 comparações)
//   h = 2:  172 168 178 175 181 183 186 190 194 201  (11 comparações)
//   h = 1:  168 172 175 178 181 183 186 190 194 201  (10 comparações)
//
// Dicas:
// 1. for (h = n / 2; h >= 1; h /= 2), e dentro o insertion sort com passo h:
//    para i de h até n - 1, desloque de h em h enquanto v[j - h] > x.
// 2. Conte uma comparação a cada teste v[j - h] > x que chega a ser feito
//    (quando j - h >= 0).
// 3. Com n = 10, os saltos são 5, 2 e 1. Na última passada, o vetor já está
//    quase ordenado e o insertion sort trabalha pouco.
// 4. Resposta esperada: o vetor final 168 172 175 178 181 183 186 190 194
//    201, com 5, 11 e 10 comparações nas três passadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 10

int main(void) {
    int alturas[N] = {190, 175, 201, 168, 183, 178, 194, 172, 186, 181};

    for (int i = 0; i < N; i++) printf("%d ", alturas[i]);
    printf("\n");
    return 0;
}
