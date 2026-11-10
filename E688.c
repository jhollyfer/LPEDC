// 0115 · Teorema mestre
// Exercício E688 · ★★☆
//
// Escreva duas buscas recursivas em v[0..N-1] = 0, 2, 4, ... (N = 1000000),
// contando cada comparação com v[...]. binaria(ini, fim, x): compara x ==
// v[meio] e depois x < v[meio]. ternaria(ini, fim, x): com terco = (fim -
// ini) / 3, m1 = ini + terco e m2 = fim - 1 - terco, compara x == v[m1], x ==
// v[m2], x < v[m1] e x > v[m2]. Faça 1000 buscas por números ímpares, x = 2 *
// ((i * 7919) % N) + 1 (i de 0 a 999), e mostre a média de comparações de
// cada uma.
//
//   Saída esperada:
//   binária: 39.9 comparações por busca
//   ternária: 47.3 comparações por busca
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 1000000

int v[N];
long comparacoes = 0;

int main(void) {
    for (int i = 0; i < N; i++) {
        v[i] = 2 * i; // só pares
    }

    return 0;
}
