// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2709 · ★☆☆ · Notas válidas com macros

#include <stdio.h>

#define QTD_NOTAS 5
#define QUADRADO(x) ((x) * (x))
#define ENTRE(x, a, b) ((x) >= (a) && (x) <= (b))

int main(void) {
    int notas[QTD_NOTAS] = {7, 11, -1, 10, 5};
    int validas = 0, soma = 0;
    for (int i = 0; i < QTD_NOTAS; i++) {
        if (ENTRE(notas[i], 0, 10)) {
            printf("nota %d: válida\n", notas[i]);
            validas++;
            soma += QUADRADO(notas[i]);
        } else {
            printf("nota %d: inválida\n", notas[i]);
        }
    }
    printf("válidas: %d, soma dos quadrados: %d\n", validas, soma);
    return 0;
}
