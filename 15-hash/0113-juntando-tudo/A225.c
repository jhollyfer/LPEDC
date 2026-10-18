// A225 · O que os clientes mais falam da padaria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palavras.h"

// letra = letra ASCII ou qualquer byte de um caractere UTF-8 (>= 128)
int eh_letra(char c) {
    unsigned char u = (unsigned char)c;
    return isalpha(u) || u >= 128;
}

// copia a próxima palavra de *p para buf, em minúsculas, e avança *p.
// devolve 0 quando o texto acaba
int proxima_palavra(const char **p, char *buf, size_t tam) {
    while (**p != '\0' && !eh_letra(**p)) {
        (*p)++; // pula espaço, pontuação, número
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

// mais vezes primeiro; no empate, ordem alfabética
int compara(const void *a, const void *b) {
    const Contagem *x = a;
    const Contagem *y = b;
    if (x->vezes != y->vezes) {
        return y->vezes - x->vezes;
    }
    return strcmp(x->palavra, y->palavra);
}

int main(void) {
    const char *texto =
        "O pão de queijo estava quente e o café estava frio. "
        "Pão bom, café ruim: o pão de queijo salva a padaria. "
        "O café da tarde? Pão, pão e mais pão!";

    Contador *c = contador_cria(17);
    if (c == NULL) {
        return 1;
    }
    char palavra[TAM_PALAVRA];
    const char *p = texto;
    while (proxima_palavra(&p, palavra, sizeof palavra)) {
        contador_soma(c, palavra);
    }

    int n = contador_distintas(c);
    printf("%d palavras, %d diferentes\n", contador_total(c), n);
    Contagem *lista = contador_lista(c);
    if (lista != NULL) {
        qsort(lista, (size_t)n, sizeof lista[0], compara);
        for (int i = 0; i < 5 && i < n; i++) {
            printf("%d. %s: %d\n", i + 1, lista[i].palavra, lista[i].vezes);
        }
        free(lista);
    }
    contador_libera(c);
    return 0;
}
// Saída:
// 31 palavras, 17 diferentes
// 1. pão: 6
// 2. o: 4
// 3. café: 3
// 4. de: 2
// 5. e: 2
