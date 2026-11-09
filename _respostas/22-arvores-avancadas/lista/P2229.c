// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2229 · ★★★ · As três sugestões mais usadas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie {
    struct Trie *f[26];
    int vezes;
} Trie;

typedef struct {
    char palavra[16];
    int vezes;
} Sugestao;

Sugestao lista[64];
int nl;

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
    r->vezes++;
}

void coleta(const Trie *n, char buf[], int prof) {
    if (n->vezes > 0) {
        buf[prof] = '\0';
        strcpy(lista[nl].palavra, buf);
        lista[nl++].vezes = n->vezes;
    }
    for (int i = 0; i < 26; i++) {
        if (n->f[i] != NULL) {
            buf[prof] = (char)('a' + i);
            coleta(n->f[i], buf, prof + 1);
        }
    }
}

int compara(const void *a, const void *b) {
    const Sugestao *x = a, *y = b;
    if (x->vezes != y->vezes) {
        return y->vezes - x->vezes;
    }
    return strcmp(x->palavra, y->palavra);
}

void sugere(const Trie *r, const char *pre) {
    char buf[16];
    int k = 0;
    for (; pre[k] != '\0'; k++) {
        r = r->f[pre[k] - 'a'];
        if (r == NULL) {
            printf("\"%s\": nenhuma sugestão\n", pre);
            return;
        }
        buf[k] = pre[k];
    }
    nl = 0;
    coleta(r, buf, k);
    qsort(lista, (size_t)nl, sizeof lista[0], compara);
    printf("\"%s\":", pre);
    for (int i = 0; i < nl && i < 3; i++) {
        printf(" %s (%d)", lista[i].palavra, lista[i].vezes);
    }
    printf("\n");
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
    const char *texto = "bom dia boa tarde bom jogo bola bonita bom dia boa noite "
                        "bolo de bolo bom bolo tarde tapioca taxi tapioca tarde bom";
    Trie *r = novo();
    char palavra[16];
    int k = 0;
    for (int i = 0;; i++) {
        if (texto[i] == ' ' || texto[i] == '\0') {
            if (k > 0) {
                palavra[k] = '\0';
                insere(r, palavra);
                k = 0;
            }
            if (texto[i] == '\0') {
                break;
            }
        } else {
            palavra[k++] = texto[i];
        }
    }
    const char *pre[4] = {"bo", "ta", "bol", "x"};
    for (int i = 0; i < 4; i++) {
        sugere(r, pre[i]);
    }
    libera(r);
    return 0;
}
