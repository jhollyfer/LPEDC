// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2206 · ★☆☆ · O começo que todas têm

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Trie {
    struct Trie *f[26];
    bool fim;
} Trie;

Trie *novo(void) {
    Trie *n = calloc(1, sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    return n;
}

void insere(Trie *r, const char *p) {
    for (; *p != '\0'; p++) {
        int i = *p - 'a';
        if (r->f[i] == NULL) {
            r->f[i] = novo();
        }
        r = r->f[i];
    }
    r->fim = true;
}

int conta_filhos(const Trie *n, int *qual) {
    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (n->f[i] != NULL) {
            c++;
            *qual = i;
        }
    }
    return c;
}

void prefixo_comum(const Trie *r, char buf[]) {
    int k = 0, qual = 0;
    while (!r->fim && conta_filhos(r, &qual) == 1) {
        buf[k++] = (char)('a' + qual);
        r = r->f[qual];
    }
    buf[k] = '\0';
}

void libera(Trie *n) {
    if (n == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        libera(n->f[i]);
    }
    free(n);
}

void testa(const char *lista[], int n) {
    Trie *r = novo();
    for (int i = 0; i < n; i++) {
        insere(r, lista[i]);
        printf("%s%s", i ? ", " : "", lista[i]);
    }
    char buf[32];
    prefixo_comum(r, buf);
    printf(": prefixo comum \"%s\"\n", buf);
    libera(r);
}

int main(void) {
    const char *l1[5] = {"comer", "comida", "comilao", "comedor", "comestivel"};
    const char *l2[4] = {"solar", "sol", "solteiro", "soldado"};
    testa(l1, 5);
    testa(l2, 4);
    return 0;
}
