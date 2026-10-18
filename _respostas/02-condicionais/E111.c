// 0019 · if
// Exercício E111 · ★★☆
//
// Resposta: o ";" logo depois de if (idade < 18) é uma instrução vazia, que
// vira o corpo do if. O bloco entre chaves fica solto e roda sempre.

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
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
