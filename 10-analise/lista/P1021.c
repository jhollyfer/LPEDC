// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1021 · ★★★ · A melhor sequência de dias do food truck
//
// O lucro diário do food truck, em centenas de reais, nos últimos 10 dias
// foi: -3, 5, -2, 8, -10, 4, 7, -1, -7, 3. Qual sequência de dias SEGUIDOS
// deu o maior lucro somado? É o problema do subvetor de soma máxima.
// Escreva três versões, todas devolvendo a soma e preenchendo *ini e *fim
// (índices de 0 a n - 1) e contando as somas feitas em *somas:
//
//   int cubica(const int v[], int n, int *ini, int *fim, long *somas)
//     para cada par (i, j), soma v[i..j] do zero com um terceiro laço;
//   int quadratica(const int v[], int n, int *ini, int *fim, long *somas)
//     para cada i, vai somando v[j] para j = i, i + 1, ... (aproveita a
//     soma anterior);
//   int linear(const int v[], int n, int *ini, int *fim, long *somas)
//     o algoritmo de Kadane: percorre uma vez, guardando a melhor soma que
//     TERMINA no dia atual. Se essa soma ficou <= 0, recomece no dia atual.
//
// Em todas, troque a melhor só quando a nova soma for ESTRITAMENTE maior.
// Mostre os dias contando de 1.
//
//   Saída esperada:
//   Cúbica:     12 (dias 2 a 7), 220 somas
//   Quadrática: 12 (dias 2 a 7), 55 somas
//   Linear:     12 (dias 2 a 7), 10 somas
//
// Dicas:
// 1. Na cúbica, o par (i, j) faz j - i + 1 somas; no total
//    n (n + 1) (n + 2) / 6 = 220 para n = 10: Θ(n³). A quadrática faz
//    n (n + 1) / 2 = 55: Θ(n²). Kadane faz n: Θ(n).
// 2. Kadane: atual = soma da melhor sequência que termina em j. Se
//    atual <= 0, atual = v[j] e comeco = j; senão, atual += v[j]. Conte 1
//    soma por dia.
// 3. O invariante de Kadane: depois de processar o dia j, melhor é a maior
//    soma de um subvetor de v[0..j].
// 4. Resposta esperada: a saída acima (5 - 2 + 8 - 10 + 4 + 7 = 12).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
