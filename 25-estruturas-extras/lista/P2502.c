// Lista · Módulo 25 · Estruturas especiais
// Exercício P2502 · ★☆☆ · O mapa do estacionamento
//
// O sistema do estacionamento guarda só as triplas (andar, vaga, horas
// parado), em ordem de andar e de vaga:
//
//   (0, 2, 3) (0, 7, 1) (1, 0, 5) (1, 1, 2) (2, 5, 8) (3, 3, 4) (3, 4, 1)
//
// São 4 andares de 8 vagas. Escreva do zero o mapa para o painel da
// entrada: uma linha por andar, com as horas de cada vaga ocupada e um
// ponto nas livres, numa passada só pelas triplas (sem montar a matriz
// cheia). No fim, os carros e as horas somadas.
//
//   Saída esperada:
//   andar 0: . . 3 . . . . 1
//   andar 1: 5 2 . . . . . .
//   andar 2: . . . . . 8 . .
//   andar 3: . . . 4 1 . . .
//   Carros: 7, horas somadas: 24
//
// Dicas:
// 1. Use um índice k na tripla da vez. Ao visitar (i, j), se t[k] é
//    exatamente (i, j), mostre o valor e avance k; senão, mostre '.'.
// 2. Isso só funciona porque as triplas estão em ordem: é um "merge" entre
//    a varredura da matriz e a lista.
// 3. Resposta esperada: 7 carros, 24 horas; o andar 2 só tem a vaga 5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
