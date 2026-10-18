// 0032 · Recursão
// Exercício E189 · ★★☆

#include <stdio.h>

void recuo(int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
}

void eco(int n, int nivel) {
    if (n == 0) {
        recuo(nivel);
        printf("fundo\n");
        return;
    }
    recuo(nivel);
    printf("ida %d\n", n);
    eco(n - 1, nivel + 1);
    recuo(nivel);
    printf("volta %d\n", n); // roda só quando a chamada de dentro voltar
}

int main(void) {
    eco(3, 0);
    return 0;
}
