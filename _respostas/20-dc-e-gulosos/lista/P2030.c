// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2030 · ★★★ · O guloso que pinta demais

#include <stdio.h>

#define N 8

const char *nome[N] = {"A0", "A1", "A2", "A3", "B0", "B1", "B2", "B3"};
int cor[N];

int viz(int u, int v) {
    return (u < 4) != (v < 4) && u % 4 != v % 4;
}

int guloso(const int ordem[]) {
    for (int i = 0; i < N; i++) {
        cor[i] = -1;
    }
    int usadas = 0;
    for (int k = 0; k < N; k++) {
        int v = ordem[k], c = 0;
        for (;;) {
            int livre = 1;
            for (int u = 0; u < N; u++) {
                if (cor[u] == c && viz(u, v)) {
                    livre = 0;
                }
            }
            if (livre) {
                break;
            }
            c++;
        }
        cor[v] = c;
        if (c + 1 > usadas) {
            usadas = c + 1;
        }
    }
    return usadas;
}

int colore(int v, int k) {
    if (v == N) {
        return 1;
    }
    for (int c = 0; c < k; c++) {
        int ok = 1;
        for (int u = 0; u < v; u++) {
            if (viz(u, v) && cor[u] == c) {
                ok = 0;
            }
        }
        if (ok) {
            cor[v] = c;
            if (colore(v + 1, k)) {
                return 1;
            }
        }
    }
    return 0;
}

void mostra(const char *titulo, int total) {
    printf("%s:", titulo);
    for (int i = 0; i < N; i++) {
        printf(" %s=%d", nome[i], cor[i]);
    }
    printf(" (%d frequências)\n", total);
}

int main(void) {
    const int intercalada[N] = {0, 4, 1, 5, 2, 6, 3, 7};
    const int por_morro[N] = {0, 1, 2, 3, 4, 5, 6, 7};
    mostra("Guloso intercalado", guloso(intercalada));
    mostra("Guloso por morro", guloso(por_morro));
    int k = 1;
    while (!colore(0, k)) {
        k++;
    }
    mostra("Ótimo", k);
    return 0;
}
