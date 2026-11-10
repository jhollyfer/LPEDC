// Lista · Módulo 16 · Grafos
// Exercício P1618 · ★★☆ · O caminho do entregador desenhado na grade
//
// O mapa de um condomínio virou uma grade: # é muro, . é passagem, S é a
// portaria e E é o bloco da entrega. O entregador anda uma casa por vez, na
// horizontal ou na vertical. Cada casa é um vértice e cada vizinha livre é
// uma aresta: é um grafo, mesmo sem matriz de adjacência.
//
// Rode uma BFS a partir de S, guardando o pai de cada casa (casa = l * C + c),
// e mostre o número de passos até E e o mapa com o caminho marcado com *
// (sem apagar S e E). Examine as direções na ordem cima, baixo, esquerda,
// direita.
//
//   Saída esperada:
//   Passos: 16
//   S**#****
//   .#*#*##*
//   .#***#**
//   .##.#.*#
//   ....#.E.
//
// Dicas:
// 1. Os vizinhos saem de dois vetores: dl[] = {-1, 1, 0, 0} e
//    dc[] = {0, 0, -1, 1}. Confira os limites da grade antes de ler mapa[][].
// 2. A fila guarda o número da casa; l = casa / C e c = casa % C.
// 3. Para marcar o caminho, ande de E para trás por pai[] até chegar em S,
//    trocando cada '.' por '*'.
// 4. Resposta esperada: 16 passos e o mapa acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 5
#define C 8

char mapa[L][C + 1] = {
    "S..#....",
    ".#.#.##.",
    ".#...#..",
    ".##.#..#",
    "....#.E.",
};

int main(void) {

    return 0;
}
