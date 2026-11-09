// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1924 · ★★★ · SEIS + SEIS = DOZE

#include <stdbool.h>
#include <stdio.h>

#define L 6

const char letras[L + 1] = "SEIDOZ";
int val[L];
bool usado[10];
int solucoes = 0;
long conferidas = 0;

int valor(const char *p) {
    int v = 0;
    for (int i = 0; p[i] != '\0'; i++) {
        int k = 0;
        while (letras[k] != p[i]) {
            k++;
        }
        v = v * 10 + val[k];
    }
    return v;
}

void atribui(int k) {
    if (k == L) {
        conferidas++;
        if (valor("SEIS") + valor("SEIS") == valor("DOZE")) {
            solucoes++;
            printf("%d + %d = %d\n", valor("SEIS"), valor("SEIS"), valor("DOZE"));
        }
        return;
    }
    for (int d = 0; d <= 9; d++) {
        if (usado[d]) {
            continue;
        }
        if (d == 0 && (letras[k] == 'S' || letras[k] == 'D')) {
            continue;
        }
        usado[d] = true;
        val[k] = d;
        atribui(k + 1);
        usado[d] = false;
    }
}

int main(void) {
    atribui(0);
    printf("Soluções: %d\n", solucoes);
    printf("Atribuições conferidas: %ld\n", conferidas);
    return 0;
}
