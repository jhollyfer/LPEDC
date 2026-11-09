// 0182 · Caminhos e ciclos
// Exercício E1092 · ★★★
//
// O envelope fechado é um quadrado com as duas diagonais: cantos A, B, C, D
// e os traços A-B, B-C, C-D, D-A, A-C, B-D. Todo canto tem grau 3, então
// não dá para desenhar sem tirar o lápis. Com 2k cantos ímpares, o mínimo
// é k traços. Escreva o programa que acha esses traços:
//
//   1. conte os cantos ímpares e mostre quantos traços são necessários;
//   2. crie um vértice falso X ligado aos dois últimos ímpares (eles viram
//      pares, e sobram 2 ímpares);
//   3. rode o Hierholzer a partir do primeiro ímpar;
//   4. mostre o trajeto cortado onde aparece o X: cada pedaço é um traço.
//
//   Saída esperada:
//   Cantos ímpares: 4 -> 2 traços
//   Traço 1: A B C A D C
//   Traço 2: D B
//
// Dicas:
// 1. Use uma matriz 5 x 5 (índice 4 é o X) e o Hierholzer do A364, sempre
//    escolhendo o vizinho de menor índice.
// 2. Na hora de mostrar, percorra o trajeto invertido: ao encontrar o X,
//    pule-o e comece a linha do próximo traço.
// 3. Resposta esperada: a saída acima. Os dois traços somam as 6 arestas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
