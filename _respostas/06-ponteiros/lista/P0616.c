// Lista · Módulo 06 · Ponteiros
// Exercício P0616 · ★★☆ · Ordem alfabética sem ligar para maiúsculas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compara_sem_caixa(const char *a, const char *b) {
    while (*a != '\0' && tolower((unsigned char) *a) == tolower((unsigned char) *b)) {
        a++;
        b++;
    }
    return tolower((unsigned char) *a) - tolower((unsigned char) *b);
}

int cmp_strcmp(const void *pa, const void *pb) {
    return strcmp(*(const char **) pa, *(const char **) pb);
}

int cmp_sem_caixa(const void *pa, const void *pb) {
    return compara_sem_caixa(*(const char **) pa, *(const char **) pb);
}

void mostrar(const char *titulo, const char **v, int n) {
    printf("%s:", titulo);
    for (int i = 0; i < n; i++) {
        printf(" %s", v[i]);
    }
    printf("\n");
}

int main(void) {
    const char *convidados[6] = {"bruna", "Ademir", "carlos", "Beatriz",
                                 "ana", "Caio"};
    const char *a[6], *b[6];

    for (int i = 0; i < 6; i++) {
        a[i] = b[i] = convidados[i]; // copia os ponteiros, não os textos
    }
    qsort(a, 6, sizeof a[0], cmp_strcmp);
    qsort(b, 6, sizeof b[0], cmp_sem_caixa);
    mostrar("strcmp", a, 6);
    mostrar("sem caixa", b, 6);
    return 0;
}
