// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2402 · ★☆☆ · Quantos kk tem a risada

#include <stdio.h>
#include <string.h>

int conta(const char *texto, const char *padrao, int pulo_inteiro) {
    int total = 0;
    const char *p = texto;
    while ((p = strstr(p, padrao)) != NULL) {
        total++;
        p += pulo_inteiro ? strlen(padrao) : 1;
    }
    return total;
}

int main(void) {
    const char *msg = "kkkkk ri muito kkk";
    printf("\"kk\" com sobreposição: %d\n", conta(msg, "kk", 0));
    printf("\"kk\" sem sobreposição: %d\n", conta(msg, "kk", 1));
    printf("\"kkk\" com sobreposição: %d\n", conta(msg, "kkk", 0));
    printf("\"kkk\" sem sobreposição: %d\n", conta(msg, "kkk", 1));
    return 0;
}
