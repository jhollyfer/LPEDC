// 0014 · if
// Exercício E081 · ★★☆

#include <stdio.h>

int main(void) {
    int idade;
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (idade < 18) {
        printf("Entrada proibida para menores.\n");
    }
    printf("Bom filme!\n");
    return 0;
}
