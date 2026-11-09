// Lista · Módulo 02 · Decisões
// Exercício P0226 · ★★★ · O caixa eletrônico com poucas notas

#include <stdio.h>

int main(void) {
    const int TEM_50 = 2, TEM_20 = 10, TEM_10 = 3;
    int saque;

    printf("Saque: ");
    if (scanf("%d", &saque) != 1 || saque <= 0) {
        printf("Valor inválido.\n");
        return 1;
    }

    int resto = saque;
    int usa50 = resto / 50 < TEM_50 ? resto / 50 : TEM_50;
    resto -= usa50 * 50;
    int usa20 = resto / 20 < TEM_20 ? resto / 20 : TEM_20;
    resto -= usa20 * 20;
    int usa10 = resto / 10 < TEM_10 ? resto / 10 : TEM_10;
    resto -= usa10 * 10;

    if (resto != 0) {
        printf("Sem notas para esse valor.\n");
        return 0;
    }
    if (usa50 > 0) {
        printf("%d x R$ 50\n", usa50);
    }
    if (usa20 > 0) {
        printf("%d x R$ 20\n", usa20);
    }
    if (usa10 > 0) {
        printf("%d x R$ 10\n", usa10);
    }
    return 0;
}
