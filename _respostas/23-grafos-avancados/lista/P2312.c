// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2312 · ★★☆ · O alfabeto do idioma inventado

#include <stdio.h>
#include <string.h>

#define L 26

void descobre(const char *rotulo, const char *palavras[], int n) {
    int antes[L][L] = {{0}}, aparece[L] = {0}, grau[L] = {0};
    for (int i = 0; i < n; i++)
        for (int k = 0; palavras[i][k]; k++) aparece[palavras[i][k] - 'a'] = 1;

    printf("%s\n", rotulo);
    for (int i = 0; i + 1 < n; i++) {
        const char *x = palavras[i], *y = palavras[i + 1];
        int k = 0;
        while (x[k] && x[k] == y[k]) k++;
        if (x[k] && y[k]) { // a primeira letra diferente decide
            int a = x[k] - 'a', b = y[k] - 'a';
            printf("  %s < %s: %c antes de %c\n", x, y, x[k], y[k]);
            if (!antes[a][b]) {
                antes[a][b] = 1;
                grau[b]++;
            }
        }
    }

    int fila[L], ini = 0, fim = 0, letras = 0;
    for (int c = 0; c < L; c++) {
        letras += aparece[c];
        if (aparece[c] && grau[c] == 0) fila[fim++] = c;
    }
    char alfabeto[L + 1];
    int m = 0;
    while (ini < fim) {
        int u = fila[ini++];
        alfabeto[m++] = (char)('a' + u);
        for (int v = 0; v < L; v++)
            if (antes[u][v] && --grau[v] == 0) fila[fim++] = v;
    }
    alfabeto[m] = '\0';
    if (m < letras) printf("  lista inconsistente: as regras formam um ciclo\n");
    else printf("  alfabeto: %s\n", alfabeto);
}

int main(void) {
    const char *jogo1[] = {"cab", "cad", "ae", "aed", "eb", "bd"};
    descobre("Lista 1", jogo1, 6);
    const char *jogo2[] = {"ba", "bc", "ca", "ab"};
    descobre("Lista 2", jogo2, 4);
    return 0;
}
