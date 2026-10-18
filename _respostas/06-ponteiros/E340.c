// 0057 · Juntando tudo: o ranking da feira
// Exercício E340 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int por_tamanho(const void *a, const void *b) {
    const char *x = *(const char * const *)a;
    const char *y = *(const char * const *)b;
    size_t tx = strlen(x), ty = strlen(y);
    if (tx != ty) {
        return (tx > ty) - (tx < ty);
    }
    return strcmp(x, y);
}

int main(void) {
    const char *capitais[] = {"Natal", "Rio Branco", "Recife", "Palmas",
                              "Maceio", "Salvador", "Teresina", "Aracaju"};
    size_t n = sizeof capitais / sizeof capitais[0];

    qsort(capitais, n, sizeof capitais[0], por_tamanho);
    for (size_t i = 0; i < n; i++) {
        printf("%s%s", capitais[i], i + 1 < n ? " " : "\n");
    }
    return 0;
}
