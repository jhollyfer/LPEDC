// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1719 · ★★☆ · Quantas chamadas para escolher o time do futsal
//
// O técnico quer saber de quantos jeitos dá para escolher k jogadores de um
// grupo de n. A função comb(n, k) do esqueleto usa a relação de Pascal:
// C(n, k) = C(n - 1, k - 1) + C(n - 1, k), com C(n, 0) = C(n, n) = 1.
//
// Toda folha da árvore de recursão devolve 1, então ela tem exatamente
// C(n, k) folhas. E todo nó interno tem dois filhos. Numa árvore assim
// (binária cheia), nós = 2 · folhas - 1. Logo:
//
//   chamadas(n, k) = 2 C(n, k) - 1
//
// Acrescente um contador e mostre, para (6, 2), (10, 5), (20, 10) e (26, 13),
// o valor, as chamadas e 2 C(n, k) - 1. Depois escreva comb_linha(n, k), que
// calcula o mesmo número sem recursão, pela fórmula multiplicativa
// C(n, k) = C(n, k - 1) · (n - k + 1) / k, e conte as multiplicações.
//
//   Saída esperada:
//    n  k     C(n,k)  chamadas  2C-1      linha  mult
//    6  2         15        29        29         15    2
//   10  5        252       503       503        252    5
//   20 10     184756    369511    369511     184756   10
//   26 13   10400600  20801199  20801199   10400600   13
//
// Dicas:
// 1. Use long: C(26, 13) passa de 10 milhões, e as chamadas, de 20 milhões.
// 2. Na fórmula multiplicativa, faça r = r * (n - i + 1) / i para i de 1 a k,
//    nessa ordem: a divisão é sempre exata.
// 3. A recursão gasta Θ(C(n, k)) chamadas, que crescem como 2^n / √n; a
//    fórmula gasta k multiplicações.
// 4. Resposta esperada: 15, 252, 184756 e 10400600, com 29, 503, 369511 e
//    20801199 chamadas; a fórmula faz 2, 5, 10 e 13 multiplicações.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

long comb(int n, int k) {
    if (k == 0 || k == n) return 1;
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main(void) {
    printf("C(10, 5) = %ld\n", comb(10, 5));
    return 0;
}
