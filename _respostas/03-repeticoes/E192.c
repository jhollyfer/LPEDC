// 0032 · Juntando tudo
// Exercício E192 · ★★★

#include <stdio.h>

int main(void) {
    int dias_no_mes = 31;
    int primeiro = 4; // 0 = domingo, ..., 4 = quinta

    printf("  D  S  T  Q  Q  S  S\n");
    for (int i = 0; i < primeiro; i++) {
        printf("   ");
    }
    for (int dia = 1; dia <= dias_no_mes; dia++) {
        printf("%3d", dia);
        if ((primeiro + dia) % 7 == 0) {
            printf("\n"); // chegou no sábado
        }
    }
    if ((primeiro + dias_no_mes) % 7 != 0) {
        printf("\n"); // fecha a última linha se ela não acabou no sábado
    }
    return 0;
}
