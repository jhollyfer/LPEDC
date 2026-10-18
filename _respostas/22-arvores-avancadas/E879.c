// 0147 · Trie
// Exercício E879 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct NoFreq {
    struct NoFreq *filho[26];
    int qtd; // quantas vezes a palavra que termina aqui apareceu (0: nenhuma)
} NoFreq;

NoFreq *novo(void) {
    NoFreq *n = calloc(1, sizeof(NoFreq));
    if (n == NULL) {
        exit(1);
    }
    return n;
}

// soma 1 na palavra de tam letras que começa em p
void conta(NoFreq *r, const char *p, int tam) {
    for (int k = 0; k < tam; k++) {
        int i = p[k] - 'a';
        if (r->filho[i] == NULL) {
            r->filho[i] = novo();
        }
        r = r->filho[i];
    }
    r->qtd++;
}

void lista(const NoFreq *n, char buf[], int nivel, int *distintas) {
    if (n->qtd > 0) {
        buf[nivel] = '\0';
        printf("%-6s %d\n", buf, n->qtd);
        (*distintas)++;
    }
    for (int i = 0; i < 26; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            lista(n->filho[i], buf, nivel + 1, distintas);
        }
    }
}

void libera(NoFreq *n) {
    if (n != NULL) {
        for (int i = 0; i < 26; i++) {
            libera(n->filho[i]);
        }
        free(n);
    }
}

int main(void) {
    const char *texto = "o rato roeu a roupa do rei de roma o rei riu da roupa";
    NoFreq *r = novo();
    int total = 0;
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == ' ') {
            i++;
            continue;
        }
        int ini = i;
        while (texto[i] >= 'a' && texto[i] <= 'z') {
            i++;
        }
        conta(r, texto + ini, i - ini);
        total++;
    }
    char buf[32];
    int distintas = 0;
    lista(r, buf, 0, &distintas);
    printf("%d palavras, %d diferentes\n", total, distintas);
    libera(r);
    return 0;
}
