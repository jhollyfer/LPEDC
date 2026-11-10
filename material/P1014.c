// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1014 · ★★☆ · Separar débitos e créditos no lugar
//
// O extrato do mês tem os lançamentos 120, -30, 45, -80, -10, 60, 0 e -5.
// Escreva int separa(int v[], int n), que deixa todos os negativos (os
// débitos) no começo do vetor, sem vetor auxiliar, e devolve quantos são.
// Use um índice i (a fronteira) e um j que percorre o vetor: quando v[j] é
// negativo, troque v[i] com v[j] e avance i. Conte as trocas.
//
// Ponha no começo de cada volta um assert com o invariante: v[0..i-1] são
// todos negativos e v[i..j-1] são todos >= 0. Escreva a função auxiliar
// bool invariante(const int v[], int i, int j) para isso.
//
//   Saída esperada:
//   Débitos: -30 -80 -10 -5
//   Créditos: 45 60 0 120
//   Trocas: 4
//
// Dicas:
// 1. Comece com i = 0 e j de 0 a n - 1. Com j = 0, as duas faixas estão
//    vazias, e o invariante vale "de graça".
// 2. No fim, j == n: o invariante diz que v[0..i-1] < 0 e v[i..n-1] >= 0.
//    É exatamente o que se queria, e i é a resposta.
// 3. A função é O(n): cada j é visto uma vez. A ordem dentro de cada grupo
//    muda (o 120 foi para o fim): essa partição não é estável.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
