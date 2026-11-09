// Lista · Módulo 21 · Programação dinâmica
// Exercício P2125 · ★★★ · Dois times equilibrados
//
// Dez amigos vão jogar futebol, e cada um tem uma nota de 1 a 10 dada pelo
// grupo: Ana 8, Beto 6, Caio 9, Duda 4, Enzo 7, Fábio 5, Gabi 10, Hugo 3,
// Iara 6 e João 7. Eles querem DOIS TIMES DE 5 com a soma das notas o mais
// parecida possível. Escreva do zero a PD com o tamanho do time na tabela:
// pode[k][s] diz se dá para escolher k jogadores com soma s. Processe os
// jogadores um a um (k e s de trás para a frente, para cada um entrar uma
// vez), guardando quem completou cada casa pela primeira vez para
// reconstruir. Escolha a soma s com 5 jogadores mais perto de total / 2.
//
//   Saída esperada:
//   Time 1: Ana Beto Caio Duda Fábio (32 pontos)
//   Time 2: Enzo Gabi Hugo Iara João (33 pontos)
//
// Dicas:
// 1. Total 65: o ideal seria 32,5, então a melhor diferença possível é 1
//    (32 contra 33).
// 2. quem[k][s] = índice do jogador que tornou pode[k][s] verdadeiro pela
//    primeira vez. Reconstrução: j = quem[5][s]; ele entra; k = 4; s -=
//    nota[j]; e assim por diante. Como ele foi processado antes dos
//    seguintes, a casa (k - 1, s - nota[j]) foi formada só com jogadores
//    de índice menor.
// 3. Resposta esperada: times de 32 e 33 pontos (diferença 1); confira os
//    nomes na saída.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
