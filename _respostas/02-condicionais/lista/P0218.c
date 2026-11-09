// Lista · Módulo 02 · Decisões
// Exercício P0218 · ★★☆ · O ícone da bateria

#include <stdio.h>

int main(void) {
    int b1 = 95, b2 = 47, b3 = 12;

    printf("%d%%: %s\n", b1, b1 >= 80 ? "cheia" : (b1 >= 20 ? "ok" : "baixa"));
    printf("%d%%: %s\n", b2, b2 >= 80 ? "cheia" : (b2 >= 20 ? "ok" : "baixa"));
    printf("%d%%: %s\n", b3, b3 >= 80 ? "cheia" : (b3 >= 20 ? "ok" : "baixa"));
    return 0;
}
