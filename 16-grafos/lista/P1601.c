// Lista · Módulo 16 · Grafos
// Exercício P1601 · ★☆☆ · Grau das paradas e número de linhas
//
// A matriz do esqueleto liga seis bairros de Manaus por linhas de ônibus
// diretas, de ida e volta (grafo NÃO dirigido): adj[i][j] == 1 quer dizer que
// uma linha liga i e j. Escreva do zero um programa que mostre:
//
// - o grau de cada bairro (quantas linhas saem dele);
// - a soma dos graus e o número de linhas (arestas), calculado pela soma;
// - o bairro com o maior grau (no empate, o de menor índice);
// - os bairros "ponta de linha", com grau 1.
//
//   Saída esperada:
//   Centro        grau 3
//   Adrianopolis  grau 3
//   Cidade Nova   grau 2
//   Ponta Negra   grau 1
//   Compensa      grau 2
//   Aleixo        grau 3
//   Soma dos graus: 14
//   Linhas (arestas): 7
//   Maior grau: Centro (3)
//   Ponta de linha: Ponta Negra
//
// Dicas:
// 1. O grau de i é a soma da linha i da matriz.
// 2. Cada aresta i-j aparece duas vezes na matriz (adj[i][j] e adj[j][i]):
//    por isso a soma dos graus é sempre o dobro do número de arestas.
// 3. Para o maior grau, troque o campeão só quando o grau for estritamente
//    maior: assim o empate fica com o primeiro.
// 4. Resposta esperada: soma dos graus 14, 7 linhas, maior grau Centro (3),
//    e a única ponta de linha é Ponta Negra.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Centro", "Adrianopolis", "Cidade Nova", "Ponta Negra", "Compensa", "Aleixo"};
int adj[V][V] = {
    {0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 0},
};

int main(void) {

    return 0;
}
