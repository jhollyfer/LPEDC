// 0138 · Memoização
// Exercício E825 · ★★☆
//
// Um motorista de aplicativo cruza o centro da cidade de um canto ao outro,
// andando só para a direita (D) ou para baixo (B). Cada quarteirão tem um
// pedágio de estacionamento rotativo, em reais, que ele paga ao passar
// (inclusive o da saída e o da chegada):
//
//   3 1 4 2 5
//   2 7 1 8 2
//   6 1 3 2 4
//   5 2 9 1 3
//
// Escreva um programa que calcula, de baixo para cima, a matriz custo[i][j]
// (o menor gasto da saída até o quarteirão (i, j)) e mostre o menor custo
// até o canto de baixo à direita. Depois, refaça o caminho de trás para a
// frente e mostre a sequência de letras D e B, da saída até a chegada.
//
//   Saída esperada:
//   Menor custo: R$ 18
//   Caminho: DDBBDBD
//
// Dicas:
// 1. custo[i][j] = pedagio[i][j] + o menor entre custo[i - 1][j] (veio de
//    cima) e custo[i][j - 1] (veio da esquerda).
// 2. Na linha 0 só dá para vir da esquerda; na coluna 0, só de cima.
// 3. Para o caminho, comece em (3, 4) e vá sempre para o vizinho (cima ou
//    esquerda) de menor custo, guardando a letra num vetor; no fim, mostre o
//    vetor de trás para a frente. Num empate, prefira cima.
// 4. Resposta esperada: a saída acima (3 + 1 + 4 + 1 + 3 + 2 + 1 + 3 = 18).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
