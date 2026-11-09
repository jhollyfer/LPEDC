// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0524 · ★★★ · A nuvem de palavras do trava-língua

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int palavras_n = 0;

void contar(char palavras[MAX][16], int cont[MAX], const char p[]) {
    for (int k = 0; k < palavras_n; k++) {
        if (strcmp(palavras[k], p) == 0) {
            cont[k]++;
            return;
        }
    }
    if (palavras_n < MAX) {
        strcpy(palavras[palavras_n], p);
        cont[palavras_n] = 1;
        palavras_n++;
    }
}

int main(void) {
    char frase[] = "O rato roeu a roupa do Rei de Roma, e o rei riu do rato.";
    char palavras[MAX][16];
    int cont[MAX];
    char p[16];
    int j = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        unsigned char c = frase[i];
        if (isalpha(c)) {
            if (j < 15) {
                p[j++] = tolower(c);
            }
        } else if (j > 0) {
            p[j] = '\0';
            contar(palavras, cont, p);
            j = 0;
        }
    }
    if (j > 0) { // a última palavra, se a frase não terminou em pontuação
        p[j] = '\0';
        contar(palavras, cont, p);
    }

    int i_maior = 0;
    for (int k = 0; k < palavras_n; k++) {
        printf("%-6s %d\n", palavras[k], cont[k]);
        if (cont[k] > cont[i_maior]) {
            i_maior = k;
        }
    }
    printf("Distintas: %d\n", palavras_n);
    printf("Mais repetida: %s (%d vezes)\n", palavras[i_maior], cont[i_maior]);
    return 0;
}
