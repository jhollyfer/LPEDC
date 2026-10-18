// 0052 · Juntando tudo: o ranking da feira
// Exercício E312 · ★★★

#include <stdio.h>
#include <string.h>

void *maximo(void *v, size_t n, size_t tam, int (*cmp)(const void *, const void *)) {
    if (n == 0) {
        return NULL;
    }
    unsigned char *base = v;
    unsigned char *maior = base;
    for (size_t i = 1; i < n; i++) {
        if (cmp(base + i * tam, maior) > 0) {
            maior = base + i * tam;
        }
    }
    return maior;
}

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int cmp_alfabeto(const void *a, const void *b) {
    return strcmp(*(const char * const *)a, *(const char * const *)b);
}

int cmp_tamanho(const void *a, const void *b) {
    size_t x = strlen(*(const char * const *)a);
    size_t y = strlen(*(const char * const *)b);
    return (x > y) - (x < y);
}

int main(void) {
    int pontos[5] = {12, 47, 33, 47, 5};
    const char *frutas[4] = {"uva", "maca", "laranja", "abacate"};

    int *mp = maximo(pontos, 5, sizeof pontos[0], cmp_int);
    printf("maior pontuação: %d (índice %td)\n", *mp, mp - pontos);

    const char **mf = maximo(frutas, 4, sizeof frutas[0], cmp_alfabeto);
    printf("última no alfabeto: %s (índice %td)\n", *mf, mf - frutas);

    mf = maximo(frutas, 4, sizeof frutas[0], cmp_tamanho);
    printf("nome mais comprido: %s (índice %td)\n", *mf, mf - frutas);

    *mp = 0;
    printf("depois de zerar:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", pontos[i]);
    }
    printf("\n");
    return 0;
}
