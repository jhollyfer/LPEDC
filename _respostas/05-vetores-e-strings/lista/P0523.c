// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0523 · ★★★ · Lendo a planilha em CSV

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int separar(const char linha[], char campos[3][32]) {
    int c = 0; // campo atual
    int j = 0; // posição dentro do campo
    for (int i = 0; linha[i] != '\0' && c < 3; i++) {
        if (linha[i] == ';') {
            campos[c][j] = '\0';
            c++;
            j = 0;
        } else if (j < 31) {
            campos[c][j++] = linha[i];
        }
    }
    if (c < 3) {
        campos[c][j] = '\0';
        c++;
    }
    return c;
}

int para_int(const char s[]) {
    int v = 0;
    for (int i = 0; isdigit((unsigned char) s[i]); i++) {
        v = v * 10 + (s[i] - '0');
    }
    return v;
}

int main(void) {
    char linhas[4][48] = {"Manaus;AM;2063547", "Parintins;;96372",
                          "Itacoatiara;AM;103598", "Manacapuru;AM;101883"};
    char cidades[4][32];
    int pop[4];
    int total = 0;
    int i_maior = 0;

    for (int k = 0; k < 4; k++) {
        char campos[3][32];
        if (separar(linhas[k], campos) != 3) {
            printf("Linha %d com defeito\n", k + 1);
            continue;
        }
        strcpy(cidades[k], campos[0]);
        pop[k] = para_int(campos[2]);
        printf("%-12s %-3s %8d\n", campos[0], campos[1][0] == '\0' ? "??" : campos[1], pop[k]);
        total += pop[k];
        if (pop[k] > pop[i_maior]) {
            i_maior = k;
        }
    }
    printf("Total: %d habitantes\n", total);
    printf("Mais populosa: %s\n", cidades[i_maior]);
    return 0;
}
