// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1016 · ★★☆ · Crescer de um em um ou dobrar?

#include <stdio.h>

long copias_mais_um(int n) {
    long copias = 0, tam = 0, cap = 1;
    for (int i = 0; i < n; i++) {
        if (tam == cap) {
            copias += tam;
            cap = cap + 1;
        }
        tam++;
    }
    return copias;
}

long copias_dobra(int n) {
    long copias = 0, tam = 0, cap = 1;
    for (int i = 0; i < n; i++) {
        if (tam == cap) {
            copias += tam;
            cap = cap * 2;
        }
        tam++;
    }
    return copias;
}

int main(void) {
    int testes[2] = {1000, 2000};
    for (int i = 0; i < 2; i++) {
        printf("n = %d: +1 copia %ld, dobrando copia %ld\n", testes[i], copias_mais_um(testes[i]),
               copias_dobra(testes[i]));
    }
    printf("Por inserção (n = 2000): +1 = %.1f, dobrando = %.1f\n", copias_mais_um(2000) / 2000.0,
           copias_dobra(2000) / 2000.0);
    return 0;
}
