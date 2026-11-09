// 0171 · Com sinal e sem sinal
// Exercício E1023 · ★★☆

#include <stdio.h>

void mostrar_ao_contrario(const char *fila[], size_t n) {
    if (n == 0) {
        printf(" (nada)");
    }
    for (size_t i = n; i-- > 0;) {
        printf(" %s", fila[i]);
    }
    printf("\n");
}

size_t ultimo_par(const int *v, size_t n) {
    for (size_t i = n; i-- > 0;) {
        if (v[i] % 2 == 0) {
            return i;
        }
    }
    return n; // n nunca é índice válido: quer dizer "não achei"
}

void mostrar_par(const char *nome, const int *v, size_t n) {
    size_t i = ultimo_par(v, n);
    if (i == n) {
        printf("ultimo par em %s: nenhum\n", nome);
    } else {
        printf("ultimo par em %s: indice %zu\n", nome, i);
    }
}

int main(void) {
    const char *fila[] = {"Ana", "Bia", "Caio"};
    printf("fila:");
    mostrar_ao_contrario(fila, 3);
    printf("fila vazia:");
    mostrar_ao_contrario(fila, 0);

    int a[] = {3, 8, 5, 4, 7};
    int b[] = {1, 3};
    mostrar_par("{3, 8, 5, 4, 7}", a, 5);
    mostrar_par("{1, 3}", b, 2);
    return 0;
}
