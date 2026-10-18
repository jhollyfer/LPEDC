// padroes.c · implementação dos quatro algoritmos de padroes.h
#include <stddef.h> // NULL
#include "padroes.h"

#define ALFABETO 256
#define RK_BASE 256
#define RK_Q 1000003LL

// guarda a ocorrência em pos[] se ainda couber
static void anota(int pos[], int max, int achados, int i) {
    if (pos != NULL && achados < max) {
        pos[achados] = i;
    }
}

static int invalido(int n, int m) {
    return m <= 0 || m > n;
}

int pb_forca_bruta(const char *texto, int n, const char *padrao, int m,
                   int pos[], int max, long *comparacoes) {
    if (invalido(n, m)) {
        return 0;
    }
    int achados = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            (*comparacoes)++;
            if (texto[i + j] != padrao[j]) {
                break;
            }
            j++;
        }
        if (j == m) {
            anota(pos, max, achados, i);
            achados++;
        }
    }
    return achados;
}

int pb_kmp(const char *texto, int n, const char *padrao, int m,
           int pos[], int max, long *comparacoes) {
    if (invalido(n, m) || m > PB_MAX_PADRAO) {
        return 0;
    }
    int pi[PB_MAX_PADRAO];
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {         // a tabela não entra na contagem
        while (k > 0 && padrao[j] != padrao[k]) {
            k = pi[k - 1];
        }
        if (padrao[j] == padrao[k]) {
            k++;
        }
        pi[j] = k;
    }
    int achados = 0;
    k = 0;
    for (int i = 0; i < n; i++) {
        while (1) {
            (*comparacoes)++;
            if (texto[i] == padrao[k]) {
                k++;
                break;
            }
            if (k == 0) {
                break;
            }
            k = pi[k - 1];
        }
        if (k == m) {
            anota(pos, max, achados, i - m + 1);
            achados++;
            k = pi[k - 1];
        }
    }
    return achados;
}

int pb_horspool(const char *texto, int n, const char *padrao, int m,
                int pos[], int max, long *comparacoes) {
    if (invalido(n, m)) {
        return 0;
    }
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) padrao[j]] = m - 1 - j;
    }
    int achados = 0;
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            (*comparacoes)++;
            if (texto[i + j] != padrao[j]) {
                break;
            }
            j--;
        }
        if (j < 0) {
            anota(pos, max, achados, i);
            achados++;
        }
        i += salto[(unsigned char) texto[i + m - 1]];
    }
    return achados;
}

int pb_rabin_karp(const char *texto, int n, const char *padrao, int m,
                  int pos[], int max, long *comparacoes) {
    if (invalido(n, m)) {
        return 0;
    }
    long long pot = 1, hp = 0, ht = 0;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * RK_BASE % RK_Q;
    }
    for (int j = 0; j < m; j++) {
        hp = (hp * RK_BASE + (unsigned char) padrao[j]) % RK_Q;
        ht = (ht * RK_BASE + (unsigned char) texto[j]) % RK_Q;
    }
    int achados = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            int j = 0;
            while (j < m) {
                (*comparacoes)++;
                if (texto[i + j] != padrao[j]) {
                    break;
                }
                j++;
            }
            if (j == m) {
                anota(pos, max, achados, i);
                achados++;
            }
        }
        if (i < n - m) {
            ht = (ht - (unsigned char) texto[i] * pot % RK_Q + RK_Q) % RK_Q;
            ht = (ht * RK_BASE + (unsigned char) texto[i + m]) % RK_Q;
        }
    }
    return achados;
}
