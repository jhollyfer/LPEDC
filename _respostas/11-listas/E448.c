// 0075 · Vetor dinâmico
// Exercício E448 · ★★☆

#include <stdio.h>

int remove_deslocando(int v[], int *n, int pos) {
    int movimentos = 0;
    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
        movimentos++;
    }
    (*n)--;
    return movimentos;
}

int remove_trocando(int v[], int *n, int pos) {
    int movimentos = 0;
    if (pos != *n - 1) {
        v[pos] = v[*n - 1]; // o último tapa o buraco
        movimentos = 1;
    }
    (*n)--;
    return movimentos;
}

void mostra(const int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", v[i]);
    }
    printf("]");
}

int main(void) {
    int a[8], b[8];
    for (int i = 0; i < 8; i++) a[i] = b[i] = 101 + i;
    int na = 8, nb = 8;

    int ma = remove_deslocando(a, &na, 2);
    int mb = remove_trocando(b, &nb, 2);

    printf("deslocando: ");
    mostra(a, na);
    printf("  movimentos: %d\n", ma);
    printf("trocando:   ");
    mostra(b, nb);
    printf("  movimentos: %d\n", mb);

    int total_a = 0, total_b = 0;
    while (na > 0) total_a += remove_deslocando(a, &na, 0);
    while (nb > 0) total_b += remove_trocando(b, &nb, 0);
    printf("esvaziando pela frente: deslocando %d, trocando %d\n", total_a, total_b);
    return 0;
}
