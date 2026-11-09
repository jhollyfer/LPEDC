// Lista · Módulo 06 · Ponteiros
// Exercício P0623 · ★★★ · Separar a linha do CSV no lugar

#include <stdio.h>

int separar(char *linha, char sep, char *campos[], int max) {
    if (max < 1) {
        return 0;
    }
    int n = 0;
    campos[n++] = linha;
    for (char *p = linha; *p != '\0'; p++) {
        if (*p == sep) {
            *p = '\0'; // fecha o campo atual no lugar do separador
            if (n < max) {
                campos[n++] = p + 1;
            }
        }
    }
    return n;
}

int main(void) {
    char linha[] = "27/11/2026;Prova de Conhecimentos;;08:00;Manaus";
    char *campos[8];

    int n = separar(linha, ';', campos, 8);
    printf("%d campos\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d] posição %2d: \"%s\"\n", i, (int) (campos[i] - linha), campos[i]);
    }
    printf("A linha agora: \"%s\"\n", linha);
    return 0;
}
