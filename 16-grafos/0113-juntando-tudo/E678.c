// 0113 · Juntando tudo: a central de entregas
// Exercício E678 · ★★★
//
// O Dijkstra do módulo custa O(V²): para achar o menor dist ele varre o
// vetor todo. Escreva a versão "de verdade", com LISTA de adjacência
// (malloc) e um HEAP mínimo de pares (dist, vértice) (assunto 0102), para o
// mapa rodoviário abaixo (km, mão dupla), saindo de Porto Alegre:
//
//   Porto Alegre-Canoas 15, Canoas-Novo Hamburgo 25,
//   Novo Hamburgo-Gramado 60, Porto Alegre-Gramado 115,
//   Novo Hamburgo-Caxias 90, Gramado-Caxias 45, Caxias-Bento 40,
//   Porto Alegre-Torres 200, Caxias-Torres 210, Porto Alegre-Pelotas 260,
//   Canoas-Caxias 120
//
// Índices: Porto Alegre 0, Canoas 1, Novo Hamburgo 2, Gramado 3, Caxias 4,
// Bento 5, Torres 6, Pelotas 7. Conte quantos itens saem do heap.
//
//   Saída esperada:
//   Canoas         15 km
//   Novo Hamburgo  40 km
//   Gramado       100 km
//   Caxias        130 km
//   Bento         170 km
//   Torres        200 km
//   Pelotas       260 km
//   Itens tirados do heap: 10
//
// Dicas:
// 1. Truque que dispensa "diminuir chave": sempre que dist[v] melhorar,
//    empurre (dist nova, v) no heap. Ao tirar um item com dist maior que
//    dist[v], ele é velho: ignore.
// 2. Por isso o heap pode ter mais que V itens: cada aresta empurra no
//    máximo duas vezes, então 2E + 1 posições bastam.
// 3. Libere todos os nós das listas no fim (o rodar acusa vazamento).
// 4. Resposta esperada: a saída acima. Saem 10 itens: os 8 vértices e 2
//    velhos (Gramado com 115 e Caxias com 135), que foram superados antes
//    de sair.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
