// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2903 · ★☆☆ · Passeio, trajeto ou caminho

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int trilha[6][6];
const char *abertos[4] = {"não é passeio", "passeio", "trajeto", "caminho"};
const char *fechados[4] = {"não é passeio", "passeio fechado", "circuito", "ciclo"};

int classifica(const char *s) {
    int n = (int)strlen(s);
    for (int i = 0; i + 1 < n; i++)
        if (!trilha[s[i] - 'A'][s[i + 1] - 'A']) return 0;
    for (int i = 0; i + 1 < n; i++)
        for (int j = i + 1; j + 1 < n; j++)
            if ((s[i] == s[j] && s[i + 1] == s[j + 1]) || (s[i] == s[j + 1] && s[i + 1] == s[j])) return 1;
    int fim = (n > 1 && s[0] == s[n - 1]) ? n - 1 : n;
    for (int i = 0; i < fim; i++)
        for (int j = i + 1; j < fim; j++)
            if (s[i] == s[j]) return 2;
    return 3;
}

int main(void) {
    const char *t[7] = {"AB", "BC", "CD", "DA", "BD", "DE", "EF"};
    for (int k = 0; k < 7; k++) {
        int a = t[k][0] - 'A', b = t[k][1] - 'A';
        trilha[a][b] = trilha[b][a] = 1;
    }
    const char *testes[5] = {"ABCD", "ABCDB", "ABCDBA", "ABCDA", "DEFD"};
    for (int i = 0; i < 5; i++) {
        int n = (int)strlen(testes[i]);
        bool fechada = testes[i][0] == testes[i][n - 1];
        int c = classifica(testes[i]);
        printf("%-7s %s, comprimento %d\n", testes[i], fechada ? fechados[c] : abertos[c], n - 1);
    }
    return 0;
}
