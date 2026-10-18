// 0101 · Comparando: estabilidade, custo e qsort
// Exercício E603 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cada elemento do vetor é um const char *; o qsort passa o ENDEREÇO dele
int alfabetica(const void *a, const void *b) {
    const char *x = *(const char *const *) a;
    const char *y = *(const char *const *) b;
    return strcmp(x, y);
}

// mais curto primeiro; empatou no tamanho, ordem alfabética
int por_tamanho(const void *a, const void *b) {
    const char *x = *(const char *const *) a;
    const char *y = *(const char *const *) b;
    size_t tx = strlen(x), ty = strlen(y);
    if (tx != ty) {
        return (tx > ty) - (tx < ty);
    }
    return strcmp(x, y);
}

void mostra(const char *v[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%s%s", v[i], i < n - 1 ? " " : "\n");
    }
}

int main(void) {
    const char *bandas[] = {"Skank", "Titas", "Legiao", "Raimundos", "Pitty", "Cazuza"};
    size_t n = sizeof bandas / sizeof bandas[0];

    qsort(bandas, n, sizeof bandas[0], alfabetica);
    mostra(bandas, n);
    qsort(bandas, n, sizeof bandas[0], por_tamanho);
    mostra(bandas, n);
    return 0;
}
