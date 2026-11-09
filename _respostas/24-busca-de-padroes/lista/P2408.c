// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2408 · ★☆☆ · O filtro do grupo da família

#include <stdio.h>
#include <string.h>

// troca cada letra de cada ocorrência por '*' e devolve quantas achou
int censura(char *texto, const char *palavra) {
    int n = (int)strlen(texto), m = (int)strlen(palavra), achou = 0;
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && texto[i + j] == palavra[j]) j++;
        if (j == m) {
            achou++;
            for (int k = 0; k < m; k++) texto[i + k] = '*';
        }
    }
    return achou;
}

int main(void) {
    char msg[] = "que droga, perdi o onibus de novo, droga de chuva, que saco";
    const char *proibidas[] = {"droga", "saco", "chato"};
    for (int k = 0; k < 3; k++) printf("%s: %d\n", proibidas[k], censura(msg, proibidas[k]));
    printf("%s\n", msg);
    return 0;
}
