// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2219 · ★★☆ · A agenda de ramais consistente

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Trie {
    struct Trie *f[10];
    bool fim;
} Trie;

Trie *novo(void) {
    Trie *n = calloc(1, sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    return n;
}

int insere(Trie *r, const char *s) {
    for (; *s != '\0'; s++) {
        if (r->fim) {
            return 0;
        }
        int d = *s - '0';
        if (r->f[d] == NULL) {
            r->f[d] = novo();
        }
        r = r->f[d];
    }
    for (int d = 0; d < 10; d++) {
        if (r->f[d] != NULL) {
            return 0;
        }
    }
    if (r->fim) {
        return 0;
    }
    r->fim = true;
    return 1;
}

void libera(Trie *n) {
    if (n != NULL) {
        for (int d = 0; d < 10; d++) {
            libera(n->f[d]);
        }
        free(n);
    }
}

void testa(const char *nome, const char *ramal[], int n) {
    Trie *r = novo();
    int ok = 1;
    for (int i = 0; i < n && ok; i++) {
        if (!insere(r, ramal[i])) {
            printf("%s: inconsistente (conflito ao inserir %s)\n", nome, ramal[i]);
            ok = 0;
        }
    }
    if (ok) {
        printf("%s: consistente\n", nome);
    }
    libera(r);
}

int main(void) {
    const char *l1[5] = {"4012", "4078", "5231", "40", "7766"};
    const char *l2[5] = {"3021", "3304", "4471", "6650", "4479"};
    testa("Lista 1", l1, 5);
    testa("Lista 2", l2, 5);
    return 0;
}
