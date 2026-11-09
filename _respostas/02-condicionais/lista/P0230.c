// Lista · Módulo 02 · Decisões
// Exercício P0230 · ★★★ · A senha de 4 dígitos do app

#include <stdio.h>

int main(void) {
    int senha;

    printf("Senha: ");
    if (scanf("%d", &senha) != 1 || senha < 0 || senha > 9999) {
        printf("Senha inválida: use 4 dígitos\n");
        return 1;
    }

    int d1 = senha / 1000;
    int d2 = senha / 100 % 10;
    int d3 = senha / 10 % 10;
    int d4 = senha % 10;

    if (d1 == d2 && d2 == d3 && d3 == d4) {
        printf("Senha fraca: dígitos iguais\n");
    } else if (d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1) {
        printf("Senha fraca: sequência crescente\n");
    } else if (d2 == d1 - 1 && d3 == d2 - 1 && d4 == d3 - 1) {
        printf("Senha fraca: sequência decrescente\n");
    } else if (senha >= 1950 && senha <= 2026) {
        printf("Senha fraca: parece um ano\n");
    } else {
        printf("Senha aceita\n");
    }
    return 0;
}
