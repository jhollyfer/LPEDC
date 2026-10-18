// 0016 · else if, if aninhado e o else pendurado
// Exercício E092 · ★☆☆

#include <stdio.h>

int main(void) {
    double saldo;
    printf("Saldo: ");
    if (scanf("%lf", &saldo) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (saldo > 0) {
        printf("Conta no azul.\n");
    } else if (saldo < 0) {
        printf("Conta no vermelho.\n");
    } else {
        printf("Conta zerada.\n");
    }
    return 0;
}
