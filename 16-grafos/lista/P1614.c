// Lista · Módulo 16 · Grafos
// Exercício P1614 · ★★☆ · O anel na rede de água: ache e mostre o ciclo
//
// A rede de canos de água de um bairro liga sete pontos (não dirigido). Para
// a manutenção, interessa saber se existe um ANEL (ciclo) e por onde ele
// passa: num anel, a água chega a um ponto por dois caminhos.
//
// Escreva uma DFS com pai[] que, ao achar uma aresta u-v com v já visitado e
// v != pai[u] (aresta de retorno), mostre o ciclo inteiro subindo por pai[] de
// u até v. Pare na primeira que achar. Rode na rede do esqueleto e, depois,
// sem o cano Valvula-Caixa.
//
//   Saída esperada:
//   Ciclo: Posto -> Escola -> Caixa -> Valvula -> Posto
//   Sem Valvula-Caixa: sem ciclo
//
// Dicas:
// 1. Num grafo não dirigido, a aresta para o pai não conta: é o mesmo cano
//    por onde a DFS chegou.
// 2. Quando u enxerga um v visitado que não é o pai, v é um ancestral de u
//    na árvore da DFS. Subir de u por pai[] até v percorre o ciclo.
// 3. Use uma variável global achou para parar a DFS assim que o ciclo for
//    mostrado.
// 4. Resposta esperada: o ciclo Valvula -> Caixa -> Escola -> Posto -> Valvula
//    (mostrado a partir de quem fecha o ciclo, subindo até Valvula) e, sem o
//    cano, "sem ciclo".
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *nomes[V] = {"Reservatorio", "Valvula", "Caixa", "Escola", "Posto", "Feira", "Praca"};
int adj[V][V];

int main(void) {
    int canos[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}, {0, 5}, {5, 6}};
    for (int k = 0; k < 7; k++) adj[canos[k][0]][canos[k][1]] = adj[canos[k][1]][canos[k][0]] = 1;

    return 0;
}
