// 0048 · Ponteiros e strings
// Exercício E288 · ★★★

#include <stdio.h>

const char *acha(const char *texto, const char *trecho) {
    for (const char *t = texto; ; t++) {
        int k = 0;
        while (trecho[k] != '\0' && t[k] == trecho[k]) {
            k++;
        }
        if (trecho[k] == '\0') {
            return t;
        }
        if (*t == '\0') {
            return NULL;
        }
    }
}

void testa(const char *texto, const char *trecho) {
    const char *p = acha(texto, trecho);
    if (p != NULL) {
        printf("\"%s\" na posição %td: %s\n", trecho, p - texto, p);
    } else {
        printf("\"%s\" não aparece\n", trecho);
    }
}

int main(void) {
    const char *texto = "o pix caiu na conta";

    testa(texto, "caiu");
    testa(texto, "boleto");
    testa(texto, "");
    return 0;
}
