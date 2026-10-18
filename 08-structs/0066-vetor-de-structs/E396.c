// 0066 · Vetor de structs
// Exercício E396 · ★★★
//
// Um terreno irregular tem 5 cantos, em metros, dados em ordem (dando a volta
// no terreno):
//
//   (0, 0)  (6, 0)  (6, 4)  (3, 7)  (0, 4)
//
// Guarde os cantos num vetor de struct Ponto e calcule a área e o perímetro.
// Para a área, use a fórmula do cadarço (shoelace): some x[i] * y[j] -
// x[j] * y[i] para cada canto i, com j sendo o canto seguinte, e divida o
// valor absoluto da soma por 2. O canto seguinte ao último é o primeiro.
//
//   Saída esperada:
//   Área: 33.00 m2
//   Perímetro: 22.49 m
//
// Dicas:
// 1. O canto seguinte com volta ao começo: int j = (i + 1) % n;
// 2. fabs e sqrt estão em math.h. Lado entre dois pontos:
//    sqrt(dx * dx + dy * dy).
// 3. Teste antes com um retângulo simples, (0,0) (8,0) (8,5) (0,5): área 40.
// 4. Resposta esperada: a saída acima (66 / 2 = 33; lados 6, 4, 4.24, 4.24, 4).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
