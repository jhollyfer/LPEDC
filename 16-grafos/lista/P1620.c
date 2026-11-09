// Lista · Módulo 16 · Grafos
// Exercício P1620 · ★★☆ · A celebridade da festa em O(V)
//
// Na festa de lançamento de um livro, conhece[i][j] == 1 quer dizer que i
// conhece j (grafo DIRIGIDO: conhecer não é recíproco). A CELEBRIDADE é quem
// todos conhecem e não conhece ninguém: em grafos, um vértice com grau de
// entrada V - 1 e grau de saída 0 (o "sumidouro universal" do Cormen).
//
// Olhar a matriz inteira custa V² consultas. Escreva int celebridade(int
// c[V][V]) com no máximo 3(V - 1) consultas: devolve o índice ou -1. Conte as
// consultas e teste nas duas festas do esqueleto.
//
//   Saída esperada:
//   Festa 1: Rubem (15 consultas de 36)
//   Festa 2: sem celebridade (13 consultas de 36)
//
// Dicas:
// 1. Eliminação: comece com candidato = 0. Para i de 1 a V - 1, se o
//    candidato conhece i, ele não é celebridade (e i ainda pode ser): troque o
//    candidato por i. Se não conhece, i não é celebridade (alguém não o
//    conhece). Cada consulta elimina uma pessoa: V - 1 consultas.
// 2. Sobra um candidato, que ainda precisa ser conferido: para todo i !=
//    candidato, c[candidato][i] == 0 e c[i][candidato] == 1. Mais 2(V - 1)
//    consultas, no máximo.
// 3. Faça a consulta passar por uma função que soma 1 num contador global.
// 4. Resposta esperada: na festa 1 a celebridade é Rubem, com 13 consultas
//    (de 36 da matriz inteira); na festa 2 não há celebridade.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Ana", "Rubem", "Clara", "Davi", "Elis", "Fausto"};
int festa1[V][V] = {
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
};
int festa2[V][V] = {
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
};

int main(void) {

    return 0;
}
