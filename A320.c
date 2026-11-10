// A320 · Vários padrões numa passada só: o filtro de spoiler

#include <stdio.h>
#include <string.h>

#define BASE 256
#define Q 1000003LL
#define NPAD 3

long long hash(const char *s, int m) {
    long long h = 0;
    for (int j = 0; j < m; j++) {
        h = (h * BASE + (unsigned char) s[j]) % Q;
    }
    return h;
}

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    // todos os padrões têm o MESMO tamanho: a janela rolante é uma só
    const char *proibidas[NPAD] = {"final", "morre", "vilao"};
    char msg[] = "sem spoiler: no final o vilao morre? nao conto, mas o final e bom";
    int n = (int) strlen(msg);
    int m = 5;

    long long hp[NPAD];
    for (int k = 0; k < NPAD; k++) {
        hp[k] = hash(proibidas[k], m);   // um hash por padrão, antes da busca
    }
    long long pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % Q;
    }

    long long ht = hash(msg, m);
    int marcar[sizeof msg] = {0};        // onde começa cada palavra proibida
    for (int i = 0; i <= n - m; i++) {
        for (int k = 0; k < NPAD; k++) {
            if (ht == hp[k] && iguais(msg + i, proibidas[k], m)) {
                printf("\"%s\" na posição %d\n", proibidas[k], i);
                marcar[i] = 1;
            }
        }
        if (i < n - m) {
            ht = (ht - (unsigned char) msg[i] * pot % Q + Q) % Q;
            ht = (ht * BASE + (unsigned char) msg[i + m]) % Q;
        }
    }
    // só depois da busca troca as letras: trocar antes mudaria as janelas
    for (int i = 0; i < n; i++) {
        if (marcar[i]) {
            for (int j = 0; j < m; j++) {
                msg[i + j] = '*';
            }
        }
    }
    printf("%s\n", msg);
    return 0;
}
// Saída:
// "final" na posição 16
// "vilao" na posição 24
// "morre" na posição 30
// "final" na posição 54
// sem spoiler: no ***** o ***** *****? nao conto, mas o ***** e bom
