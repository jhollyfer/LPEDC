// 0029 · Parâmetros e passagem por valor
// Exercício E170 · ★☆☆

#include <stdio.h>

void repetir(char simbolo, int vezes) {
    for (int i = 1; i <= vezes; i++) {
        printf("%c", simbolo);
    }
    printf("\n");
}

int main(void) {
    repetir('=', 20);
    printf("PADARIA PÃO QUENTE\n");
    repetir('-', 20);
    printf("5 pães      R$ 4.50\n");
    printf("1 leite     R$ 5.20\n");
    repetir('-', 20);
    printf("Total       R$ 9.70\n");
    repetir('=', 20);
    return 0;
}
