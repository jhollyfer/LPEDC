// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2330 · ★★★ · Quantas ruas novas no centro histórico
//
// No centro histórico, todas as ruas são de mão única. Hoje não dá para
// ir de qualquer largo a qualquer outro. A prefeitura quer abrir o MÍNIMO
// de ruas novas (também de mão única) para que dê. As ruas:
//
//   Sé -> Carmo, Carmo -> Rosário, Rosário -> Sé, Rosário -> Mercado,
//   Mercado -> Teatro, Teatro -> Mercado, Carmo -> Matriz,
//   Cais -> Matriz, Estação -> Feira, Feira -> Estação, Estação -> Sé
//
// O resultado clássico: encolha cada componente fortemente conexo num
// ponto só (o grafo vira um DAG). Conte as FONTES (grupos onde nenhuma
// rua chega de fora) e os SUMIDOUROS (de onde nenhuma rua sai para
// fora). Se houver mais de um grupo, a resposta é max(fontes,
// sumidouros); com um grupo só, 0. Escreva do zero: Kosaraju, a marcação
// de quem entra e quem sai de cada grupo, e a resposta.
//
//   Saída esperada:
//   Grupo 1: Estação Feira (ninguém chega)
//   Grupo 2: Cais (ninguém chega)
//   Grupo 3: Sé Carmo Rosário
//   Grupo 4: Matriz (não sai)
//   Grupo 5: Mercado Teatro (não sai)
//   Fontes: 2, sumidouros: 2
//   Ruas novas, no mínimo: 2
//
// Dicas:
// 1. Índices 0 a 8 na ordem Sé, Carmo, Rosário, Mercado, Teatro, Matriz,
//    Cais, Estação, Feira. Rode a 1ª DFS com u de 0 a 8 e numere os
//    grupos na ordem da 2ª passada.
// 2. Só contam as setas a -> b com grupo[a] != grupo[b]: elas marcam
//    sai[grupo[a]] e entra[grupo[b]].
// 3. Resposta esperada: 5 grupos, 2 fontes ({Estação, Feira} e {Cais}),
//    2 sumidouros ({Matriz} e {Mercado, Teatro}): 2 ruas novas.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
