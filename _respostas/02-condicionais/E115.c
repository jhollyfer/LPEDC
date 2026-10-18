// 0020 · if/else e o = no lugar do ==
// Exercício E115 · ★☆☆

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (idade >= 18) {
        printf("Maior de idade.\n");
    } else {
        printf("Faltam %d ano(s) para a maioridade.\n", 18 - idade);
    }
    return 0;
}
