// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1023 · ★★★ · Quem tem a maioria no grêmio?

#include <stdio.h>

int maioria_ingenua(const int v[], int n, long *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        int cont = 0;
        for (int j = 0; j < n; j++) {
            (*comp)++;
            if (v[j] == v[i]) {
                cont++;
            }
        }
        if (cont > n / 2) {
            return v[i];
        }
    }
    return -1;
}

int maioria_boyer_moore(const int v[], int n, long *comp) {
    int candidato = -1, cont = 0;
    *comp = 0;
    for (int i = 0; i < n; i++) { // fase 1: cancela pares diferentes
        (*comp)++;
        if (cont == 0) {
            candidato = v[i];
            cont = 1;
        } else if (v[i] == candidato) {
            cont++;
        } else {
            cont--;
        }
    }
    int votos = 0;
    for (int i = 0; i < n; i++) { // fase 2: confirma
        (*comp)++;
        if (v[i] == candidato) {
            votos++;
        }
    }
    return votos > n / 2 ? candidato : -1;
}

void apura(const char *nome, const int v[], int n) {
    long ci, cb;
    int a = maioria_ingenua(v, n, &ci);
    int b = maioria_boyer_moore(v, n, &cb);
    if (a != b) {
        printf("%s: as duas discordam!\n", nome);
    }
    if (b >= 0) {
        int votos = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == b) {
                votos++;
            }
        }
        printf("%s: candidato %d com %d de %d votos\n", nome, b, votos, n);
    } else {
        printf("%s: ninguém tem maioria\n", nome);
    }
    printf("  ingênuo: %ld comparações, Boyer-Moore: %ld\n", ci, cb);
}

int main(void) {
    int e1[11] = {1, 3, 2, 2, 1, 2, 2, 3, 2, 2, 2};
    int e2[7] = {1, 2, 3, 1, 2, 3, 1};
    apura("Eleição 1", e1, 11);
    apura("Eleição 2", e2, 7);
    return 0;
}
