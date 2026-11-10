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
