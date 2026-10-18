// 0161 · Juntando tudo
// Exercício E963 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "padroes.h"

#define MAXPOS 16

// letra, dígito ou '_' fazem parte de uma palavra
int de_palavra(char c) {
    return isalnum((unsigned char) c) || c == '_';
}

// quantas ocorrências de padrao são palavras inteiras na linha
int conta_palavra(const char *linha, const char *padrao) {
    int n = (int) strlen(linha);
    int m = (int) strlen(padrao);
    int pos[MAXPOS];
    long comp = 0;
    int k = pb_kmp(linha, n, padrao, m, pos, MAXPOS, &comp);
    int inteiras = 0;
    for (int i = 0; i < k && i < MAXPOS; i++) {
        int ini = pos[i];
        int fim = pos[i] + m;            // primeira letra depois da ocorrência
        int livre_antes = ini == 0 || !de_palavra(linha[ini - 1]);
        int livre_depois = fim == n || !de_palavra(linha[fim]);
        if (livre_antes && livre_depois) {
            inteiras++;
        }
    }
    return inteiras;
}

int main(void) {
    const char *linhas[] = {
        "churrasco: sal grosso na picanha",
        "salada de alface e tomate",
        "pouco sal, por favor",
        "cachorro-quente com salsicha",
        "faltou sal!",
        "o sal_marinho acabou",
    };
    for (int l = 0; l < 6; l++) {
        if (conta_palavra(linhas[l], "sal") > 0) {
            printf("%d: %s\n", l + 1, linhas[l]);
        }
    }
    return 0;
}
