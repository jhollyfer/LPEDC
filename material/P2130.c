// Lista · Módulo 21 · Programação dinâmica
// Exercício P2130 · ★★★ · O caixeiro viajante do Amazonas
//
// Um vendedor sai de Manaus, visita Itacoatiara, Manacapuru, Parintins,
// Tefé e Coari (cada uma uma vez) e volta a Manaus. As distâncias (em
// horas de barco, num mapa simplificado) estão na matriz do main. Testar
// as 5! = 120 ordens funciona, mas com 20 cidades seriam 19! (mais de 10^17).
// A PD de HELD-KARP faz O(2^n · n²): custo[S][v] é o menor tempo para sair
// de Manaus, passar por TODAS as cidades do conjunto S (uma máscara de
// bits) e terminar em v (v está em S). Então
//
//   custo[S][v] = min, para u em S sem v, de custo[S sem v][u] + dist[u][v]
//
// e a resposta é o min de custo[todas][v] + dist[v][0]. Escreva do zero a
// PD, reconstrua a rota e confira com a força bruta das permutações.
//
//   Saída esperada:
//   Held-Karp: 94 horas
//   Rota: Manaus > Manacapuru > Coari > Tefé > Parintins > Itacoatiara > Manaus
//   Força bruta: 94 horas
//
// Dicas:
// 1. As cidades 1 a 5 são os bits 0 a 4 de S (cidade v é o bit v - 1).
//    custo[{v}][v] = dist[0][v]. Percorra S em ordem crescente: todo
//    subconjunto de S é menor que S.
// 2. Guarde em pai[S][v] o u que deu o mínimo; para reconstruir, ande de
//    (todas, último) tirando v de S a cada passo.
// 3. Resposta esperada: o tempo mínimo e a rota da saída, iguais nos dois
//    métodos. A PD preenche 32 · 5 casas; a força bruta, 120 rotas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
