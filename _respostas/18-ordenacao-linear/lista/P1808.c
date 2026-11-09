// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1808 · ★☆☆ · Radix sort bit a bit: zeros na frente, uns atrás

#include <stdio.h>

#define N 8

void passada(int v[], int n, int b) { // separação estável pelo bit b
    int saida[N], zeros = 0;
    for (int i = 0; i < n; i++)
        if (((v[i] >> b) & 1) == 0) zeros++;
    int iz = 0, iu = zeros;
    for (int i = 0; i < n; i++) {
        if ((v[i] >> b) & 1) saida[iu++] = v[i];
        else saida[iz++] = v[i];
    }
    for (int i = 0; i < n; i++) v[i] = saida[i];
}

void mostra(const char *rotulo, const int v[], int n) {
    printf("%-7s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" ");
        for (int b = 3; b >= 0; b--) printf("%d", (v[i] >> b) & 1);
    }
    printf(" |");
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    int linha[N] = {12, 5, 9, 14, 3, 10, 6, 11};

    mostra("início", linha, N);
    for (int b = 0; b < 4; b++) {
        passada(linha, N, b);
        char rotulo[8];
        snprintf(rotulo, sizeof rotulo, "bit %d", b);
        mostra(rotulo, linha, N);
    }
    return 0;
}
