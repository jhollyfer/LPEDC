// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2310 · ★☆☆ · Quem recebe o recado
//
// Na família, cada um repassa o recado só para algumas pessoas (mão
// única): Ana -> Bia, Bia -> Caio, Caio -> Ana, Caio -> Davi, Edu -> Davi.
// Escreva do zero o fecho transitivo pelo algoritmo de Warshall: o Floyd-
// Warshall com 0 e 1 no lugar de números, em que alcanca[i][j] vira 1
// quando alcanca[i][k] e alcanca[k][j] são 1. Mostre a matriz e, para cada
// pessoa, quantas OUTRAS pessoas recebem o recado dela.
//
//   Saída esperada:
//         Ana Bia Caio Davi Edu
//   Ana     1   1    1    1   0   chega em 3
//   Bia     1   1    1    1   0   chega em 3
//   Caio    1   1    1    1   0   chega em 3
//   Davi    0   0    0    0   0   chega em 0
//   Edu     0   0    0    1   0   chega em 1
//
// Dicas:
// 1. A diagonal começa em 0. Ela só vira 1 se a pessoa está num ciclo (o
//    recado volta para ela).
// 2. Cabeçalho com printf("      Ana Bia Caio Davi Edu\n"); os números com
//    "%3d", menos nas colunas Caio e Davi, que usam "%4d".
// 3. Resposta esperada: Ana, Bia e Caio chegam em 3 pessoas cada; Davi em
//    nenhuma; Edu só em Davi.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
