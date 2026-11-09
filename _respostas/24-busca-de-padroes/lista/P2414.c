// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2414 · ★★☆ · O mesmo colar visto de outro ponto

#include <stdio.h>
#include <string.h>

// devolve o início da menor rotação (em ordem alfabética) de s
int menor_rotacao(const char *s) {
    int n = (int)strlen(s), melhor = 0;
    for (int k = 1; k < n; k++) {
        // compara a rotação k com a melhor, letra a letra, dando a volta
        int j = 0;
        while (j < n && s[(k + j) % n] == s[(melhor + j) % n]) j++;
        if (j < n && s[(k + j) % n] < s[(melhor + j) % n]) melhor = k;
    }
    return melhor;
}

void canonica(const char *s, char saida[]) {
    int n = (int)strlen(s), k = menor_rotacao(s);
    for (int j = 0; j < n; j++) saida[j] = s[(k + j) % n];
    saida[n] = '\0';
}

int main(void) {
    const char *colares[] = {"VAAVB", "AVBVA", "BAVAV", "VBVAA", "AVAVB", "ABAVV"};
    char forma[6][16];
    for (int i = 0; i < 6; i++) {
        canonica(colares[i], forma[i]);
        printf("%s -> %s\n", colares[i], forma[i]);
    }
    int grupo[6] = {0}, g = 0;
    for (int i = 0; i < 6; i++) {
        if (grupo[i]) continue;
        grupo[i] = ++g;
        printf("Colar %d:", g);
        for (int j = i; j < 6; j++)
            if (strcmp(forma[j], forma[i]) == 0) {
                grupo[j] = g;
                printf(" %s", colares[j]);
            }
        printf("\n");
    }
    return 0;
}
