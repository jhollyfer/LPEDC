// 0006 · scanf
// Exercício E036 · ★★★

#include <stdio.h>

int main(void) {
    int dia = 0, mes = 0, ano = 0;

    printf("Data: ");
    scanf("%d%*c%d%*c%d", &dia, &mes, &ano); // %*c: lê o separador e descarta

    printf("ISO: %04d-%02d-%02d\n", ano, mes, dia);
    return 0;
}
