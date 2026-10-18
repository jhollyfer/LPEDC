// 0061 · Vetor de structs
// Exercício E364 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    double preco;
} Celular;

int por_nome(const void *a, const void *b) {
    Celular x = *(const Celular *)a;
    Celular y = *(const Celular *)b;
    return strcmp(x.nome, y.nome);
}

int por_preco_desc(const void *a, const void *b) {
    Celular x = *(const Celular *)a;
    Celular y = *(const Celular *)b;
    if (x.preco > y.preco) return -1;
    if (x.preco < y.preco) return 1;
    return 0;
}

void mostrar(const char *titulo, Celular v[], int n) {
    printf("%s:\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("  %-10s R$ %.2f\n", v[i].nome, v[i].preco);
    }
}

int main(void) {
    Celular v[] = {
        {"Moto G", 1299.00},
        {"Galaxy A", 1899.00},
        {"iPhone", 5499.00},
        {"Redmi", 999.00},
    };
    int n = sizeof v / sizeof v[0];

    qsort(v, n, sizeof v[0], por_nome);
    mostrar("Por nome", v, n);
    qsort(v, n, sizeof v[0], por_preco_desc);
    mostrar("Por preço", v, n);
    return 0;
}
