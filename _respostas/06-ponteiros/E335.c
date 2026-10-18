// 0056 · void * e cast
// Exercício E335 · ★★★

#include <stdio.h>
#include <string.h>

int busca(const void *v, size_t n, size_t tam, const void *alvo,
          int (*igual)(const void *, const void *)) {
    const unsigned char *inicio = v;
    for (size_t i = 0; i < n; i++) {
        if (igual(inicio + i * tam, alvo)) {
            return (int)i;
        }
    }
    return -1;
}

int igual_int(const void *a, const void *b) { return *(const int *)a == *(const int *)b; }
int igual_double(const void *a, const void *b) { return *(const double *)a == *(const double *)b; }
int igual_texto(const void *a, const void *b) {
    return strcmp(*(const char * const *)a, *(const char * const *)b) == 0;
}

int main(void) {
    int cods[5] = {310, 422, 518, 422, 907};
    double precos[4] = {9.90, 15.50, 4.25, 30.00};
    const char *nomes[3] = {"ana", "bia", "caio"};

    int cod = 422;
    double preco = 4.25;
    const char *nome = "caio";
    const char *outro = "bruno";

    printf("422 no índice %d\n", busca(cods, 5, sizeof cods[0], &cod, igual_int));
    printf("4.25 no índice %d\n", busca(precos, 4, sizeof precos[0], &preco, igual_double));
    printf("caio no índice %d\n", busca(nomes, 3, sizeof nomes[0], &nome, igual_texto));
    printf("bruno no índice %d\n", busca(nomes, 3, sizeof nomes[0], &outro, igual_texto));
    return 0;
}
