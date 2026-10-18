// 0054 · malloc e free
// Exercício E322 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t ta = 5 * sizeof(int);
    size_t tb = 5 * sizeof(double);
    size_t tc = 3 * sizeof(int *);
    size_t td = strlen("Recife") + 1;
    size_t te = 5;

    int *a = malloc(ta);
    double *b = malloc(tb);
    int **c = malloc(tc);
    char *d = malloc(td);
    int *e = malloc(te);
    if (a == NULL || b == NULL || c == NULL || d == NULL || e == NULL) {
        free(a); // free(NULL) não faz nada: libera todos sem medo
        free(b);
        free(c);
        free(d);
        free(e);
        return 1;
    }

    printf("a) %zu bytes\n", ta);
    printf("b) %zu bytes\n", tb);
    printf("c) %zu bytes\n", tc);
    printf("d) %zu bytes\n", td);
    printf("e) %zu bytes: cabe %zu int\n", te, te / sizeof(int));

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    return 0;
}
// Saída:
// a) 20 bytes
// b) 40 bytes
// c) 24 bytes
// d) 7 bytes
// e) 5 bytes: cabe 1 int
