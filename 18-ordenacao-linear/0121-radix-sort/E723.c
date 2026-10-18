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
// Dicas:
// 1. Uma fila simples basta: typedef struct { int itens[MAX]; int ini, fim; }
//    Fila; com enfileira (itens[fim++] = x), desenfileira (itens[ini++]) e
//    vazia (ini == fim). Cada passada começa com as 10 filas zeradas.
// 2. Cada fila recebe no máximo os 10 números, então MAX = 16 sobra.
// 3. A fila é o que garante a estabilidade: quem entrou antes no escaninho
//    sai antes. Com uma PILHA no lugar, o resultado sairia errado.
// 4. Resposta esperada: a saída acima.
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
