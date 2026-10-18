// A226 · Contando as palavras de qualquer texto (entrada padrão)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palavras.h"

int eh_letra(char c) {
    unsigned char u = (unsigned char)c;
    return isalpha(u) || u >= 128;
}

int proxima_palavra(const char **p, char *buf, size_t tam) {
    while (**p != '\0' && !eh_letra(**p)) {
        (*p)++;
    }
    if (**p == '\0') {
        return 0;
    }
    size_t n = 0;
    while (eh_letra(**p)) {
        if (n < tam - 1) {
            buf[n++] = (char)tolower((unsigned char)**p);
        }
        (*p)++;
    }
    buf[n] = '\0';
    return 1;
}

int compara(const void *a, const void *b) {
    const Contagem *x = a;
    const Contagem *y = b;
    if (x->vezes != y->vezes) {
        return y->vezes - x->vezes;
    }
    return strcmp(x->palavra, y->palavra);
}

int main(void) {
    Contador *c = contador_cria(101);
    if (c == NULL) {
        return 1;
    }
    char linha[256]; // linha maior que isso chega em pedaços
    char palavra[TAM_PALAVRA];
    while (fgets(linha, sizeof linha, stdin) != NULL) {
        const char *p = linha;
        while (proxima_palavra(&p, palavra, sizeof palavra)) {
            contador_soma(c, palavra);
        }
    }

    int n = contador_distintas(c);
    Contagem *lista = contador_lista(c);
    if (lista == NULL) {
        contador_libera(c);
        return 1;
    }
    qsort(lista, (size_t)n, sizeof lista[0], compara);
    int uma_vez = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i].vezes == 1) {
            uma_vez++;
        }
    }
    printf("%d palavras, %d diferentes, %d aparecem uma vez só\n", contador_total(c), n, uma_vez);
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%d. %s: %d\n", i + 1, lista[i].palavra, lista[i].vezes);
    }
    printf("\"casa\" aparece %d vezes\n", contador_vezes(c, "casa"));
    free(lista);
    contador_libera(c);
    return 0;
}
// Para testar com um arquivo: ~/LPEDC/rodar A226.c < texto.txt
// Exemplo:
// $ printf 'Quem casa quer casa.\nQuem não casa, quer casar!\n' | ~/LPEDC/rodar A226.c
// 9 palavras, 5 diferentes, 2 aparecem uma vez só
// 1. casa: 3
// 2. quem: 2
// 3. quer: 2
// "casa" aparece 3 vezes
