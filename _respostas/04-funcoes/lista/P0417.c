// Lista · Módulo 04 · Funções e modularização
// Exercício P0417 · ★★☆ · A pilha da potência na tela

#include <stdio.h>

void recuo(int nivel) {
    for (int i = 0; i < 2 * nivel; i++) {
        printf(" ");
    }
}

int potencia(int base, int exp, int nivel) {
    recuo(nivel);
    if (exp == 0) {
        printf("potencia(%d, %d) = 1\n", base, exp);
        return 1;
    }
    printf("potencia(%d, %d)\n", base, exp);
    int r = base * potencia(base, exp - 1, nivel + 1);
    recuo(nivel);
    printf("= %d\n", r);
    return r;
}

int main(void) {
    int r = potencia(2, 4, 0);
    printf("Resultado: %d\n", r);
    return 0;
}
