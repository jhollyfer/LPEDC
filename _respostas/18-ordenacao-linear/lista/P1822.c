// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1822 · ★★★ · Radix MSD: os municípios em ordem alfabética

#include <stdio.h>
#include <string.h>

#define N 15
#define G 257 // grupo 0 = fim da string, 1..256 = caractere + 1

const char *aux[N];
long chamadas;

int grupo(const char *s, int d) { return s[d] ? (unsigned char)s[d] + 1 : 0; }

void msd(const char *v[], int ini, int fim, int d, int mostra) {
    chamadas++;
    int c[G + 1] = {0};
    for (int i = ini; i <= fim; i++) c[grupo(v[i], d) + 1]++; // c[g + 1] conta o grupo g
    for (int g = 1; g <= G; g++) c[g] += c[g - 1];            // c[g] = início do grupo g
    if (mostra) {
        printf("Primeiro nível:");
        for (int g = 1; g < G; g++)
            if (c[g + 1] > c[g]) printf(" %c(%d)", g - 1, c[g + 1] - c[g]);
        printf("\n");
    }
    int pos[G + 1];
    for (int g = 0; g <= G; g++) pos[g] = c[g];
    for (int i = ini; i <= fim; i++) aux[pos[grupo(v[i], d)]++] = v[i]; // estável, da frente
    for (int i = ini; i <= fim; i++) v[i] = aux[i - ini];
    for (int g = 1; g < G; g++) // o grupo 0 (strings que acabaram) já está pronto
        if (c[g + 1] - c[g] > 1) msd(v, ini + c[g], ini + c[g + 1] - 1, d + 1, 0);
}

int main(void) {
    const char *mun[N] = {"manaus", "parintins", "itacoatiara", "manacapuru", "coari",
                          "tefe", "tabatinga", "maues", "humaita", "iranduba",
                          "manicore", "barcelos", "borba", "codajas", "careiro"};

    msd(mun, 0, N - 1, 0, 1);
    int ok = 1;
    for (int i = 0; i < N; i++) {
        printf("%s%s", i % 5 ? " " : (i ? "\n" : ""), mun[i]); // 5 por linha
        if (i > 0 && strcmp(mun[i - 1], mun[i]) > 0) ok = 0;
    }
    printf("\nChamadas: %ld | em ordem pelo strcmp: %s\n", chamadas, ok ? "sim" : "não");
    return 0;
}
