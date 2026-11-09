// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2224 · ★★★ · Caça-palavras com trie

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 4

typedef struct Trie {
    struct Trie *f[26];
    bool fim;
} Trie;

const char grade[L][L + 1] = {"CASA", "ORTE", "LAMO", "APES"};
bool usada[L][L];
char achadas[32][8];
int na = 0;
long visitas = 0;

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

void libera(Trie *n) {
    if (n != NULL) {
        for (int i = 0; i < 26; i++) {
            libera(n->f[i]);
        }
        free(n);
    }
}

void procura(int l, int c, Trie *no, char buf[], int prof) {
    if (l < 0 || l >= L || c < 0 || c >= L || usada[l][c]) {
        return;
    }
    Trie *prox = no->f[grade[l][c] - 'A'];
    if (prox == NULL) {
        return;
    }
    visitas++;
    buf[prof] = (char)(grade[l][c] - 'A' + 'a');
    buf[prof + 1] = '\0';
    if (prox->fim) {
        strcpy(achadas[na++], buf);
        prox->fim = false;
    }
    usada[l][c] = true;
    for (int dl = -1; dl <= 1; dl++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dl != 0 || dc != 0) {
                procura(l + dl, c + dc, prox, buf, prof + 1);
            }
        }
    }
    usada[l][c] = false;
}

int compara(const void *a, const void *b) {
    return strcmp(a, b);
}

int main(void) {
    const char *dic[15] = {"casa", "cara", "caro", "arte", "mar", "mesa", "pe", "ame",
                           "rato", "lago", "cola", "mel", "sapo", "tear", "ramo"};
    Trie *r = novo();
    for (int i = 0; i < 15; i++) {
        insere(r, dic[i]);
    }
    char buf[L * L + 1];
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < L; c++) {
            procura(l, c, r, buf, 0);
        }
    }
    qsort(achadas, (size_t)na, sizeof achadas[0], compara);
    printf("Achadas (%d):", na);
    for (int i = 0; i < na; i++) {
        printf(" %s", achadas[i]);
    }
    printf("\n");
    printf("Casas visitadas: %ld\n", visitas);
    libera(r);
    return 0;
}
