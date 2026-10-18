// 0126 · Permutações
// Exercício E753 · ★★☆
//
// O motoboy sai da pizzaria (local 0), entrega em quatro bairros (1 a 4) e
// volta para a pizzaria. A matriz dist (em km, já no programa) diz a
// distância entre cada par de locais. Gere todas as 4! = 24 ordens de
// entrega, calcule o percurso de cada uma (ida, entregas e volta) e mostre a
// menor distância e a PRIMEIRA ordem, na ordem em que a sua recursão gera,
// que a atinge.
//
//   Saída esperada:
//   24 rotas testadas
//   menor: 16 km
//   rota: Pizzaria -> Lagoa -> Centro -> Jardim -> Vila -> Pizzaria
//
// Dicas:
// 1. Permute o vetor {1, 2, 3, 4} com trocas, como no texto. Na folha, some
//    dist[0][v[0]], depois dist[v[k]][v[k + 1]] e, no fim, dist[v[3]][0].
// 2. Guarde a melhor rota num segundo vetor, copiando v quando achar uma
//    distância MENOR (estritamente) que a melhor até agora.
// 3. A rota de trás para frente (Vila, Jardim, Centro, Lagoa) também dá
//    16 km, mas aparece depois. Por que toda rota empata com a inversa?
// 4. Resposta esperada: as 3 linhas acima. Este é o problema do caixeiro
//    viajante: com 15 bairros seriam mais de um trilhão de ordens.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define LOCAIS 5

const char *nomes[LOCAIS] = {"Pizzaria", "Centro", "Jardim", "Lagoa", "Vila"};
const int dist[LOCAIS][LOCAIS] = {
    {0, 9, 4, 2, 4},
    {9, 0, 4, 4, 9},
    {4, 4, 0, 3, 2},
    {2, 4, 3, 0, 7},
    {4, 9, 2, 7, 0},
};

int main(void) {

    return 0;
}
