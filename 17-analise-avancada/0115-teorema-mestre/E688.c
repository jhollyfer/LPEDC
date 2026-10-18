// 0115 · Teorema mestre
// Exercício E688 · ★★☆
//
// Se dividir ao meio dá log₂ n, dividir em três não seria melhor? Teste.
// Escreva duas buscas RECURSIVAS num vetor ordenado v[0..N-1] com os
// números pares 0, 2, 4, ..., contando cada comparação com um elemento do
// vetor (cada == , < ou > com v[...]):
//
// - binaria(ini, fim, x): compara x == v[meio]; depois x < v[meio] e segue
// numa metade. T(n) = T(n/2) + 2.
// - ternaria(ini, fim, x): com terco = (fim - ini) / 3, m1 = ini + terco e
// m2 = fim - 1 - terco, compara x == v[m1], x == v[m2], x < v[m1] e
// x > v[m2], e segue num dos três pedaços. T(n) = T(n/3) + 4.
//
// Pelo teorema, as duas são caso 2, Θ(log n). Mas a constante importa.
// Faça 1000 buscas por números ÍMPARES (que não estão no vetor), com
// x = 2 * ((i * 7919) % N) + 1 para i de 0 a 999, e mostre a média:
//
//   Saída esperada:
//   binária: 39.9 comparações por busca
//   ternária: 47.3 comparações por busca
//
// Dicas:
// 1. Use intervalo semiaberto [ini, fim): o pedaço vazio (ini >= fim)
//    devolve -1. Os três pedaços da ternária são [ini, m1), [m1 + 1, m2) e
//    [m2 + 1, fim).
// 2. (long)i * 7919 evita estouro? Aqui não estoura, mas é bom hábito.
// 3. Por que perde? A binária gasta 2 comparações para dividir por 2
//    (2 · log₂ n ≈ 40). A ternária gasta até 4 para dividir por 3
//    (4 · log₃ n ≈ 4 · 12,6 ≈ 50; um pouco menos, porque às vezes para
//    na terceira). Θ igual não quer dizer tempo igual.
// 4. Resposta esperada: a saída acima.
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
