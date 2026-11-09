// Lista · Módulo 06 · Ponteiros
// Exercício P0628 · ★★★ · Todas as vezes que a palavra aparece

#include <stdio.h>
#include <string.h>

int achar_todas(const char *texto, const char *palavra, const char *pos[], int max) {
    int n = 0;
    const char *p = strstr(texto, palavra);
    while (p != NULL && n < max) {
        pos[n++] = p;
        p = strstr(p + 1, palavra); // continua depois desta ocorrência
    }
    return n;
}

int main(void) {
    const char *letra = "O boi bumbá, o boi Garantido, o boizinho do povo, boi!";
    const char *palavra = "boi";
    const char *pos[10];
    size_t tam = strlen(palavra);

    int n = achar_todas(letra, palavra, pos, 10);
    printf("%d ocorrências:", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", (int) (pos[i] - letra));
    }
    printf("\n");

    int k = 0;
    for (const char *c = letra; *c != '\0';) {
        if (k < n && c == pos[k]) {
            printf("[%s]", palavra);
            c += tam;
            k++;
        } else {
            putchar(*c);
            c++;
        }
    }
    printf("\n");
    return 0;
}
