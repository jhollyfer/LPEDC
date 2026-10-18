// 0016 · else if, if aninhado e o else pendurado
// Exercício E093 · ★★☆
//
// Sem chaves, o else ficava com o if (chuva). Com as chaves, ele volta para
// o if (vai_sair), como o recuo prometia.

#include <stdio.h>

int main(void) {
    int vai_sair, chuva;
    printf("Vai sair? Vai chover? ");
    if (scanf("%d %d", &vai_sair, &chuva) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (vai_sair) {
        if (chuva) {
            printf("Leve o guarda-chuva.\n");
        }
    } else {
        printf("Fique em casa e descanse.\n");
    }
    printf("Bom dia!\n");
    return 0;
}
