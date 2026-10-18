// 0105 · A ideia e a função hash
// Exercício E629 · ★★★

#include <stdio.h>

#define M 8

int indice(const char *s) {
    unsigned soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += (unsigned char)s[i];
    }
    return (int)(soma % M);
}

int main(void) {
    int contagem[M] = {0};
    const char *frutas[] = {"banana", "uva", "maçã"};

    for (int i = 0; i < 3; i++) {
        printf("%s -> %d\n", frutas[i], indice(frutas[i]));
        contagem[indice(frutas[i])]++;
    }
    for (int b = 0; b < M; b++) {
        printf("balde %d: %d\n", b, contagem[b]);
    }
    return 0;
}
