// 0077 · Notação O: como o custo cresce
// Exercício E462 · ★★★
//
// Resposta: a) O(n²): n dobra, os passos multiplicam por 4; b) tamanho(texto)
// fica na condição do for, avaliada n + 1 vezes, e cada chamada custa n
// passos; c) medir uma vez só antes do laço. Passos: 1000, 2000 e 4000.

#include <stdio.h>

long passos = 0;

int tamanho(const char *s) {
    int t = 0;
    while (s[t] != '\0') {
        passos++;
        t++;
    }
    return t;
}

int conta_vogais(const char *texto) {
    int vogais = 0;
    int n = tamanho(texto); // mede uma vez só
    for (int i = 0; i < n; i++) {
        char c = texto[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogais++;
        }
    }
    return vogais;
}

int main(void) {
    static char texto[4001];
    int tamanhos[3] = {1000, 2000, 4000};

    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            texto[i] = "abcde"[i % 5];
        }
        texto[n] = '\0';
        passos = 0;
        int v = conta_vogais(texto);
        printf("n = %d: %d vogais, %ld passos\n", n, v, passos);
    }
    return 0;
}
