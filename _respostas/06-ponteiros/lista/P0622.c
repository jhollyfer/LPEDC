// Lista · Módulo 06 · Ponteiros
// Exercício P0622 · ★★★ · O meu qsort de qualquer tipo

#include <stdio.h>
#include <string.h>

void troca_bytes(void *a, void *b, size_t tam) {
    unsigned char *pa = a, *pb = b;
    for (size_t k = 0; k < tam; k++) {
        unsigned char aux = pa[k];
        pa[k] = pb[k];
        pb[k] = aux;
    }
}

void ordenar(void *base, size_t n, size_t tam,
             int (*cmp)(const void *, const void *)) {
    unsigned char *v = base;
    for (size_t i = 1; i < n; i++) {
        size_t j = i;
        while (j > 0 && cmp(v + (j - 1) * tam, v + j * tam) > 0) {
            troca_bytes(v + (j - 1) * tam, v + j * tam, tam);
            j--;
        }
    }
}

int cmp_int(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

int cmp_double(const void *a, const void *b) {
    double x = *(const double *) a, y = *(const double *) b;
    return (x > y) - (x < y);
}

int cmp_linha(const void *a, const void *b) {
    return strcmp(a, b); // a linha char[12] começa com a string
}

int main(void) {
    int idades[6] = {34, 19, 52, 27, 19, 40};
    double precos[5] = {9.90, 2.49, 15.00, 4.75, 2.10};
    char cidades[5][12] = {"Tefe", "Coari", "Borba", "Manaus", "Autazes"};

    ordenar(idades, 6, sizeof idades[0], cmp_int);
    ordenar(precos, 5, sizeof precos[0], cmp_double);
    ordenar(cidades, 5, sizeof cidades[0], cmp_linha);

    printf("Idades:");
    for (int i = 0; i < 6; i++) {
        printf(" %d", idades[i]);
    }
    printf("\nPreços:");
    for (int i = 0; i < 5; i++) {
        printf(" %.2f", precos[i]);
    }
    printf("\nCidades:");
    for (int i = 0; i < 5; i++) {
        printf(" %s", cidades[i]);
    }
    printf("\n");
    return 0;
}
