// 0121 · Radix sort
// Exercício E723 · ★★☆
//
// A classificadora de cartões tinha 10 escaninhos, e cada escaninho é uma
// FILA: o primeiro cartão que entra é o primeiro que sai (assunto 0085).
// Faça o radix sort assim, sem contagem nem acumulado: em cada passada,
// distribua os números em 10 filas pelo dígito da vez e depois recolha as
// filas em ordem, da 0 à 9, de volta no vetor. Os números são os cubos de 0
// a 9, embaralhados:
//
//   64 8 216 512 27 729 0 1 343 125
//
//   Saída esperada:
//   exp =   1: 000 001 512 343 064 125 216 027 008 729
//   exp =  10: 000 001 008 512 216 125 027 729 343 064
//   exp = 100: 000 001 008 027 064 125 216 343 512 729
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

#define MAX 16

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %03d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int v[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
    int n = 10;
    mostra(v, n); // apague esta linha

    return 0;
}
