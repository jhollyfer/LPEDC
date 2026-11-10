// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2915 · ★★☆ · A rede é robusta?
//
// Uma rede é "robusta" para a operadora quando é conexa e nenhum cabo
// sozinho a desconecta (não tem ponte). Escreva void avalia(const char *nome,
// int nv, int ne, int c[][2]) que conta os componentes e as pontes (uma
// DFS com tin e low por componente) e dá o veredito. Teste:
//
//   R1 (6 nós): 0-1, 1-2, 2-0, 3-4, 4-5, 5-3
//   R2 (6 nós): 0-1, 1-2, 2-0, 2-3, 3-4, 4-5, 5-3
//   R3 (6 nós): 0-1, 1-2, 2-3, 3-4, 4-5, 5-0, 0-3
//
//   Saída esperada:
//   R1: 2 componente(s), 0 ponte(s): frágil
//   R2: 1 componente(s), 1 ponte(s): frágil
//   R3: 1 componente(s), 0 ponte(s): robusta
//
// Dicas:
// 1. Zere tin[] a cada rede. O laço externo começa uma DFS em cada nó ainda
//    não visitado: cada começo é um componente.
// 2. Robusta = 1 componente e 0 pontes.
// 3. Resposta esperada: a saída acima. R1 não tem ponte, mas está partida em
//    dois; R2 está inteira, mas o cabo 2-3 é ponte.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
