// 0113 · Juntando tudo: o contador de palavras
// Exercício E673 · ★☆☆

#include <stdio.h>
#include <ctype.h>

int eh_letra(char c) {
    unsigned char u = (unsigned char)c;
    return isalpha(u) || u >= 128; // byte >= 128: pedaço de letra UTF-8
}

int main(void) {
    const char *frase = "Bom dia, Brasil! Bom dia, São Paulo.";
    int total = 0;
    const char *p = frase;
    while (*p != '\0') {
        while (*p != '\0' && !eh_letra(*p)) {
            p++;
        }
        if (*p == '\0') {
            break;
        }
        while (eh_letra(*p)) {
            putchar(tolower((unsigned char)*p));
            p++;
        }
        putchar('\n');
        total++;
    }
    printf("%d palavras\n", total);
    return 0;
}
