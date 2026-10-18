// 0018 · Lógicos: E, OU, NÃO
// Exercício E105 · ★★☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int ano;
    printf("Ano: ");
    scanf("%d", &ano);

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
    printf("Bissexto? %d\n", bissexto);
    return 0;
}
