// Lista · Módulo 12 · Pilhas e filas
// Exercício P1223 · ★★★ · O menor caminho na feira (busca em largura)
//
// O mapa da feira tem corredores livres ('.'), barracas ('#'), a entrada
// (S) e a barraca do açaí (F). Você anda uma casa por passo, para cima,
// baixo, esquerda ou direita. Qual o MENOR número de passos de S até F?
// Uma FILA resolve: a partir de S, visite primeiro todas as casas a 1 passo,
// depois todas a 2 passos, e assim por diante (é a busca em largura).
//
//   S.#...
//   .##.#.
//   ...#..
//   #....#
//   ...#.F
//
// Escreva o programa com uma fila circular de posições (linha, coluna), uma
// matriz de distâncias (-1 = não visitada) e uma matriz de "de onde vim"
// para refazer o caminho. Mostre o número de passos e o mapa com o caminho
// marcado com '*' (sem apagar S e F). Na hora de visitar vizinhos, use a
// ordem: cima, baixo, esquerda, direita.
//
//   Saída esperada:
//   Menor caminho: 9 passos
//   S.#...
//   *##.#.
//   **.#..
//   #****#
//   ...#*F
//
// Dicas:
// 1. Ponha S na fila com distância 0. Enquanto a fila não esvaziar: tire
//    (l, c); para cada vizinho dentro do mapa, que não é '#' e ainda não
//    foi visitado, anote dist = dist[l][c] + 1, anote de onde veio e ponha
//    na fila.
// 2. A primeira vez que uma casa é visitada já é pelo menor caminho: a fila
//    garante que todas as casas a k passos saem antes das a k + 1.
// 3. Para marcar o caminho, ande de F para trás pelo "de onde vim" até S.
// 4. A fila nunca guarda a mesma casa duas vezes, então cabe com 30
//    posições (5 x 6). Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define L 5
#define C 6

int main(void) {
    char mapa[L][C + 1] = {
        "S.#...",
        ".##.#.",
        "...#..",
        "#....#",
        "...#.F",
    };
    for (int i = 0; i < L; i++) {
        printf("%s\n", mapa[i]);
    }
    return 0;
}
