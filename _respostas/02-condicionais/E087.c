// 0015 · if/else e o = no lugar do ==
// Exercício E087 · ★★☆

#include <stdio.h>

int main(void) {
    int tentativas;
    if (scanf("%d", &tentativas) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (tentativas == 3) {
        printf("Cartão bloqueado.\n");
    } else {
        printf("Senha errada. Restam %d tentativa(s).\n", 3 - tentativas);
    }
    printf("Tentativas registradas: %d\n", tentativas);
    return 0;
}
