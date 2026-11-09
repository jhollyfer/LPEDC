// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2004 · ★☆☆ · O caixa da feira com poucas moedas

#include <stdio.h>

#define T 4

const int nota[T] = {10, 5, 2, 1};
int estoque[T] = {2, 3, 4, 5};

int troco(int valor) {
    printf("Troco de R$ %d:", valor);
    int falta = valor;
    for (int i = 0; i < T; i++) {
        while (nota[i] <= falta && estoque[i] > 0) {
            printf(" %d", nota[i]);
            falta -= nota[i];
            estoque[i]--;
        }
    }
    printf("\n");
    return falta == 0;
}

int main(void) {
    const int pedidos[3] = {27, 18, 9};
    for (int k = 0; k < 3; k++) {
        if (!troco(pedidos[k])) {
            printf("  faltou troco!\n");
        }
    }
    printf("Sobrou no caixa: %d de 10, %d de 5, %d de 2, %d de 1\n",
           estoque[0], estoque[1], estoque[2], estoque[3]);
    return 0;
}
