// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2214 · ★★☆ · O menor apelido de cada palavra

#include <stdio.h>
#include <stdlib.h>

typedef struct Trie {
    struct Trie *f[26];
    int passam;
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
        r->passam++;
    }
}

void apelido(const Trie *r, const char *p, char buf[]) {
    int k = 0;
    for (; *p != '\0'; p++) {
        r = r->f[*p - 'a'];
        buf[k++] = *p;
        if (r->passam == 1) {
            break;
        }
    }
    buf[k] = '\0';
}

void libera(Trie *n) {
    if (n != NULL) {
        for (int i = 0; i < 26; i++) {
            libera(n->f[i]);
        }
        free(n);
    }
}

int main(void) {
    const char *salas[6] = {"acervo", "acesso", "arquivo", "auditorio", "biblioteca", "brinquedoteca"};
    Trie *r = novo();
    for (int i = 0; i < 6; i++) {
        insere(r, salas[i]);
    }
    char buf[32];
    for (int i = 0; i < 6; i++) {
        apelido(r, salas[i], buf);
        printf("%s: %s\n", salas[i], buf);
    }
    libera(r);
    return 0;
}
