// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2018 · ★★☆ · Quem tem maioria absoluta?

#include <stdio.h>

int conta(const int v[], int ini, int fim, int x) {
    int c = 0;
    for (int i = ini; i <= fim; i++) {
        if (v[i] == x) {
            c++;
        }
    }
    return c;
}

int maioria(const int v[], int ini, int fim) {
    if (ini == fim) {
        return v[ini];
    }
    int meio = ini + (fim - ini) / 2;
    int e = maioria(v, ini, meio);
    int d = maioria(v, meio + 1, fim);
    int metade = (fim - ini + 1) / 2;
    if (e != -1 && conta(v, ini, fim, e) > metade) {
        return e;
    }
    if (d != -1 && conta(v, ini, fim, d) > metade) {
        return d;
    }
    return -1;
}

void apura(const char *urna, const int v[], int n) {
    int m = maioria(v, 0, n - 1);
    if (m == -1) {
        printf("%s: ninguém tem maioria\n", urna);
    } else {
        printf("%s: candidato %d, com %d de %d votos\n", urna, m, conta(v, 0, n - 1, m), n);
    }
}

int main(void) {
    const int u1[15] = {4, 7, 4, 4, 2, 4, 7, 4, 9, 4, 4, 2, 4, 7, 4};
    const int u2[8] = {1, 2, 3, 1, 2, 3, 1, 2};
    apura("Urna 1", u1, 15);
    apura("Urna 2", u2, 8);
    return 0;
}
