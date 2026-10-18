// 0063 · Enum
// Exercício E373 · ★☆☆

#include <stdio.h>

enum Tamanho { P = 1, M, G, GG = 10, XG, XXG = GG * 2, ESP };

int main(void) {
    const enum Tamanho tamanhos[] = {P, M, G, GG, XG, XXG, ESP};
    const char *nomes[] = {"P", "M", "G", "GG", "XG", "XXG", "ESP"};
    int n = sizeof tamanhos / sizeof tamanhos[0];

    for (int i = 0; i < n; i++) {
        printf("%s = %d\n", nomes[i], tamanhos[i]);
    }

    enum Tamanho t = G + XG; // compila: para o C, são só inteiros
    printf("G + XG = %d\n", t);
    return 0;
}
