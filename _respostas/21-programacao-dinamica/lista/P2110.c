// Lista · Módulo 21 · Programação dinâmica
// Exercício P2110 · ★☆☆ · Quantas mensagens cabem nesses números?

#include <stdio.h>
#include <string.h>

long leituras(const char *s) {
    int n = (int)strlen(s);
    long formas[32];
    formas[0] = 1;
    for (int i = 1; i <= n; i++) {
        formas[i] = 0;
        if (s[i - 1] != '0') {
            formas[i] += formas[i - 1];
        }
        if (i >= 2) {
            int dois = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (dois >= 10 && dois <= 26) {
                formas[i] += formas[i - 2];
            }
        }
    }
    return formas[n];
}

int main(void) {
    const char *msgs[3] = {"226", "1122612", "301"};
    for (int k = 0; k < 3; k++) {
        printf("%s: %ld leituras\n", msgs[k], leituras(msgs[k]));
    }
    return 0;
}
