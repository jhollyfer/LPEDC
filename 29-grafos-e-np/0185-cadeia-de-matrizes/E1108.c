// 0185 · Cadeia de matrizes
// Exercício E1108 · ★★☆
//
// Para convencer o chefe de que vale a pena pensar na ordem, o analista
// quer mostrar a melhor e a PIOR ordem de uma cadeia de cinco matrizes,
// p = 40, 5, 50, 2, 30, 8. Escreva o programa que preenche duas tabelas ao
// mesmo tempo (mínimo e máximo, cada uma com o seu s), mostra as duas
// parentizações com os custos e quantas vezes a pior custa a melhor.
//
//   Saída esperada:
//   Melhor: ((A1 (A2 A3)) (A4 A5)) = 2020
//   Pior:   (((A1 A2) (A3 A4)) A5) = 82600
//   A pior custa 40.9 vezes a melhor
//
// Dicas:
// 1. A recorrência do máximo é a mesma, trocando min por max (e começando
//    com -1 em vez de LONG_MAX). A subestrutura ótima vale para os dois.
// 2. Uma função mostra(s, i, j) recebe a tabela de cortes como parâmetro:
//    void mostra(int s[N + 1][N + 1], int i, int j).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>

int main(void) {

    return 0;
}
