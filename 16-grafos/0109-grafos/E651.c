// 0109 · Grafos
// Exercício E651 · ★★☆
//
// O bairro tem quatro esquinas, A (0), B (1), C (2) e D (3). A prefeitura listou
// as ruas num vetor de "Rua" (struct com "int de, para"), uma entrada por
// SENTIDO permitido; {0, 1} é ir de A para B. Os sentidos são {0, 1}, {1, 0},
// {1, 2}, {2, 3}, {3, 0}, {0, 2} e {2, 0}. Monte a matriz de adjacência
// DIRIGIDA a partir do vetor e, para cada par de esquinas ligadas, diga se a
// rua é de mão dupla ou única (e o sentido). No fim, conte cada tipo.
//
//   Saída esperada:
//   Sentidos cadastrados: 7
//   A-B: mão dupla
//   A-C: mão dupla
//   A-D: mão única (D -> A)
//   B-C: mão única (B -> C)
//   C-D: mão única (C -> D)
//   Mão única: 3, mão dupla: 2
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 4

typedef struct {
    int de;
    int para;
} Rua;

int main(void) {

    return 0;
}
