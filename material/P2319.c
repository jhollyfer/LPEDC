// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2319 · ★★☆ · A cerca que fecha o curral
//
// O vaqueiro estica arame entre sete mourões (M0 a M6), uma cerca por vez,
// nesta ordem:
//
//   M0-M1, M1-M2, M3-M4, M2-M3, M4-M0, M5-M6, M2-M5, M6-M1, M3-M0
//
// Cada cerca que liga dois mourões JÁ ligados por arame fecha um curral
// (um ciclo). Escreva do zero, com union-find (acha com compressão de
// caminho), um programa que diz, a cada cerca, se ela fecha um curral ou
// só estende o arame, e o total de currais. Sem DFS: o grafo cresce aresta
// por aresta e o union-find responde cada uma em tempo quase constante.
//
//   Saída esperada:
//   cerca 1 (M0-M1): só estende o arame
//   cerca 2 (M1-M2): só estende o arame
//   cerca 3 (M3-M4): só estende o arame
//   cerca 4 (M2-M3): só estende o arame
//   cerca 5 (M4-M0): fecha o curral 1
//   cerca 6 (M5-M6): só estende o arame
//   cerca 7 (M2-M5): só estende o arame
//   cerca 8 (M6-M1): fecha o curral 2
//   cerca 9 (M3-M0): fecha o curral 3
//   Currais fechados: 3
//
// Dicas:
// 1. acha(x): se pai[x] != x, pai[x] = acha(pai[x]); devolva pai[x].
// 2. Cerca a-b com acha(a) == acha(b) fecha curral; senão, junte os dois
//    grupos (pai[acha(a)] = acha(b)).
// 3. Resposta esperada: as cercas 5, 8 e 9 fecham currais; 3 no total
//    (9 cercas - 6 que bastam para ligar 7 mourões).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
