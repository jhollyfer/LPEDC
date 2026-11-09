// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1917 · ★★☆ · Todos os caminhos até a saída
//
// No mapa do shopping, # é parede e . é corredor. Você entra em S, no
// canto de cima à esquerda, e quer chegar à saída F, no canto de baixo à
// direita, andando nas 4 direções e sem passar duas vezes pela mesma casa.
// O labirinto do assunto 0129 para no primeiro caminho; aqui você quer
// CONTAR todos e saber o tamanho do mais curto e do mais longo. Complete
// anda(l, c, passos).
//
//   Saída esperada:
//   Caminhos: 12
//   Mais curto: 7 passos
//   Mais longo: 13 passos
//
// Dicas:
// 1. Ao chegar em F, conte o caminho, atualize o menor e o maior e volte
//    (não marque F).
// 2. Senão: saia se a casa está fora, é parede ou já foi visitada; marque,
//    tente os 4 vizinhos com passos + 1 e DESMARQUE ao voltar. Sem
//    desmarcar, um caminho bloqueia os outros e a conta sai menor.
// 3. Resposta esperada: 12 caminhos, o mais curto com 7 passos e o mais
//    longo com 13.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define L 4
#define C 5

const char mapa[L][C + 1] = {
    "S...#",
    ".#...",
    "...#.",
    "#...F",
};
bool visto[L][C];
int caminhos = 0, menor = 1000, maior = 0;

void anda(int l, int c, int passos) {
    (void)l;
    (void)c;
    (void)passos;
    // COMPLETE AQUI
}

int main(void) {
    anda(0, 0, 0);
    printf("Caminhos: %d\n", caminhos);
    printf("Mais curto: %d passos\n", menor);
    printf("Mais longo: %d passos\n", maior);
    return 0;
}
