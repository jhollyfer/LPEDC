// 0148 · Union-find
// Exercício E883 · ★☆☆

#include <stdio.h>
#include "uniao.h"

int main(void) {
    const char *cidade[] = {"Araras", "Bauru", "Catanduva", "Dourado", "Embu", "Franca", "Garça"};
    int estradas[][2] = {{0, 2}, {1, 5}, {2, 3}, {5, 6}, {0, 3}};
    UF *u = uf_cria(7);
    for (int i = 0; i < 5; i++) {
        uf_une(u, estradas[i][0], estradas[i][1]);
    }
    printf("Grupos de cidades ligadas: %d\n", uf_grupos(u));
    int perguntas[][2] = {{0, 3}, {1, 6}, {3, 5}, {4, 4}};
    for (int i = 0; i < 4; i++) {
        int a = perguntas[i][0], b = perguntas[i][1];
        printf("%s -> %s: %s\n", cidade[a], cidade[b],
               uf_juntos(u, a, b) ? "dá para ir" : "não dá para ir");
    }
    uf_libera(u);
    return 0;
}
